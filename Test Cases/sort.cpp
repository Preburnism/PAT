#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int n = 11;
int array[n] = {4, 7, 8, 5, 2, 4, 55, 42, 9, 42, 15};

void bubbleSort()
{
    for (int i = 0; i < n - 1; i++) //n-1趟排序
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectSort()
{
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = k; j < n; j++) //sort from[i,n]
        {
            if (array[k] > array[j])
            {
                k = j;
            }
        }
        int temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
}

void insertSort()
{
    for (int i = 1; i < n; i++)
    {
        int temp = array[i];
        int j = i;
        while (j > 0 && temp < array[j - 1])
        {
            array[j] = array[j - 1];//元素后移
            j--;
        }
        array[j] = temp;
    }
}

int main()
{
    //selectSort();
    //bubbleSort();
    //insertSort();
    sort(array, array + n);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    system("pause");
    return 0;
}