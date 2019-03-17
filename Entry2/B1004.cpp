#include <stdio.h>

struct stu
{
    char name[15];
    char id[15];
    int score;
} a, max, min;

int main()
{
    int n;
    scanf("%d", &n);
    max.score = 0;
    min.score = 100;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%d", &a.name, &a.id, &a.score);
        if (a.score >= max.score)
            max = a;
        if (a.score <= min.score)
            min = a;
    }
    printf("%s %s\n%s %s", max.name, max.id, min.name, min.id);

    return 0;
}