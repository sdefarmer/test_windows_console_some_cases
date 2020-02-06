// testvirtualclass.cpp

#include "testvirtualclass.h"

// 测试目的：纯虚类，释放时能否将子类释放掉

// 总结：在创建类对象时，若存在虚函数，则会创建一个虚表，里面保存所有虚函数的指针，用于调用子类实现函数
// 当父类没有定义析构虚函数时，或者没有析构函数，那么在虚表中就不会存在这个函数指针
// 因此，在对象释放时，若释放的是父类，那么子类析构函数无法得到调用
// 需要父类定义析构虚函数，或者释放时，使用创建时的类


class CMyVirtualClass
{
public:
	//virtual ~CMyVirtualClass()
	//{
	//	int test = 0;
	//}
	virtual void func1()
	{
		int test = 0;
	}
	virtual void func2() = 0;
};

class CMyClass : public CMyVirtualClass
{
public:
	CMyClass()
	{
		int test = 0;
	}
	virtual ~CMyClass()
	{
		int test = 0;
	}
	void func1()
	{
		int test = 0;
	}
	void func2()
	{

	}
private:
	int test;
};

void testvirtualclass()
{
	CMyVirtualClass *p = new CMyClass;
	p->func1();
	delete p;
}