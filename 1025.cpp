#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct testee //registration_number, final_rank, location_number, local_rank
{
    char id[15];
    int score;
    int frank;
    int group;
    int lrank;
} t[30000];

bool cmp(testee t1, testee t2)
{
    if (t1.score != t2.score)
        return t1.score > t2.score; //从大到小排序
    else
        return strcmp(t1.id, t2.id) < 0; //若t1.id < t2.id, strcmp结果为负, 返回true
}

int main()
{
    int N, K;
    int count = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &K);
        testee ttemp[300];
        int j;
        for (j = 0; j < K; j++)
        {
            scanf("%s%d", ttemp[j].id, &ttemp[j].score);
            ttemp[j].group = i + 1;
        }
        sort(ttemp, ttemp + j, cmp);

        ttemp[0].lrank = 1;
        t[count++] = ttemp[0];

        for (j = 1; j < K; j++)
        {
            //即 ttemp[j].lrank = (ttemp[j].score == ttemp[j - 1].score) ? (ttemp[j].lrank = ttemp[j - 1].lrank) : (ttemp[j].lrank = j + 1);
            if (ttemp[j].score == ttemp[j - 1].score)
                ttemp[j].lrank = ttemp[j - 1].lrank;
            else
                ttemp[j].lrank = j + 1;
            t[count++] = ttemp[j];
        }
    }

    sort(t, t + count, cmp);
    t[0].frank = 1;
    printf("%d\n%s %d %d %d\n", count, t[0].id, t[0].frank, t[0].group, t[0].lrank);
    for (int i = 1; i < count; i++)
    {
        if (t[i].score == t[i - 1].score)
            t[i].frank = t[i - 1].frank;
        else
            t[i].frank = i + 1;
        printf("%s %d %d %d\n", t[i].id, t[i].frank, t[i].group, t[i].lrank);
    }

    system("pause");
    return 0;
}