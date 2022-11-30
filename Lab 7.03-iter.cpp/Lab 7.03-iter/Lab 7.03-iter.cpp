#include <iostream>
#include <iomanip>
using namespace std;
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Count(int** a, const int rowCount, const int colCount, int& count);
void SaddlePoint(int** a, const int rowCount, const int colCount);
bool IsMinInRowN(int** a, const int n, const int k, const int colCount);
bool IsMaxInColK(int** a, const int n, const int k, const int rowCount);
int main()
{
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	int count = 0;
	if (Count(a, rowCount, colCount, count))
		cout << "count = " << count << endl;
	else
		cout << "there are no zero elements" << endl;
	cout << endl;
	SaddlePoint(a, rowCount, colCount);
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Input(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Count(int** a, const int rowCount, const int colCount, int& count)
{
	bool result = false;
	count = 0;
	int k_zero;
	for (int i = 0; i < rowCount; i++)
	{
		k_zero = 0;
		for (int j = 0; j < rowCount; j++)
			if (a[i][j] == 0)
			{
				result = true;
				k_zero++;
				break;
			}
		if (k_zero > 0)
		{
			for (int j = 0; j < colCount; j++)
				if (a[i][j] < 0)
					count++;
		}
	}

	return result;
}
bool IsMinInRowN(int** a, const int n, const int k, const int colCount)
{
	for (int j = 0; j < colCount; j++)
		if (a[n][j] < a[n][k])
		{
			return false;
		}
	return true;
}
bool IsMaxInColK(int** a, const int n, const int k, const int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		if (a[i][k] > a[n][k])
		{
			return false;
		}
	return true;
}
void SaddlePoint(int** a, const int rowCount, const int colCount)
{
	cout << "Saddle points: min in row & max in col" << endl;
	cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
	int No = 0;
	for (int n = 0; n < rowCount; n++)
		for (int k = 0; k < colCount; k++)
			if (IsMinInRowN(a, n, k, colCount) && IsMaxInColK(a, n, k, rowCount))
			{
				cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
			}
}
