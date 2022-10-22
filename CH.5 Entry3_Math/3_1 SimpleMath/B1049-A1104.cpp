#include <cstdio>

const int maxn = 100010;
double a[maxn];

int main()
{
    int n;
    scanf("%d", &n);

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a[i]);
        sum += a[i] * (n - i) * (i + 1);
    }

    printf("%.2f", sum);

    return 0;
}