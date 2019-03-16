//Product of Polynomials
#include <stdio.h>

const int maxn = 2005;                      //0 <= N <=1000, so N+N <= 2000
double co[maxn] = {0.0}, res[maxn] = {0.0}; //res stores the result

int main()
{
    int k, n;
    double a; //n:exponent, a:coefficient;

    scanf("%d", &k);
    for (int i = 0; i < k; i++) //input the first line
    {
        scanf("%d%lf", &n, &a);
        co[n] = a;
    }

    k = 0; //qingkong k
    scanf("%d", &k);
    for (int i = 0; i < k; i++) //input the second line, multipy each term of the first line one by one
    {
        scanf("%d%lf", &n, &a);
        for (int j = 0; j < maxn; j++)
        {
            res[n + j] += a * co[j]; //合并同类项, 系数相乘，指数相加
        }
    }

    int count = 0;
    for (int i = 0; i < maxn; i++)
    {
        if (res[i] != 0.0)
            count++;
    }

    printf("%d", count);
    for (int i = maxn - 1; i >= 0; i--)
    {
        if (res[i] != 0.0)
            printf(" %d %.1f", i, res[i]);
    }

    return 0;
}