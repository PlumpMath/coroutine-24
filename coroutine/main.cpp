//
//  main.cpp
//  coroutine
//
//  Created by taowei on 14-2-8.
//  Copyright (c) 2014年 taowei. All rights reserved.
//

#include "coroutine.h"
#include <iostream>

struct args {
	int n;
};

static void foo(struct schedule *S, void *ud) {
	struct args *arg = (struct args *)ud;
	int start = arg->n;
	int i;
	for (i = 0; i < 5; i++) {
		printf("coroutine %d : %d\n", coroutine_running(S), start + i);
		coroutine_yield(S);
	}
}

static void test(struct schedule *S) {
	struct args arg1 = { 0 };
	struct args arg2 = { 100 };

	int co1 = coroutine_new(S, foo, &arg1);
	int co2 = coroutine_new(S, foo, &arg2);
	printf("start\n");
	while (coroutine_status(S, co1) && coroutine_status(S, co2)) {
		coroutine_resume(S, co1);
		coroutine_resume(S, co2);
	}
	printf("end\n");
}

int main(int argc, const char * argv[])
{
	struct schedule *S = coroutine_open();
	test(S);
	coroutine_close(S);
    return 0;
}

