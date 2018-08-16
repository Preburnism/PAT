#include <stdio.h>
#include <algorithm>
using namespace std;

int num[4] = {0};

bool up(int a, int b)
{
    if (a != b)
        return a < b;
    else
        return a >= b;
}

bool down(int a, int b)
{
    if (a != b)
        return a > b;
    else
        return a <= b;
}

void toArray(int v)
{
    for (int i = 0; i < 4; i++)
    {
        num[i] = v % 10;
        v = v / 10;
    }
}

int toNum()
{
    int v = 0, times = 1;
    for (int i = 0; i < 4; i++)
    {
        v += num[i] * times;
        times *= 10;
    }
    return v;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans = n;
    do
    {
        toArray(ans);
        sort(num, num + 4, up); //sort()默认从小到大，up()可省略
        int a1 = toNum();
        sort(num, num + 4, down);
        int a2 = toNum();
        ans = a1 - a2;
        if (!ans)
        {
            printf("%d - %d = 0000\n", n, n);
            break;
        }
        printf("%.4d - %.4d = %.4d\n", a1, a2, ans);
    } while (ans != 6174);

    return 0;
}