#include <cstdio>

int main()
{
    int n;
    int ans = 0, base = 1;
    scanf("%d", &n);

    int left, right, now; //当前位置左右两侧
    while (n / base != 0)
    {
        left = n / (base * 10);
        right = n % base;
        now = n / base % 10;

        if (now == 0)
            ans += left * base;
        else if (now == 1)
            ans += left * base + right + 1;
        else
            ans += (left + 1) * base;

        base *= 10;
    }
    printf("%d", ans);
    return 0;
}