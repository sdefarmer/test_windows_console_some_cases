// testnewdelete.cpp

#include "testnewdelete.h"

// ����Ŀ�ģ�newһ�����飬�ܷ�����ͷ�ĳһ����Ա

// �ܽ᣺�����ԣ��﷨�ϲ�������ģ���Ҫ����ָ�������ǿ��ʹ�õ��������ַ��������Ȼ���ִ���


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