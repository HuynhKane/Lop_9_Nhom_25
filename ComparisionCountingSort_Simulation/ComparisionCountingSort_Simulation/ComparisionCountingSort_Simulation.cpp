#include <iostream>
#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#define nMax 50
#define keyMax 100
#define keyMin 0
#define sizeRec (1500 / nMax)
//(100 + sizeRec * i ,100 + 3 *M[i].key, 100 + sizeRec * (i + 1),500)
using namespace std;
struct Record {
	char data;
	int key;
};
void PrintKey(Record M[], int N, int COUNT[])
{
	cout << "COMPARISION SORTING";
	cout << "\nSo luong MAU: " << nMax;
	cout << "\nMAX: " << keyMax;
	cout << "\nMIN: " << keyMin;
	drawText(1600, 700, "COUNTING TABLE");
	drawText(1600, 400, "RECORD M[]");
	for (int i = 0; i < N; ++i)
	{
		
		rectangle(100 + sizeRec * i, 500 - 4 * M[i].key, 100 + sizeRec * (i + 1), 500);
		rectangle(100 + sizeRec * i, 850 - (300 * COUNT[i])/nMax, 100 + sizeRec * (i + 1), 850);

	}
	Sleep(1);
	system("cls");
	return;
}

void ComparisionCounting(Record M[], int N) {
	int COUNT[nMax];
	int i, j;
	Record K[nMax];
	for (i = 0; i < N; i++) 
	{
		COUNT[i] = 0;
	}
	for (i = N - 1; i >= 1; i--)
	{
		for (j = i - 1; j >= 0; j--) 
		{
			drawText(100 + + sizeRec / 2 + sizeRec * j, 510, "J");
			drawText(100 + +sizeRec / 2 + sizeRec * i, 510, "I");
			circle(100 + +sizeRec / 2 + sizeRec * i, 550, 20);
			circle(100 + +sizeRec / 2 + sizeRec * j, 550, 20);
			PrintKey(M, N, COUNT);
			if (M[i].key <= M[j].key)
			{
				line(800, 675, 750, 700);
				line(800, 725, 750, 700);
				line(825, 680, 900, 680);
				line(825, 720, 900, 720);

				COUNT[j] += 1;
			}
			else
			{
				line(700, 675, 750, 700);
				line(700, 725, 750, 700);
				COUNT[i] += 1;
			}
		}
		PrintKey(M, N, COUNT);
		
	}
	for (i = 0; i < N; i++) 
	{
		K[COUNT[i]].key = M[i].key;
		
	}
	for (int i = 0; i < N; i++)
	{
		M[i].key = K[i].key;
	}
	//PrintKey(M, N, COUNT);
}
int main()
{
	initgraph();
	srand(time(NULL));
	int N = nMax;
	Record M[nMax];

	for (int i = 0; i < N; ++i)
	{
		M[i].key = rand() % keyMax + keyMin;
		setcolorRGB(160, 32, 240);
	}
	ComparisionCounting(M, N);
	system("cls");
	cout << "COMPARISION SORTING";
	cout << "\nSo luong MAU: " << nMax;
	cout << "\nMAX: " << keyMax;
	cout << "\nMIN: " << keyMin;
	drawText(750, 550, "________COMPLETE________");
	for (int i = 0; i < N; ++i)
	{

		rectangle(100 + sizeRec * i, 500 - 4 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(100000);
}
