#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}
int smallestInRow(int* a, const int N, int index, int min, int i)
{
	if (i >= N)
		return index;
	else
		if (a[i] < min) {
			index = i;
			min = a[i];
		}
	return smallestInRow(a, N, index, min, i + 1);
}
void Sort(int** a, const int N, int i)
{
	int tmp;
	int index = smallestInRow(a[i], N, 0, a[i][0], 0);
	tmp = a[i][index];
	a[i][index] = a[i][N - 1 - i];
	a[i][N - 1 - i] = tmp;
	if (i < N - 1)
		Sort(a, N, i + 1);
}

int main()
{
	srand((unsigned)time(NULL));
	int N;
	cout << "N = "; cin >> N;
	cout << endl;
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];
	int Low = 7, High = 65;
	CreateRows(a, N, Low, High, 0);
	PrintRows(a, N, 0);
	cout << " Modified matrix :\n\n";
	Sort(a, N, 0);
	PrintRows(a, N, 0);
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
