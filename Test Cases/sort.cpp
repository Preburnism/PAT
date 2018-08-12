#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
            array[j] = array[j - 1]; //元素后移
            j--;
        }
        array[j] = temp;
    }
}

int Partition(int left, int right)
{
    int p = round(1.0 * rand() / RAND_MAX * (right - left) + left);
    swap(array[left], array[p]);

    int temp = array[left];
    while (left < right)
    {
        while (left < right && array[right] > temp)
            right--;
        array[left] = array[right];

        while (left < right && array[left] <= temp)
            left++;
        array[right] = array[left];
    }
    array[left] = temp;
    return left;
}

void quickSort(int left, int right)
{
    if (left < right)
    {
        int pos = Partition(left, right);
        quickSort(left, pos - 1);  //左子区间
        quickSort(pos + 1, right); //右子区间
    }
}

int main()
{
    //selectSort();
    //bubbleSort();
    //insertSort();
    //sort(array, array + n);
    srand((unsigned)time(NULL));
    quickSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    system("pause");
    return 0;
}