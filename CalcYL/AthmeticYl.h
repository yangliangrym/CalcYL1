#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <qstring.h>
using namespace std;
struct fraction {
	int a;
	int b;
};

class AthmeticYl
{
public:
	AthmeticYl();
	~AthmeticYl();
	//�ýṹ���Ų����� 
	string buf;
	int TestN = 0;					   //��Ŀ����
	char ope[4] = { '+','-','x','/' }; //������
	struct fraction mOpn[11];
	char mRightAns[100];
	QString gRightAns;				   //��ȷ�𰸣����ڽ������
	QString pTest;
	double ro(double r);
	int Priority(char op);
	int gcd(int a, int b);
	struct fraction Ca(struct  fraction n1, struct fraction n2, char op);
	struct  fraction getN();
	char getop();
	char m();
	void PrintTest(int n);
	bool Jug(QString YouAns);
};

