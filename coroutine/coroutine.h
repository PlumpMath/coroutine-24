//
//  coroutine.h
//  coroutine
//
//  Created by taowei on 14-2-8.
//  Copyright (c) 2014年 taowei. All rights reserved.
//

#ifndef __coroutine__coroutine__
#define __coroutine__coroutine__

//#define _XOPEN_SOURCE 600

#define COROUTINE_DEAD	0
#define COROUTINE_READY	1
#define COROUTINE_RUNNING 2
#define COROUTINE_SUSPEND 3

struct schedule;

typedef void (*coroutine_func)(struct schedule *, void *ud);

struct schedule * coroutine_open(void);
void coroutine_close(struct schedule *);

int coroutine_new(struct schedule *, coroutine_func, void *ud);
void coroutine_resume(struct schedule *, int id);
int coroutine_status(struct schedule *, int id);
int coroutine_running(struct schedule *);
void coroutine_yield(struct schedule *);


#endif /* defined(__coroutine__coroutine__) */
