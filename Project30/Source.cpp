#include <iostream>
#include<stdio.h>
using namespace std;
void init(int A[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		A[i] = rand() % 20 + 1;
}

void out(int A[], int size)
{
	cout << "\n";
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << "\n";
}

void random(int A[], int size)
{
	int x, i, j;

	for (i = 0; i < size; i++)
	{
		x = A[i];
		for (j = i - 1; j >= 0 && A[j] != x && A[j] != A[i]; j--)
			A[j + 1] = A[j];
		A[j + 1] = x;
	}
}

int search(int A[], int size, int digit)
{
	for (int i = 0; i < size; i++)
		if (A[i] == digit)
			return i;
	return -1;
}

void sort(int A[], int size, int key)
{
	int x, i, j;
	for (i = 0; i < key; i++)
	{
		x = A[i];
		for (j = i - 1; j >= 0 && A[j] < x; j--)
			A[j + 1] = A[j];
		A[j + 1] = x;
	}
	for (i = key + 1; i < size; i++)
	{
		x = A[i];
		for (j = i - 1; j >= key + 1 && A[j] > x; j--)
			A[j + 1] = A[j];
		A[j + 1] = x;
	}
}
void main()
{
	setlocale(LC_ALL, "Russian");
	const int s = 20;
	int A[s];
	int a, digit, tmp;

	do
	{
		init(A, s);
		out(A, s);
		cout << "\nЭта программа принимает массив из 20 целых чисел со значениями от 1 до 20:\n";
		cout << "1 - разбрасывает элементы массива произвольным образом.\n";
		cout << "2 - Пользователь вводит случайное число из того же диапазона, программа находит позицию этого числа в массиве\n";
		cout << " и сортирует элементы массива, находящиеся слева от найденной позиции по убыванию, а элементы массива,\n";
		cout << " находящиеся справа от найденной позиции по возрастанию\n";
		cout << "Введите ваш выбор: ";
		cin >> a;
		switch (a)
		{
		case 1:
			random(A, s);
			out(A, s);
		case 2:
			cout << "Введите число из диапазона от 1 до 20:";
			cin >> digit;
			tmp = search(A, s, digit);
			if (tmp != -1)
			{
				cout << "Число " << digit << " есть в массиве под номером " << tmp << "\n";
				sort(A, s, tmp);
				out(A, s);
			}
			else
				cout << "Число " << digit << " отсутствует в массиве\n";
		}
		cout << "\nЕсли хотите продолжить, нажмите 1\n";
		cin >> a;
	} while (a == 1);
}

