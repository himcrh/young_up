#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#define width 1500
#define length 400

int n;
int** p;

enum column {
	A, B, C
};

void show();
void startup();

void move(int a, int b)
{
	for (int i = 0; i < n; i++)
	{
		if (p[a][i] == 1)
		{
			p[a][i] = 0;
			p[b][i] = 1;
			break;
		}
	}
	cleardevice();
	show();
	Sleep(100);
}

void honio(int a, int b, int c, int k)
{
	if (k == 1)
		move(a, c);
	else
	{
		honio(a, c, b, k - 1);
		move(a, c);
		honio(b, a, c, k - 1);
	}
}

void show()
{
	startup();
	setfillcolor(RED);
	setlinecolor(WHITE);
	for (int i = 0; i < 3; i++)
	{
		int cnt = 0;
		for (int j = n; j > 0; j--)
		{
			if (p[i][j - 1] == 1)
			{
				fillrectangle(width * (i + 1) / 4 - j * 10, length - (cnt + 1) * 10, width * (i + 1) / 4 + j * 10, length - cnt * 10);
				cnt++;
			}
		}
	}
	FlushBatchDraw();
}

void startup()
{
	setfillcolor(BLUE);
	setlinecolor(WHITE);
	fillrectangle(width / 4 - 5, 0, width / 4 + 5, 400);
	fillrectangle(width * 2 / 4 - 5, 0, width * 2 / 4 + 5, 400);
	fillrectangle(width * 3 / 4 - 5, 0, width * 3 / 4 + 5, 400);
}

int main()
{
	scanf_s("%d", &n);
	p = new int* [3];
	for (int i = 0; i < 3; i++)
		p[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[0][i] = 1;
	}

	initgraph(width, length);
	startup();
	BeginBatchDraw();
	show();
	honio(A, B, C, n);
	system("pause");
	return 0;
}
