#include <stdio.h>
#include <iostream>
#include <vector>

const int maxn = 20;
int n, p[maxn], hash[maxn] = {false};

void generateP(int index)
{
    int watch[6];
    for (int i = 1; i <= 5; i++)
    {
        watch[i] = hash[i];
    }

    if (index == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
        return;
    }
    for (int x = 1; x <= n; x++)
    {
        if (hash[x] == false)
        {
            p[index] = x;
            hash[x] = true;
            generateP(index + 1);
            hash[x] = false;
        }
    }
}

int main()
{
    n = 5;
    generateP(1);
    system("pause");
    return 0;
}