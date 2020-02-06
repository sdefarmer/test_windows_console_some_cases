// testvscpp.cpp : �������̨Ӧ�ó������ڵ㡣
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


char* tip[] = { "0: �������������ͷ�����", 
				"1: ���Զ����ͷ�һ�������ڴ��ж����Ķ���",
				"2: ����pthread�ڴ����й©����",
				"3: ����Event������ͬ����",
				"4: ����Mutex������ͬ����",
				"5: ����vector",
				"99: ������ʱ����",
				"100: �˳�����"};


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
		printf("�����룺");
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

