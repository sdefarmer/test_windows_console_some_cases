// testvscpp.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <malloc.h>
#include<new.h>
#include <crtdbg.h>
#include <iostream>

#include "test/testvirtualclass.h"
#include "test/testnewdelete.h"
#include "test/testpthread.h"
#include "test/teststdvector.h"
#include "test/testtemp.h"


char* tip[] = { "0: 测试虚类析构释放问题", 
				"1: 测试独立释放一个数组内存中独立的对象",
				"2: 测试pthread内存存在泄漏问题",
				"3: 测试Event名称相同问题",
				"4: 测试Mutex名称相同问题",
				"5: 测试vector",
				"99: 测试临时代码",
				"100: 退出程序"};


int main()
{
	bool bContinue = true;
	do
	{
		int nTipCount = sizeof(tip) / sizeof(char*);
		for (int i = 0; i < nTipCount; ++i)
		{
			printf(tip[i]);
			printf("\n");
		}
		printf("请输入：");
		int nInput = -1;
		std::cin >> nInput;
		switch (nInput)
		{
		case 0:
			testvirtualclass();
			break;
		case 1:
			testnewdelete();
			break;
		case 2:
			testpthread();
			break;
		case 3:
			testEvent();
			break;
		case 4:
			testMutex();
			break;
		case 5:
			teststdvector();
			break;
		case 99:
			testtemp();
			break;
		case 100:
			bContinue = false;
			break;
		}
	} while (bContinue);

    return 0;
}

