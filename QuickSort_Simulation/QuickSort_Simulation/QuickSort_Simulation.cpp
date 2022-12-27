#include <iostream>
#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define nMax 150
#define keyMax 100
#define keyMin 1
#define sizeRec (1500 / nMax)
//(100 + sizeRec * i ,100 + 3 *M[i].key, 100 + sizeRec * (i + 1),500)
using namespace std;
struct Record {
	char data;
	int key;
};
void PrintKey(Record M[], int N)
{
	cout << "QUICK SORTING";
	cout << "\nSo luong MAU: " << nMax;
	cout << "\nMAX: " << keyMax;
	cout << "\nMIN: " << keyMin;
	for (int i = 1; i < N; ++i)
	{

		rectangle(100 + sizeRec * i, 500 - 4 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(2);
	system("cls");
	return;
}
int partition(Record M[], int start, int end)
{

	int pivot = M[start].key;

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (M[i].key <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	swap(M[pivotIndex], M[start]);
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (M[i].key <= pivot) {
			i++;
		}

		while (M[j].key > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(M[i++], M[j--]);
		}
	}

	return pivotIndex;
}

void QuickSort(Record M[], int start, int end)
{
	PrintKey(M, nMax);
	if (start >= end)
		return;
	int p = partition(M, start, end);
	QuickSort(M, start, p - 1);
	
	QuickSort(M, p + 1, end);
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

	QuickSort(M,0, nMax);
	system("cls");
	cout << "QUICK SORTING";
	cout << "\nSo luong MAU: " << nMax;
	cout << "\nMAX: " << keyMax;
	cout << "\nMIN: " << keyMin;
	for (int i = 1; i < N; ++i)
	{

		rectangle(100 + sizeRec * i, 500 - 4 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(10000);
}
