#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);

    int g[100005];
    memset(g, 0, sizeof(g));

    for (int i = 0; i < n; i++)
    {
        int score;
        scanf("%d", &score);
        g[score]++;
    }

    int k;
    scanf("%d", &k);
    int query[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &query[i]);
    }
    for (int i = 0; i < k; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", g[query[i]]);
    }

    return 0;
}