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
	cout << "SHELL SORTING";
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
void ShellSort(Record M[], int N)
{
	int i, j, dis = (sizeRec / 2);
	for (int kc = N / 2; kc > 0; kc -= 1)
	{
		for (i = kc; i < N; ++i)
		{
			Record R = M[i];
			for (j = i; j >= kc && M[j - kc].key > R.key; j -= kc)
			{
				
				M[j] = M[j - kc];	
				circle(100 + j * dis, 520, 10);
				circle(100 + (j - kc) * dis, 520, 10); 
			}
			M[j] = R;
			
		}
		
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
	
	ShellSort(M, N);
	system("cls");
	cout << "SHELL SORTING";
	cout << "\nSo luong MAU: " << nMax;
	cout << "\nMAX: " << keyMax;
	cout << "\nMIN: " << keyMin;
	for (int i = 0; i < N; ++i)
	{

		rectangle(100 + sizeRec * i, 500 - 4 * M[i].key, 100 + sizeRec * (i + 1), 500);

	}
	Sleep(10000);
}
