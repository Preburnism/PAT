//given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
#include <stdio.h>
#include <algorithm>
using namespace std; //algorithm的函数需要std

const int MAXN = 100010;
int d_atob[MAXN], d_ajt[MAXN]; //adjacent distance
int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d_ajt[i]);
        sum += d_ajt[i];
        d_atob[i] = sum; //d_atob[i] is the distance from 1 to i+1, so the distance, a to b, is d_atob[b-1] - d_atob[a-1]
    }

    int m;
    scanf("%d", &m);
    int a, b;
    for (int j = 0; j < m; j++) //m次查询
    {
        scanf("%d%d", &a, &b);
        int d1 = 0;
        if (a > b)
            swap(a, b);
        /*
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        */
        /*m次查询遍历数组，极限情况，10000次 x 100000次数组操作 = 10^9次，结果超时
        for (int i = a; i < b; i++)
        {
            d1 += d[i];
        }
        */
        d1 = d_atob[b - 1] - d_atob[a - 1];
        d1 <= sum - d1 ? printf("%d\n", d1) : printf("%d\n", sum - d1);
    }
    return 0;
}