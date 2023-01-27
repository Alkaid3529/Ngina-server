# Ngina-server Project overview
This project built a high quality `multi-thread` and `high concurrency server program framework` from scratch, and realized the data transmission between the server and the client according to the specified data packet format. At the same time, the server could execute different business processing logic and other functions according to the different data packet contents of the client.

# Project technology
In this project, the main development technology involves `epoll high concurrency technology` under Linux, `thread pool` technology, `thread synchronization` technology and unique `delay recovery connection` technology, etc. At the same time, it is equipped with signal processing, daemon process, configuration file reading and other functions. In order to ensure the stable operation of the server, many details are also completed. It is a very challenging project for the author, which refers to the architecture implementation of Nginx to some extent, and many of the details also refer to the implementation of Nginx.

# Content description
The author will use about half a month or so to gradually improve this set of multi-threaded high concurrency server framework, including network communication, signal processing and other functional modules, plan to complete the source code of each module, the final combination of its composition of a complete server framework.Note that the introduction document is in English and the comments are in Chinese.
