#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct testee
{
    int id;
    int score;
    int s[6];
    int sp = 0; //perfect submission
    bool isValid = false;
} stu[10005];

int p[5];
int n, k, m;

bool cmp(testee a, testee b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else if (a.sp != b.sp)
        return a.sp > b.sp;
    else
        return a.id < b.id;
}

void init()
{
    for (int i = 1; i <= n; i++) //1-n
    {
        stu[i].id = i; //id=i;
        stu[i].score = 0;
        stu[i].sp = 0;
        stu[i].isValid = false;
        memset(stu[i].s, -1, sizeof(stu[i].s));
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);

    init();

    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int id, num, score;
        scanf("%d %d %d", &id, &num, &score);

        if (score != -1)
            stu[id].isValid = true;

        if (score == -1 && stu[id].s[num] == -1) //该题-1记为0
            stu[id].s[num] = 0;

        if (stu[id].s[num] < score)
            stu[id].s[num] = score;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (stu[i].s[j] != -1)
                stu[i].score += stu[i].s[j]; //计算总成绩

            if (stu[i].s[j] == p[j]) //计算perfect submission
                stu[i].sp++;
        }
    }

    sort(stu + 1, stu + n + 1, cmp);

    int r = 1;
    for (int i = 1; i <= n && stu[i].isValid == true; i++)
    {
        if (i > 1 && stu[i].score != stu[i - 1].score)
            r = i;

        printf("%d %05d %d ", r, stu[i].id, stu[i].score);
        for (int j = 1; j <= k; j++)
        {
            if (j != 1)
                printf(" ");
            if (stu[i].s[j] != -1)
                printf("%d", stu[i].s[j]);
            else
                printf("-");
        }
        printf("\n");
    }

    return 0;
}