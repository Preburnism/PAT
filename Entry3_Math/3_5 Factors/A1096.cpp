//Consecutive Factors
#include <cstdio>
#include <cmath>
typedef long long ll;

int main()
{
    ll n;
    scanf("%lld", &n);
    ll sqr = (ll)sqrt(1.0 * n);

    int start = 0;
    int flen = 0;
    for (int i = 2; i <= sqr; i++) //i, j 表示 factor
    {
        ll temp = 1;
        for (int j = i; j < n; j++)
        {
            temp *= j;
            if (n % temp != 0)
                break;
            if (flen < j - i + 1)
            {
                flen = j - i + 1;
                start = i;
            }
        }
    }

    if (flen == 0)
        printf("1\n%lld", n);
    else
    {
        printf("%d\n", flen);
        for (int i = 0; i < flen; i++) //i 表示输出顺序
        {
            if (i != 0)
                printf("*");
            printf("%d", i + start);
        }
    }

    return 0;
}