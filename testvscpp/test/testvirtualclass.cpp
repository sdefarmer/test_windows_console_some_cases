// testvirtualclass.cpp

#include "testvirtualclass.h"

// ����Ŀ�ģ������࣬�ͷ�ʱ�ܷ������ͷŵ�

// �ܽ᣺�ڴ��������ʱ���������麯������ᴴ��һ��������汣�������麯����ָ�룬���ڵ�������ʵ�ֺ���
// ������û�ж��������麯��ʱ������û��������������ô������оͲ�������������ָ��
// ��ˣ��ڶ����ͷ�ʱ�����ͷŵ��Ǹ��࣬��ô�������������޷��õ�����
// ��Ҫ���ඨ�������麯���������ͷ�ʱ��ʹ�ô���ʱ����


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