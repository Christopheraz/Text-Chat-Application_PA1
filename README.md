## CSE 589 - PA1 - Info
### 链接
1. https://github.com/pwfee/Text-Chat-Application Github Private Repo
2. https://github.com/exceptionhandle/Text-Chat-Application 现成代码
3. http://beej-zhcn.netdpi.net/ 参考 API

### 需求分配
函数 - 包含在头文件 ```include/server.h```


1. Print function
    * ```void PrintIP(); /* Client & Server */```
    * ```void PrintPort(); /* Client & Server */```
    * ```void PrintList(); /* Client & Server */```
    * ```void PrintStatistics(); /* Server */```
    * ~~```void PrintAuthor(); /* Client & Server */```~~

2. Core function
    * ```SetPort(); /* Client & Server */```
    * ```Login(); /* Client */```
    * ```Logout(); /* Client */```
    * ```Exit();/* Client */```
    
    
3. Message function
    * ```SendMsg(); /* Client */```
    * ```Broadcast(); /* Client */```
    * ```Blocked(); /* Server */```
    * ```Block();  /* Client */```
    * ```UnBlock(); /* Client */```
    * ```Refresh(); /* Client */```
    
4. utils function
    * StrToInt()
    * IPConvert()
    * ...


结构体

* 存放 LIST 以及 STATISTICS
* ...

### 编译 
``` /include ``` 存放头文件
``` /src ``` 存放 *.cpp 文件

Makefile 根据文件结构执行链接和编译，在根目录执行
```$ make```


### 文件结构
```.
├── Makefile
├── README.md
├── assignment1
├── include
│   ├── global.h
│   ├── logger.h
│   └── server.h
├── logs
├── object
│   ├── assign.o
│   ├── assignment1.o
│   ├── logger.o
│   └── server.o
└── src
    ├── assignment1.cpp
    ├── logger.cpp
    └── server.cpp
```

