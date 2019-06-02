#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int sum[maxn] = {0}; //m == sum[right]-sum[left-1]

int main()
{
    int n, m; //the amount that the customer has to pay
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) //sum[i]=d1+d2+……+di  递增
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }

    int ref = 100000010; //参照值
    int right;
    for (int i = 1; i <= n; i++) //遍历寻找参照值，等于m或者大于m且为最小的和
    {
        right = lower_bound(sum + i, sum + n + 1, m + sum[i - 1]) - sum; //大于等于m的值的下标
        if (sum[right] - sum[i - 1] == m)
        {
            ref = m;
            break;
        }
        else if (sum[right] - sum[i - 1] > m && sum[right] - sum[i - 1] < ref) //按题意取最小的ref
        {
            ref = sum[right] - sum[i - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        right = lower_bound(sum + i, sum + n + 1, m + sum[i - 1]) - sum; //大于等于m的值的下标
        if (sum[right] - sum[i - 1] == ref)
        {
            printf("%d-%d\n", i, right);
        }
    }

    return 0;
}