/*
	《C++程序设计》课程实验作业：结构化程序设计和基于对象编程练习
	程序：瓦瓦捡豆游戏
	任务：为瓦瓦分配不同的任务，然后设计瓦瓦捡豆的最优路径算法，并编写程序代码，执行程序验证结果

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

	// 为瓦瓦分派任务
	wawa.assignTask(0);

	// 提示按下任意键后开始执行后面的指令（完成任务的算法实现）
	BEGIN();

	// 请输入你的指令
	// 指令开始
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
	// 指令结束

	// 检查上面的指令执行后是否完成了任务，并给出相应的提示
	END(wawa);
}

void BEGIN()
{
	printf("\n按下任意键后开始执行你的指令。");
	_getch();
}

void END(XWawa &wawa)
{
	printf("\n所有指令已执行完毕。");
	if (wawa.taskIsAccomplished())
	{
		cout<<"\n恭喜！任务已完成。瓦瓦移动了"<<wawa.GetMoveCount()<<"次。";
	}
	else
	{
		printf("\n很遗憾，任务没有完成。修改代码，再试一次吧。");
	}
	printf("\n按下任意键后退出程序...\n");
	_getch();
}
