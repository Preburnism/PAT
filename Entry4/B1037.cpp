#include <stdio.h>

long long toKnut(int g, int s, int k) //10^7*17*19 > 4*10^9 > int范围;
{
    return g * 17 * 29 + s * 29 + k;
}

int main()
{
    int g, s, k;
    scanf("%d.%d.%d", &g, &s, &k);
    long long p = toKnut(g, s, k);
    scanf("%d.%d.%d", &g, &s, &k);
    long long a = toKnut(g, s, k);

    long long res = a - p;
    if (res < 0)
    {
        printf("-");
        res = -res; //abs(res)
    }

    printf("%lld.%lld.%lld", res / 17 / 29, res / 29 % 17, res % 29);

    return 0;
}