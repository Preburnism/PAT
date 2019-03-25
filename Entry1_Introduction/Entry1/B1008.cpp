//数组元素循环右移(原题要求直接输出即可，此处代码排序后存入了当前数组)
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    m = m % n; //确保m<n
    int arr[108];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int t1, t2;

    //分两种情况，n个整数减去所移位数m对m取模是否为0，即依次取代后是否会归回原位，，，且m不为0
    if (m)
    {
        if ((n - m) % m == 0)
        {
            for (int j = 0; j < m; j++)
            {
                int i = j;

                t1 = arr[i];             //初始位置
                arr[i] = arr[n - m + i]; //前移

                while ((i += m) < n) //若没到第n-m 位持续后移
                {
                    t2 = arr[i];
                    arr[i] = t1;
                    t1 = t2;
                }
            }
        }
        else
        {
            int i = 0, j = 0;
            i += m;
            t1 = arr[0];
            arr[0] = arr[n - m];

            while (i != j)
            {
                t2 = arr[i];
                arr[i] = t1;
                t1 = t2;
                i + m < n ? i += m : i = i - (n - m); //判读前移or后移
            }
        }
    }

    printf("%d", arr[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    return 0;
}