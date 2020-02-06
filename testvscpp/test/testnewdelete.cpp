// testnewdelete.cpp

#include "testnewdelete.h"

// 测试目的：new一个数组，能否独立释放某一个成员

// 总结：不可以，语法上产生错误的，需要完整指针对象，若强制使用单个对象地址，运行仍然出现错误


class CTestNewDelete
{
public:
	~CTestNewDelete()
	{
		int test = 0;
	}
	int test;
};

void testnewdelete()
{
	CTestNewDelete *p = new CTestNewDelete[10];
	delete &p[2];
}