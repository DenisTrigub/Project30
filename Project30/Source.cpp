#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void insertSort(int array[], int length) {
    int x, k;
    int leftNeg = -1;
    int rightNeg = -1;
    for (int i = 0; i < length; i++)
        if (array[i] < 0)
        {
            rightNeg = i;
        }
    for (int i = length - 1; i >= 0; i--)
        if (array[i] < 0)
        {
            leftNeg = i;
        }
    for (int n = 0; n < length; n++)//в этом цикле идет сортировка в нужном интервале
    {
        for (int i = leftNeg; i < rightNeg; i++)//ваши интервалы
        {
            k = i;
            x = array[i];
            for (int j = i + 1; j < rightNeg; j++)
                if (array[j] < x) {
                    k = j;
                    x = array[j];
                }
            array[k] = array[i];
            array[i] = x;

        }
        cout << array[n] << " ";//вывод всего массива
    }

}

int main()
{
    int const length = 20;
    int array[length];
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 40 - 10;
        cout << array[i] << " ";
    }
    cout << '\n';
    insertSort(array, length);
    cout << '\n';
    return 0;
}