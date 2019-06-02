#include <cstdio>
#include <cstdlib>

const int maxn = 110;
int f[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    f[0] = 0;

    int cost_time = 0, utime;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
        f[i] > f[i - 1] ? utime = 6 : utime = 4;
        cost_time += abs(f[i] - f[i - 1]) * utime + 5;
    }

    printf("%d", cost_time);

    return 0;
}