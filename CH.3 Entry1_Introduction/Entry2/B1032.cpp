#include <stdio.h>

const int maxn = 100005;
int score[maxn] = {0};

int main()
{
    int n;
    scanf("%d", &n);

    int id, s, top = 0;
    score[top] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &id, &s);
        score[id] += s;
        if (score[id] >= score[top])
        {
            top = id;
        }
    }

    printf("%d %d", top, score[top]);

    return 0;
}