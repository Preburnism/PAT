#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct car
{
    char pn[8];
    int hh, mm, ss;
    int time;
    char state[4];
} all[10005], valid[10005];

bool cmp(car a, car b)
{
    if (strcmp(a.pn, b.pn))
        return strcmp(a.pn, b.pn) < 0;
    else
        return a.time < b.time;
}

bool tcmp(car a, car b)
{
    return a.time < b.time;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %s", &all[i].pn, &all[i].hh, &all[i].mm, &all[i].ss, &all[i].state);
        all[i].time = all[i].hh * 3600 + all[i].mm * 60 + all[i].ss;
    }

    map<string, int> ptime;
    int maxTime = 0;

    sort(all, all + n, cmp);
    int now = 0, valnum = 0;
    while (now < n - 1) //筛选出合理的数据对
    {
        if (strcmp(all[now].pn, all[now + 1].pn) == 0)
        {
            if (strcmp(all[now].state, "in") == 0 && strcmp(all[now + 1].state, "out") == 0)
            {
                valid[valnum++] = all[now++];
                valid[valnum++] = all[now];

                int t = all[now].time - all[now - 1].time;
                if (ptime.count(all[now].pn) == 0)
                {
                    ptime.insert(make_pair(all[now].pn, t));
                }
                else
                {
                    ptime[all[now].pn] += t;
                }
                maxTime = max(maxTime, ptime[all[now].pn]);
            }
        }
        now++;
    }

    sort(valid, valid + valnum, tcmp); //按时间排序
    //start query
    int curr = 0;
    int carnum = 0;
    for (int i = 0; i < k; i++)
    {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int currtime = h * 3600 + m * 60 + s;

        for (int j = curr; j < valnum; j++)
        {
            if (currtime < valid[j].time)
            {
                curr = j;
                break;
            }

            if (!strcmp(valid[j].state, "in"))
                carnum++;

            else
                carnum--;
        }
        printf("%d\n", carnum);
    }

    map<string, int>::iterator it;
    for (it = ptime.begin(); it != ptime.end(); it++)
    {
        if (it->second == maxTime)
            printf("%s ", it->first.c_str());
    }

    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);

    return 0;
}