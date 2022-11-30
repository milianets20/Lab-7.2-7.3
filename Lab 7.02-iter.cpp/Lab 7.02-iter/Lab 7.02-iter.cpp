#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int smallestInRow(int* a, const int n);
void Sort(int** a, const int n);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	cout << " Modified matrix :\n";
	Sort(a, n);
	Print(a, n);
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int smallestInRow(int* a, const int n)
{
	int min = a[0], index = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			index = i;
			min = a[i];
		}
	}
	return index;
}

void Sort(int** a, const int n)
{
	int tmp, index = 0;
	for (int i = 0; i < n; i++)
	{
		index = smallestInRow(a[i], n);
		tmp = a[i][index];
		a[i][index] = a[i][n - 1 - i];
		a[i][n - 1 - i] = tmp;
	}
}
