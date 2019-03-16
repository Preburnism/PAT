//	A+B for Polynomials
#include <stdio.h>

int main()
{
    int k, n; //n:exponent, a:coefficient;
    double a;
    int num = 2;             //two lines input;
    double co[1005] = {0.0}; //co[n] stores the coefficient of the exponent n;
    int count = 0;           //the result k;

    while (num--)
    {
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d%lf", &n, &a);
            //不能在输入的过程中直接计算结果k项，要考虑各项相加为0的情况
            /*
            if (co[n] == 0.0)
                count++; //count  when input at first time;
            */
            co[n] += a;
        }
    }
    for (int i = 0; i <= 1000; i++) //0 <= N <= 1000
    {
        if (co[i] != 0)
            count++;
    }

    printf("%d", count);
    for (int i = 1000; i >= 0; i--)
    {
        if (co[i] != 0.0)
            printf(" %d %.1f", i, co[i]);
    }

    return 0;
}