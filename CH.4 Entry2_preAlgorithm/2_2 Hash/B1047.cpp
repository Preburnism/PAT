#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int hash[1005] = {0};
    int maxg = 0;
    for (int i = 0; i < n; i++)
    {
        int gid, mid, score;
        scanf("%d-%d %d", &gid, &mid, &score);
        hash[gid] += score;
        if (hash[maxg] < hash[gid])
            maxg = gid;
    }

    printf("%d %d", maxg, hash[maxg]);

    return 0;
}