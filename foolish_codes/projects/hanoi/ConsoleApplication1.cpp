#include<graphics.h>//EasyX图形库
#include<bits/stdc++.h>
using namespace std;

int DiskNum;//记录盘的数量
const int width = 800;
const int length = 650;

enum peg{
	A=0, B, C//A,B,C分别表示三个柱子
};

typedef struct DISK {
	int ord,left, top, right, bottom;
}disk;//采用结构体记录盘的标号和大小
stack<DISK> peg[3];//采用栈记录每个柱子上的盘

void initshow();//绘制背景
void initdisk();//初始化盘子的长度
void hanoi(int num, int origin, int pass, int aim);//递归移动盘
void Move(int origin, int aim);//移动单个盘

int main() {
	puts("Please input the number of disks");
	puts("the number must be less than 25");
	scanf_s("%d", &DiskNum);//得到盘的数量
	initshow();
	initdisk();
	hanoi(DiskNum, A, B, C);
	return 0;
}

void initshow() {
	initgraph(width, length);
	setbkcolor(WHITE);//设置背景为白色
	cleardevice();
	//绘制红色柱子
	setlinecolor(RED);
	line(200, 110, 200, 500); //outtextxy();
	line(400, 110, 400, 500); 
	line(600, 110, 600, 500);
	//绘制灰色底座
	setfillcolor(LIGHTGRAY);
	fillrectangle(80, 501, 720, 510);
}

void initdisk() {
	for (int i = 1; i <= DiskNum; i++) {
		disk di = { i,110 + i * 5,500 - i * 20,290 - i * 5,518 - i * 20 };
		solidrectangle(di.left, di.top, di.right, di.bottom);
		peg[0].push(di);
	}
}

void hanoi(int num, int origin, int pass, int aim) {
	//将num个盘从origin移动到aim,经过pass
	if (num == 1) {
		//只移动一个盘时，直接移动即可
		Move(origin, aim);
		return;
	}
	//移动多个盘时，先将num-1个盘从origin移动到pass,经过aim
	hanoi(num - 1, origin, aim, pass);
	//再将底层的盘从origin移动到aim
	Move(origin, aim);
	//最后将num-1个盘从pass移动到aim,经过origin
	hanoi(num - 1, pass, origin, aim);
}

void Move(int origin, int aim){
	int dx = aim - origin;
	disk di1 = peg[origin].top();//移动前的盘子
	peg[origin].pop();
	int l = peg[aim].size();
	disk di2 ={di1.ord,di1.left + dx * 200 ,480-l*20,
	di1.right+dx*200,498-l*20};//移动后的盘子
	peg[aim].push(di2);
	// 向上运动
	while (di1.top >= 100)
	{
		setfillcolor(GREEN);
		solidrectangle(di1.left, di1.top, di1.right, di1.bottom);
		Sleep(10);
		setfillcolor(WHITE);
		solidrectangle(di1.left, di1.top, di1.right, di1.bottom);
		setlinecolor(RED);
		line((di1.left + di1.right) / 2, di1.top, (di1.left + di1.right) / 2, di1.bottom);	// 重新画上被擦掉原有的红线
		di1.top -= 10;
		di1.bottom -= 10;
	}

	// 向左或右运动，与 dx 的正负有关
	while (di1.right != di2.right)
	{
		setfillcolor(GREEN);
		solidrectangle(di1.left, di1.top, di1.right, di1.bottom);
		Sleep(10);
		setfillcolor(WHITE);
		solidrectangle(di1.left, di1.top, di1.right, di1.bottom);
		if (dx < 0)											// dx<0向左移
		{
			di1.left -= 20;
			di1.right -= 20;
		}
		else												// dx>0向右移
		{
			di1.left += 20;
			di1.right += 20;
		}
	}

	// 向下运动
	while (di1.bottom <= di2.bottom)
	{
		setfillcolor(GREEN);
		solidrectangle(di1.left, di1.top, di1.right, di1.bottom);

		Sleep(10);
		setfillcolor(WHITE);
		solidrectangle(di1.left, di1.top, di1.right, di1.bottom);
		setlinecolor(RED);
		if (di1.top > 100)									// 重画被擦掉的红线
		{
			line((di1.left + di1.right) / 2, di1.top, (di1.left + di1.right) / 2, di1.bottom);
		}
		di1.top += 10;
		di1.bottom += 10;
	}

	// 在目的钢针上的相应位置绘制出黄色矩形块
	setfillcolor(YELLOW);
	solidrectangle(di1.left, di1.top - 10, di1.right, di1.bottom - 10);
}
