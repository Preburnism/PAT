#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn], op[maxn], left[maxn], right[maxn];

int main()
{
    int n;
    scanf("%d", &n);

    int cnt = 0;

    left[0] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i != 0)
            left[i] = max(left[i - 1], a[i - 1]);
    }
    right[n - 1] = 0x7fffffff;

    if (left[n - 1] < a[n - 1])
        op[cnt++] = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = min(right[i + 1], a[i + 1]);
        if (left[i] < a[i] && right[i] > a[i])
            op[cnt++] = a[i];
    }

    printf("%d\n", cnt);
    for (int i = cnt - 1; i >= 0; i--)
    {
        if (i != cnt - 1)
            printf(" ");
        printf("%d", op[i]);
    }
    printf("\n");

    return 0;
}