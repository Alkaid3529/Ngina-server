# Ngina-server Project overview
This project built a high quality `multi-thread` and `high concurrency server program framework` from scratch, and realized the data transmission between the server and the client according to the specified data packet format. At the same time, the server could execute different business processing logic and other functions according to the different data packet contents of the client.

# Project technology
In this project, the main development technology involves `epoll high concurrency technology` under Linux, `thread pool` technology, `thread synchronization` technology and unique `delay recovery connection` technology, etc. At the same time, it is equipped with signal processing, daemon process, configuration file reading and other functions. In order to ensure the stable operation of the server, many details are also completed. It is a very challenging project for the author, which refers to the architecture implementation of Nginx to some extent, and many of the details also refer to the implementation of Nginx.

# Project deployment
The root directory of the project contains seven folders and four files. The functions of each folder and file are as follows:

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
