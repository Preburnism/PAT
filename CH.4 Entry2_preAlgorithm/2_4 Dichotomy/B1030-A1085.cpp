#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int arr[maxn];

int main()
{
    int n;
    int p; //parameter<=10^9
    scanf("%d%d", &n, &p);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n); //默认递增

    int maxlen = 1;
    for (int i = 0; i < n; i++)
    {
        int len = upper_bound(arr + i + 1, arr + n, (long long)arr[i] * p) - arr; //在arr[i+1]-arr[n-1]内二分查找，返回第一个大于乘积的地址，减去首地址即为下标
        len -= i;
        maxlen = max(maxlen, len);
    }

    printf("%d", maxlen);
    return 0;
}