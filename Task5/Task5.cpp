#include<iostream>
using namespace std;

int main()
{
	int k = 1;
	int n = 0;
	cin >> n;

	int** data = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		data[i] = new int[n];
	}

	if (n % 2 != 0)
	{
		data[n / 2][n / 2] = n * n;
	}

	for (int i = 0; i < (n / 2); i++)
	{
		for (int j = i; j < (n - i); j++)
		{
			data[i][j] = k;
			k++;
		}
		for (int j = 1; j < (n - i - i); j++)
		{
			data[j + i][(n - i) - 1] = k;
			k++;
		}
		for (int j = (n - 2) - i; j >= i; j--)
		{
			data[(n - i) - 1][(j)] = k;
			k++;
		}
		for (int j = (n - i) - 2; j > i; j--)
		{
			data[j][i] = k;
			k++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%4d ", data[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
	{
		delete[] data[i];
	}
	delete[] data;

	return 0;
}