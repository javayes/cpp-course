/*
	��C++������ơ��γ�ʵ����ҵ���ṹ��������ƺͻ��ڶ�������ϰ
	�������߼���Ϸ
	����Ϊ���߷��䲻ͬ������Ȼ��������߼񶹵�����·���㷨������д������룬ִ�г�����֤���

	2011-02-20	ZhangHua
*/
#include <iostream>
#include <conio.h>
using namespace std;

#include "XWawa.h"

#pragma comment(lib, "XWawa.lib")

void BEGIN();
void END(XWawa&);

void main()
{
	XWawa wawa;

	// Ϊ���߷�������
	wawa.assignTask(0);

	// ��ʾ�����������ʼִ�к����ָ����������㷨ʵ�֣�
	BEGIN();

	// ���������ָ��
	// ָ�ʼ
	// --------------------------------------------------
	wawa.moveUp();
	wawa.moveUp();
	while (wawa.beanIsHere())
	{
		wawa.pickupBean();
		if (wawa.rightIsClear())
			wawa.moveRight();
		else
			break;
	}
	// --------------------------------------------------
	// ָ�����

	// ��������ָ��ִ�к��Ƿ���������񣬲�������Ӧ����ʾ
	END(wawa);
}

void BEGIN()
{
	printf("\n�����������ʼִ�����ָ�");
	_getch();
}

void END(XWawa &wawa)
{
	printf("\n����ָ����ִ����ϡ�");
	if (wawa.taskIsAccomplished())
	{
		cout<<"\n��ϲ����������ɡ������ƶ���"<<wawa.GetMoveCount()<<"�Ρ�";
	}
	else
	{
		printf("\n���ź�������û����ɡ��޸Ĵ��룬����һ�ΰɡ�");
	}
	printf("\n������������˳�����...\n");
	_getch();
}
