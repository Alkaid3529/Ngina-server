# Ngina-server 项目概述

本项目从无到有的搭建了一个质量较高的`多线程高并发服务器项目程序框架`，除了没有实现具体的业务处理逻辑之外，已经是一个较为完善的服务器框架。项目实现了根据规定的数据包格式，在服务器端和客户端进行数据传输，同时服务器端可以根据客户端不同的数据包内容执行不同的业务处理逻辑。

在本项目中，主要的开发技术涉及 `Linux` 下 `epoll 高并发技术`，`线程池技术`，`线程同步技术`和独特的`延迟回收连接技术`等，同时配备了`信号处理`、`守护进程`、`配置文件读取`等功能，为保证服务器稳定运行，还对许多细节进行了较为完善的处理，在一定程度上参考了 Nginx 的架构实现，其中许多细节也参考了 Nginx 的实现方式，是一个对笔者来说很有挑战性的一个项目。

本项目还包含一个基于 C++ 11 `高性能内存池`的可`动态内存分配`的链表队列，队列支持`多线程`下 30 Hz 到 50 Hz 的数据输入和 10 Hz 的数据输出，项目内含自实现的 内存池 分配器，可以在一定程度上`提升内存分配性能`，减少内存碎片的产生和内存分配失败引起的程序崩溃。

# 项目背景
项目最初，Leader 的要求是设计一个可以`同时缓存多种数据类型的容器`，容器需要保证`先入先出`的存取规则，因此笔者理所当然的选择了对 STL 中的 deque 队列进行封装，并自行设计了数据结构满足多种数据的存取，插入数据可以通过重载实现，这也是第一版。

但是在测试过程中，由于`数据输入频率很高`，但是`取出速率较慢`，因此`数据很容易在队列中积压`，栈区`内存开销`会很大，而栈区内存只有在进程结束后才被回收，因此会导致整个`进程内存占用较大`，为了解决这个问题，笔者选择将类中成员类型修改为`指针`类型，这也就是第二版。

修改为指针后，当数据进入队列时分配堆区内存，当数据被取走后便可以即刻释放内存，从而一定程度上减少内存开销。虽然解决了内存开销问题，但是随着数据输入频率越来越高，渐渐产生了新的问题，即每次存入数据都需要在堆区申请内存，取出数据需要释放内存，`频繁的内存申请与释放存在一定的安全隐患`，而且最关键的是，程序效率也会有所下降，笔者查阅后发现，是因为每次 new delete 都需要和操作系统进行对接，这里存在一定的开销，会影响程序效率，而且可能会出现内存不足的情况，为了解决这个问题，笔者查阅一些资料后决定选择`内存池化技术`进行解决。

最终完成了一个高效进行数据缓存转发的多线程高并发服务器架构。

# 项目框架
项目根目录下包含了七个文件夹和四个文件，各文件夹和文件大致功能如下：

`_include`，文件夹中存储了本项目全部的头文件，包括全部的函数声明、宏定义、全局变量声明等。

`app`，文件夹中存放核心的文件，如程序入口函数、设置进程标题和配置文件读取等。

`logic`，文件夹存放通信逻辑类的函数实现，比较重要。

`misc`，文件夹存放不便于归类的一些文件，如线程池函数实现、内存分配和校验码等。

`net`，文件夹中存放真正的核心文件，实现了许多重要的函数功能，如基础通信类、建立连接、连接请求、连接超时等核心文件，十分重要。

`proc`，文件夹中存放进程相关的函数实现，如 master 进程、守护进程等函数实现。

`signal`，文件夹中存放信号处理相关的函数实现，如注册信号处理函数等。

`common.mk`，核心编译文件，用于编译。

`config.mk`，编译配置文件，控制编译路径等。

`makefile`，编译文件。

`nginx.conf`，项目配置信息，存储许多重要的功能选项。

## 内存池设计
指针，是 C/C++ 独特的一点，在程序设计中，不可避免的需要操作内存，但是直接操作内存的便捷性也会给程序设计带来许多隐患，可能会遇到内存不足、分配失败等特殊情况，而且每次内存分配都需要向操作系统申请，都存在时空开销，效率并不高。
为了更好地管理和优化程序内存，可以通过内存池化技术，在一定程度上降低操作内存的成本，提升程序效率，因此，在本项目中将实现一个性能不错的内存池用于解决笔者在工作过程中遇到的一些项目需求。

## 链表栈
为了验证内存池设计的性能，还需要设计一个可以进行动态内存分配的数据结构作为载体，分别使用默认分配器和内存池作为内存分配工具，进行相同的数据输入输出，观察两者的分配效率。常用的测试工具为链表栈结构，因此，笔者将首先实现一个链表栈，作为测试分配其性能的工具。

## 数据缓存池
数据池可以`存储多种格式数据`，并保证数据的`先入先出`存取，通过内存池提升数据存取效率。
出于一些原因，在这里笔者并未给出通过内存池实现的数据缓存队列，相信感兴趣的读者可以通过给出的内存池实现和队列设计可以自行实现。



# Ngina-server Project overview
This project built a high quality `multi-thread` and `high concurrency server program framework` from scratch, and realized the data transmission between the server and the client according to the specified data packet format. At the same time, the server could execute different business processing logic and other functions according to the different data packet contents of the client.

# Project technology
In this project, the main development technology involves `epoll high concurrency technology` under Linux, `thread pool` technology, `thread synchronization` technology and unique `delay recovery connection` technology, etc. At the same time, it is equipped with signal processing, daemon process, configuration file reading and other functions. In order to ensure the stable operation of the server, many details are also completed. It is a very challenging project for the author, which refers to the architecture implementation of Nginx to some extent, and many of the details also refer to the implementation of Nginx.

# Project deployment
The root directory of the project contains seven folders and four files.The functions of each folder and file are [shown](https://www.processon.com/embed/63c9de808363e12bdd5be0d9) below:

![Ngina 服务器框架](https://user-images.githubusercontent.com/98629981/215273229-a569921d-f4b4-4a29-a3d9-d447a39fe398.jpg)


`_include`, which stores all header files of this project, including all function declarations, macro definitions, global variable declarations, etc.

`app`, folder to store the core files, such as program entry function, set the process title and configuration file reading.

`logic`, folder store communication logic class function implementation, more important.

`misc`, folder for files that are not easy to sort, such as thread pool function implementation, memory allocation, and parity code.

`net`, folder store the real core file, to achieve many important functions, such as basic communication class, establish connection, connection request, connection timeout and other core files, is very important.

`proc`, a folder containing process-related function implementations, such as master, daemons, etc.

`signal`, the folder stores the function implementation related to signal processing, such as registering signal processing functions.

`common.mk`, the core compilation file, is used for compilation.

`config.mk`, to compile configuration files and control compilation paths.

`makefile`, compile file.

`nginx.conf`, project configuration information, stores many important functional options.

# Project process
The procedure execution flow is shown in the [figure](https://www.processon.com/embed/63d48e749b89530fb85c7d4f) below

![aa97bb891cd9b07404ed103087a63b8](https://user-images.githubusercontent.com/98629981/215250278-13b95a2e-d73d-4a18-84a7-bbe37969bed3.png)

