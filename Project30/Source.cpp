#include <iostream>
using namespace std;
int main()
{
	srand(time(0));
	const int size = 10;
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % -20 - 20;
		cout << arr[i] << endl;
	}
	return 0;
}