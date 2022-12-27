#include <iostream>
#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

#define nMax 1000 //Thay doi do lon cua MANG tai day
#define keyMax 100 // gia tri Max khi random
#define keyMin 0 // gia tri Min khi random
#define sizeRec (1200 / nMax)
//(100 + sizeRec * i ,100 + 3 *M[i].key, 100 + sizeRec * (i + 1),500)
using namespace std;
struct Record {
	char data;
	int key;
};
void PrintKey(Record M[], int N)
{
	int j = 0;
	int temp = 0;
	cout << "\t\t\t\t\t\tMERGE SORTING";
	for (int i = 0; i < N; ++i, j += 15)
	{

		rectangle(100 + sizeRec * i, 400 - 3 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(50);
	system("cls");

	return;
}
void Merge(Record M[], int L, int mid, int R)
{
	int i, j, k = L;
	int n1 = mid - L + 1;
	int n2 = R - mid;
	Record* M1 = new Record[n1];
	Record* M2 = new Record[n2];
	for (i = 0; i < n1; ++i)
	{
		M1[i] = M[L + i];
	}
	for (j = 0; j < n2; ++j)
	{
		M2[j] = M[mid + j + 1];
	}
	i = j = 0;
	while (i < n1 && j < n2) {

		M[k++] = (M1[i].key <= M2[j].key) ? M1[i++] : M2[j++];
	}
	while (i < n1) {

		M[k++] = M1[i++];
	}
	while (j < n2)
	{

		M[k++] = M2[j++];
	}
}

void MergeSort(Record M[], int L, int R)
{
	if (L < R)
	{
		int dis = sizeRec;
		int mid = (L + R) / 2;
		circle(100 + mid * dis, 550, 10);
		MergeSort(M, L, mid);
		circle(100 + mid * dis, 550, 10);
		MergeSort(M, mid + 1, R);
		circle(100 + mid * dis, 550, 10);
		Merge(M, L, mid, R);
		PrintKey(M, nMax);
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
	
	MergeSort(M, 0, nMax);
	cout << "\t\t\t\t\t\tMERGE SORTING";
	for (int i = 1; i < N; ++i)
	{
		
		rectangle(100 + sizeRec * i, 400 - 3 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(10000);
}
