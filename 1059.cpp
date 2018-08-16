#include <stdio.h>
#include <math.h>

const int maxn = 100010;
int prime[maxn], num = 0;
bool isP[maxn] = {0}; //零初始化器;   isP[maxn] = {1}只会把第一个bool值初始化为true，其他都是false；

struct Factor
{
    int x, cnt;
} fac[10];

void FindPrime()
{
    for (int i = 2; i < maxn; i++)
    {
        if (isP[i] == false) //false为素数
        {
            prime[num++] = i;
            for (int j = i + i; j < maxn; j += i)
            {
                isP[j] = true;
            }
        }
    }
}

int main()
{
    int fn = 0;
    int N;
    scanf("%d", &N);
    if (N == 1)
        printf("1=1");
    else
    {
        printf("%d=", N);
        FindPrime();
        int sqr = (int)sqrt(1.0 * N);
        for (int i = 0; i < num && prime[i] <= sqr; i++)
        {
            if (N % prime[i] == 0)
            {
                fac[fn].x = prime[i];
                fac[fn].cnt = 0;
                while (N % prime[i] == 0)
                {
                    fac[fn].cnt++;
                    N /= prime[i];
                }
                fn++;
            }
            if (N == 1)
                break;
        }

        if (N != 1)
        {
            fac[fn].x = N;
            fac[fn++].cnt = 1;
        }

        for (int i = 0; i < fn; i++)
        {
            if (fac[i].cnt == 1)
                printf("%d", fac[i].x);
            else
                printf("%d^%d", fac[i].x, fac[i].cnt);
            if (i != fn - 1)
                printf("*");
        }
    }

    return 0;
}