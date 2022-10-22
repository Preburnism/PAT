#include <cstdio>
#include <algorithm>
using namespace std;

struct grade
{
    int id;
    int grade[4]; //a,c,m,e;
} stu[2019];

int Rank[1000005][4] = {0}; //各科排名
int curr;                   //当前科目
char match[4] = {'A', 'C', 'M', 'E'};

bool cmp(grade a, grade b)
{
    return a.grade[curr] > b.grade[curr];
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
    }

    for (curr = 0; curr < 4; curr++) //分别对A C M E四科排名次
    {
        sort(stu, stu + N, cmp);
        Rank[stu[0].id][curr] = 1;
        for (int i = 1; i < N; i++)
        {
            if (stu[i].grade[curr] == stu[i - 1].grade[curr]) //若和上一名成绩相同则继承上一名名次
                Rank[stu[i].id][curr] = Rank[stu[i - 1].id][curr];
            else
                Rank[stu[i].id][curr] = i + 1;
        }
    }

    int query;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &query);
        if (Rank[query][0] == 0) //排名0,即不存在
        {
            printf("N/A\n");
        }
        else
        {
            int bSub = 0; //best subject;
            for (int j = 0; j < 4; j++)
            {
                if (Rank[query][j] < Rank[query][bSub])
                {
                    bSub = j;
                }
            }
            printf("%d %c\n", Rank[query][bSub], match[bSub]);
        }
    }

    return 0;
}