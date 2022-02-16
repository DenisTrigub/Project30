#include <iostream>
using namespace std;

void init(int A[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		A[i] = rand() % 100;
}

void out(int A[], int size)
{
	cout << "\n";
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << "\n";
}

void sort(int A[], int size, int uk = 1)
{
	int x, i, j;
	if (uk == 0)
	{
		for (i = 0; i < size; i++)
		{
			x = A[i];
			for (j = i - 1; j >= 0 && A[j] > x; j--)
				A[j + 1] = A[j];
			A[j + 1] = x;
		}
	}
	else if (uk == 1)
	{
		for (i = 0; i < size; i++)
		{
			x = A[i];
			for (j = i - 1; j >= 0 && A[j] < x; j--)
				A[j + 1] = A[j];
			A[j + 1] = x;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	const int s = 10;
	int A[s];
	int a;
	do
	{
		cout << "Эта программа сортирует массив по возрастанию или по убыванию.\n";
		init(A, s);
		out(A, s);
		cout << "1 - по убыванию\n0 - по возрастанию\n";
		cin >> a;
		if (a != 0)
			sort(A, s, 1);
		else
			sort(A, s, a);
		cout << "\nРезультат:\n";
		out(A, s);
		cout << "\nЕсли хотите продолжить, нажмите 1\n";
		cin >> a;
	} while (a == 1);
}


