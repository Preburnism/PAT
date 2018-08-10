#include <stdio.h>
#include <iostream>

const int maxn = 20;
int p[maxn], hash[maxn] = {false};
int n, count = 0;

void generateP(int index)
{
    if (index == n + 1)
    {
        count++;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                (p[i] != j) ? (printf(" X ")) : (printf(" O "));
            }
            printf("\n");
        }
        printf("\n\n");
    }
    for (int x = 1; x <= n; x++)
    {
        if (hash[x] == false)
        {
            bool flag = true;
            //遍历之前的皇后
            for (int pre = 1; pre < index; pre++)
            {
                //第index列皇后行号为x，即p[index]=x;第pre列行号为p[pre]
                if (abs(index - pre) == abs(x - p[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                p[index] = x;
                hash[x] = true;
                generateP(index + 1);
                hash[x] = false;
            }
        }
    }
}

int main()
{
    n = 10;
    generateP(1);

    printf("%d", count);

    system("pause");
    return 0;
}
