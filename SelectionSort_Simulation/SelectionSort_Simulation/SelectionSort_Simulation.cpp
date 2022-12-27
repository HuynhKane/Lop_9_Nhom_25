#include <iostream>
#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define nMax 1500
#define keyMax 100
#define keyMin 0
#define sizeRec (1500 / nMax)
//(100 + sizeRec * i ,100 + 3 *M[i].key, 100 + sizeRec * (i + 1),500)
using namespace std;
struct Record {
	char data;
	int key;
};
void PrintKey(Record M[], int N)
{
	cout << "SELECTION SORTING";
	cout << "\nSo luong MAU: " << nMax;
	cout << "\nMAX: " << keyMax;
	cout << "\nMIN: " << keyMin;
	for (int i = 0; i < N; ++i)
	{

		rectangle(100 + sizeRec * i, 500 - 4 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(2);
	system("cls");
	return;
}
void SelectionSort(Record M[], int N)
{
	int i, j, min_idx;
	for (i = 0; i < N - 1; i++)
	{
		
		int dis = sizeRec;
		min_idx = i;
		circle(100 + sizeRec / 2 + i * dis, 520, 10);
		for (j = i + 1; j < N; j++)
		{
			
			circle(100 + sizeRec / 2 + min_idx * dis, 520, 10);
			
			if (M[j].key < M[min_idx].key)
			{
				min_idx = j;
				
			}
			
		}
		swap(M[min_idx], M[i]);
		PrintKey(M, N);
		
	}
	
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

	SelectionSort(M, N);
	system("cls");
	cout << "SELECTION SORTING";
	cout << "\nSo luong MAU: " << nMax;
	cout << "\nMAX: " << keyMax;
	cout << "\nMIN: " << keyMin;
	for (int i = 0; i < N; ++i)
	{

		rectangle(100 + sizeRec * i, 500 - 4 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(10000);
}
