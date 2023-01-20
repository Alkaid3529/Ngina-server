﻿
#ifndef __NGX_GBLDEF_H__
#define __NGX_GBLDEF_H__

#include <signal.h>

#include "ngx_c_slogic.h"
#include "ngx_c_threadpool.h"

// 本文件保存通用的定义、结构体定义和全局变量的外部声明

// 结构体定义

// 读取配置文件信息的结构体
typedef struct _CConfItem
{
	// 配置项目名称
	char ItemName[50];
	// 配置项目内容
	char ItemContent[500];

} CConfItem, *LPCConfItem;

// 日志存储结构体
typedef struct
{
	// 日志等级
	int log_level;
	// 日志文件描述符
	int fd;

} ngx_log_t;

// 外部全局变量声明
extern size_t g_argvneedmem;
extern size_t g_envneedmem;
extern int g_os_argc;
extern char **g_os_argv;
extern char *gp_envmem;
extern int g_daemonized;
extern CLogicSocket g_socket;
extern CThreadPool g_threadpool;

extern pid_t ngx_pid;
extern pid_t ngx_parent;
extern ngx_log_t ngx_log;
extern int ngx_process;
extern sig_atomic_t ngx_reap;
extern int g_stopEvent;

#endif
