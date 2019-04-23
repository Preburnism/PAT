#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct people
{
    char name[10];
    int age;
    int worth;
} rp[100005];

bool cmp(people a, people b)
{
    if (a.worth != b.worth)
        return a.worth > b.worth;
    else if (a.age != b.age)
        return a.age < b.age;
    else
        return strcmp(a.name, b.name) < 0;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", &rp[i].name, &rp[i].age, &rp[i].worth);
    }

    sort(rp, rp + n, cmp);

    for (int i = 0; i < k; i++)
    {
        int m, min, max;
        scanf("%d%d%d", &m, &min, &max);

        printf("Case #%d:\n", i + 1);

        int num = 0, count = 0;
        while (num < n)
        {

            if (count < m && rp[num].age >= min && rp[num].age <= max)
            {
                printf("%s %d %d\n", rp[num].name, rp[num].age, rp[num].worth);
                count++;
            }

            if (count == m)
                break;
            num++;
        }
        if (count == 0)
            printf("None\n");
    }

    return 0;
}