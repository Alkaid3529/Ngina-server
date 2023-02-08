# Ngina-server 项目概述

本项目从无到有的搭建了一个质量较高的`多线程高并发服务器项目程序框架`，除了没有实现具体的业务处理逻辑之外，已经是一个较为完善的服务器框架。项目实现了根据规定的数据包格式，在服务器端和客户端进行数据传输，同时服务器端可以根据客户端不同的数据包内容执行不同的业务处理逻辑。

在本项目中，主要的开发技术涉及 `Linux` 下 `epoll 高并发技术`，`线程池技术`，`线程同步技术`和独特的`延迟回收连接技术`等，同时配备了`信号处理`、`守护进程`、`配置文件读取`等功能，为保证服务器稳定运行，还对许多细节进行了较为完善的处理，在一定程度上参考了 Nginx 的架构实现，其中许多细节也参考了 Nginx 的实现方式，是一个对笔者来说很有挑战性的一个项目。

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

