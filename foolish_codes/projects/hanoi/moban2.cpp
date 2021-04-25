#include<easyx.h>
#define MAX 5
typedef struct MyRect
{
	int left;
	int top;
	int right;
	int bottom;
}MYRECT;

typedef struct MyStack
{
	MYRECT rect[MAX + 1];
	int    top;
}MYSTACK;

MYSTACK g_Pillar[3] = { 0 };
int		g_nPan = MAX;
// ��������
void Hannoi(int n, char a, char b, char c);		// ��ŵ���ݹ�
void Move(int n, char a, char b);				// �ƶ�����
int  switchab(char a);

int main()
{
	initgraph(800, 650);
	setbkcolor(WHITE);
	cleardevice();
	//��������
	setlinecolor(RED);
	line(400, 110, 400, 500);
	line(600, 110, 600, 500);
	line(200, 110, 200, 500);
	//����
	setfillcolor(LIGHTGRAY);
	fillrectangle(80, 501, 720, 510);
	//-------------
	for (int i = 0; i < MAX; i++)
	{
		g_Pillar[0].top++;
		g_Pillar[0].rect[g_Pillar->top].left = 115 + i * 5;
		g_Pillar[0].rect[g_Pillar->top].top = 480 - i * 20;
		g_Pillar[0].rect[g_Pillar->top].right = 285 - i * 5;
		g_Pillar[0].rect[g_Pillar->top].bottom = 498 - i * 20;

		solidrectangle(g_Pillar[0].rect[g_Pillar[0].top].left, g_Pillar[0].rect[g_Pillar[0].top].top,
			g_Pillar[0].rect[g_Pillar[0].top].right, g_Pillar[0].rect[g_Pillar[0].top].bottom);
	}
	Hannoi(g_nPan, 'a', 'b', 'c');

	//-------------
	closegraph();
	return 0;
}

void Hannoi(int n, char a, char b, char c)
{
	if (n == 1)
		Move(1, a, c);
	else
	{
		Hannoi(n - 1, a, c, b);
		Move(n, a, c);
		Hannoi(n - 1, b, a, c);
	}
}
// �ƶ�����
void Move(int n, char a, char b)
{
	int dx = 0, iSrc = 0, iDst = 0;
	dx = switchab(b) - switchab(a);						// Ŀ�ĸ�����Դ�����λ�ò�ֵ
	iSrc = switchab(a);										// Դ��������
	iDst = switchab(b);										// Ŀ�ĸ����

	MYRECT pan1 = { 0 };//�ƶ�ǰ������
	MYRECT pan2 = { 0 };//�ƶ��������

	// Դջ��Ŀ��ջֵ�Ĵ���
	pan1 = g_Pillar[iSrc].rect[g_Pillar[iSrc].top];
	g_Pillar[iSrc].top--;

	g_Pillar[iDst].top++;
	pan2.left = pan1.left + dx * 200;
	pan2.top = 500 - g_Pillar[iDst].top * 20;
	pan2.right = pan1.right + dx * 200;
	pan2.bottom = 500 - g_Pillar[iDst].top * 20 + 18;
	g_Pillar[iDst].rect[g_Pillar[iDst].top] = pan2;
	// �����˶�
	while (pan1.top >= 100)
	{
		setfillcolor(GREEN);
		solidrectangle(pan1.left, pan1.top, pan1.right, pan1.bottom);
		Sleep(10);
		setfillcolor(WHITE);
		solidrectangle(pan1.left, pan1.top, pan1.right, pan1.bottom);
		setlinecolor(RED);
		line((pan1.left + pan1.right) / 2, pan1.top, (pan1.left + pan1.right) / 2, pan1.bottom);	// ���»��ϱ�����ԭ�еĺ���
		pan1.top -= 10;
		pan1.bottom -= 10;
	}

	// ��������˶����� i3 �������й�
	while (pan1.right != pan2.right)
	{
		setfillcolor(GREEN);
		solidrectangle(pan1.left, pan1.top, pan1.right, pan1.bottom);
		Sleep(10);
		setfillcolor(WHITE);
		solidrectangle(pan1.left, pan1.top, pan1.right, pan1.bottom);
		if (dx < 0)											// i3<0������
		{
			pan1.left -= 20;
			pan1.right -= 20;
		}
		else												// i3>0������
		{
			pan1.left += 20;
			pan1.right += 20;
		}
	}

	// �����˶�
	while (pan1.bottom <= pan2.bottom)
	{
		setfillcolor(GREEN);
		solidrectangle(pan1.left, pan1.top, pan1.right, pan1.bottom);

		Sleep(10);
		setfillcolor(WHITE);
		solidrectangle(pan1.left, pan1.top, pan1.right, pan1.bottom);
		setlinecolor(RED);
		if (pan1.top > 100)									// �ػ��������ĺ���
		{
			line((pan1.left + pan1.right) / 2, pan1.top, (pan1.left + pan1.right) / 2, pan1.bottom);
		}
		pan1.top += 10;
		pan1.bottom += 10;
	}

	// ��Ŀ�ĸ����ϵ���Ӧλ�û��Ƴ���ɫ���ο�
	setfillcolor(YELLOW);
	solidrectangle(pan1.left, pan1.top - 10, pan1.right, pan1.bottom - 10);
}

int switchab(char a)
{
	switch (a)
	{
	case 'a':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	}
	return 0;
}