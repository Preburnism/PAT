#include <cstdio>

const int inf = 0x7fffffff;
const int maxn = 200010;
int s1[maxn];

int main()
{
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 1; i <= n1; i++)
    {
        scanf("%d", &s1[i]);
    }

    scanf("%d", &n2);
    s1[n1 + 1] = inf;

    int medianpos = (n1 + n2 + 1) / 2;
    int i = 1, count = 0;

    int s2_in;
    for (int j = 1; j <= n2; j++)
    {
        scanf("%d", &s2_in);

        while (s1[i] < s2_in)
        {
            count++; //i++ ——> count++
            if (count == medianpos)
            {
                printf("%d", s1[i]);
            }
            i++;
        }
        count++; //j++ ——> count++
        if (count == medianpos)
            printf("%d", s2_in);
    }
    while (i <= n1) //中间数在s1中
    {
        count++;                //i++ ——> count++
        if (count == medianpos) //数到中间位置
            printf("%d", s1[i]);
        i++;
    }

    return 0;
}