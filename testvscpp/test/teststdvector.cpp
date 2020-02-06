// teststdvector.cpp

#include "teststdvector.h"
#include <stdio.h>
#include <vector>

// ����Ŀ�ģ�std::moveʹ��

// �ܽ᣺std::move������Ч���⹹���µĶ���

class CTestMove
{
public:
	CTestMove() { printf("CTestMove constructor\n"); }
	CTestMove(const CTestMove &mo) { printf("CTestMove copy constructor\n"); }
	~CTestMove() { printf("CTestMove destructor\n"); }
};

std::vector<CTestMove> getcopymove()
{
	std::vector<CTestMove> data;
	CTestMove move;
	data.push_back(move);
	return data;//std::move(data);
}
void teststdmove()
{
	printf("teststdmove start\n");
	std::vector<CTestMove> vec;
	printf("teststdmove add object to vector\n");
	CTestMove test;
	vec.push_back(test);
	printf("teststdmove add object to vector end\n");

	printf("teststdmove normal set\n");
	std::vector<CTestMove> vec2;
	vec2 = vec;
	printf("teststdmove normal set end\n");

	printf("teststdmove move set\n");
	std::vector<CTestMove> vec3;
	vec3 = std::move(vec);
	printf("teststdmove move set end\n");

	printf("teststdmove get move set\n");
	std::vector<CTestMove> vec4 = getcopymove();
	printf("teststdmove get move set end\n");

	printf("teststdmove end\n");
}

void teststdvector()
{
	printf("����std::move��ʹ��\n");
	teststdmove();
	printf("\n");
}