#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student
{
    char name[11];
    char id[11];
    int grade;
} rec[110];

bool cmp(student a, student b)
{
    return a.grade > b.grade;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", &rec[i].name, &rec[i].id, &rec[i].grade);
    }

    sort(rec, rec + n, cmp);

    int lg, rg; //left,right
    scanf("%d%d", &lg, &rg);

    int pos = 0;
    bool isprint = false;
    while (pos < n) //pos增大，grade减小,on-off上下边界
    {
        if (rec[pos].grade <= rg && rec[pos].grade >= lg)
        {
            isprint = true;

            printf("%s %s\n", rec[pos].name, rec[pos].id);
            pos++;
        }
        else if (rec[pos].grade >= rg)
        {
            pos++;
        }
        else
            break;
    }

    if (!isprint)
        printf("NONE");

    return 0;
}