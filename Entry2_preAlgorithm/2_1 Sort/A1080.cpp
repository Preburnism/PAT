#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct application
{
    int id;
    int ge, gi;
    int fg;    //final grade
    int ps[6]; //preferred school
    int rank;
} stu[40005];

struct school
{
    int quota;
    int ad_num;        //admitted number
    int ad_stu[40005]; //id of student;
    int last_ad;
} gs[105];

int n, m, k;

bool cmp(application a, application b)
{
    if (a.fg != b.fg)
        return a.fg > b.fg;
    else
        return a.ge > b.ge;
}

bool scmp(int a, int b)
{
    return a < b;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &gs[i].quota);
        gs[i].ad_num = 0;
        gs[i].last_ad = -1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        stu[i].fg = stu[i].ge + stu[i].gi;
        stu[i].id = i;

        for (int j = 0; j < k; j++)
        {
            scanf("%d", &stu[i].ps[j]);
        }
    }

    sort(stu, stu + n, cmp);

    for (int i = 0; i < n; i++) //排名
    {
        if (i > 0 && stu[i].fg == stu[i - 1].fg && stu[i].ge == stu[i - 1].ge)
            stu[i].rank = stu[i - 1].rank;
        else
            stu[i].rank = i;
    }

    for (int i = 0; i < n; i++) //第i个学生
    {
        for (int j = 0; j < k; j++) //第j个志愿
        {
            int sid = stu[i].ps[j];                                                                                    //school id
            if (gs[sid].ad_num < gs[sid].quota || (gs[sid].last_ad != -1 && stu[gs[sid].last_ad].rank == stu[i].rank)) //排名相同则进入
            {
                gs[sid].ad_stu[gs[sid].ad_num] = stu[i].id; //记录招收的学生
                gs[sid].ad_num++;                           //该校人数+1
                gs[sid].last_ad = stu[i].id;                //最后一名是i

                break;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (gs[i].ad_num > 0)
        {
            sort(gs[i].ad_stu, gs[i].ad_stu + gs[i].ad_num, scmp);
            for (int j = 0; j < gs[i].ad_num; j++)
            {
                if (j != 0)
                    printf(" ");
                printf("%d", gs[i].ad_stu[j]);
            }
        }
        printf("\n");
    }

    return 0;
}