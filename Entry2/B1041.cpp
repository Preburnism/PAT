#include <stdio.h>

const int maxn = 1005;
struct stu
{
    long long id;
    int t_seat; //试机座位
    int e_seat; //考试座位
} d[maxn];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%d%d", &d[i].id, &d[i].t_seat, &d[i].e_seat);
    }
    scanf("%d", &m);
    int s;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &s);
        for (int j = 0; j < n; j++)
        {
            if (s == d[j].t_seat)
            {
                printf("%lld %d\n", d[j].id, d[j].e_seat);
            }
        }
    }

    return 0;
}