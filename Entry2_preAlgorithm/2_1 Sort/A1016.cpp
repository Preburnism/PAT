#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct record
{
    char name[25];
    int mo, dd, hh, mi; //mm:dd:hh:mm
    bool state;         //true: on-line or false: off-line
    int time;           //the lasting time (in minute)
    int id = -1;        //classify diffirent ones
} bill[1005], temp;

int toll[25]; //cents/minute
bool cmp(record a, record b)
{
    int s = strcmp(a.name, b.name); //返回值 < 0，则表示 str1 小于 str2
    if (s != 0)
        return s < 0;
    else if (a.mo != b.mo)
        return a.mo < b.mo;
    else if (a.dd != b.dd)
        return a.dd < b.dd;
    else if (a.hh != b.hh)
        return a.hh < b.hh;
    else
        return a.mi < b.mi;
}

void print(int on, int off, int &time, int &price)
{
    printf("%02d:%02d:%02d ", bill[on].dd, bill[on].hh, bill[on].mi);
    printf("%02d:%02d:%02d ", bill[off].dd, bill[off].hh, bill[off].mi);

    temp = bill[on];

    while (temp.dd < bill[off].dd || temp.hh < bill[off].hh || temp.mi < bill[off].mi)
    {
        time++;
        price += toll[temp.hh];
        temp.mi++;
        if (temp.mi >= 60)
        {
            temp.mi = 0;
            temp.hh++;
        }
        if (temp.hh >= 24)
        {
            temp.hh = 0;
            temp.dd++;
        }
    }
}

int main()
{
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", &toll[i]);
    }

    int n;
    scanf("%d", &n);
    char status[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d:%d ", &bill[i].name, &bill[i].mo, &bill[i].dd, &bill[i].hh, &bill[i].mi);

        scanf("%s", &status);
        if (strcmp(status, "on-line") == 0)
            bill[i].state = true;
        else if (strcmp(status, "off-line") == 0)
            bill[i].state = false;
    }

    sort(bill, bill + n, cmp);

    //"It is guaranteed that at least one call is well paired in the input.
    //"并没有保证每个用户都匹配成功，只是说所有用户中至少有一对是符合题意的。这很关键

    int on = 0, next, off; //next为一段落，on-off连续匹配
    while (on < n)
    {
        int np = 0; //needprint
        next = on;
        while (next < n && strcmp(bill[on].name, bill[next].name) == 0)
        {
            if (np == 0 && bill[next].state == true)
                np = 1;
            else if (np == 1 && bill[next].state == false)
                np = 2;
            next++;
        }
        if (np < 2)
        {
            on = next;
            continue;
        }

        printf("%s %02d\n", bill[on].name, bill[on].mo);
        int allPrice = 0;

        while (on < next)
        {
            while (on < next - 1 && !(bill[on].state == true && bill[on + 1].state == false))
            {
                on++;
            }

            off = on + 1;
            if (off == next) //输出完该成员所有配对的on-off
            {
                on = next;
                break;
            }
            int time = 0, price = 0;
            print(on, off, time, price); //输出函数
            allPrice += price;
            printf("%d $%.2f\n", time, price / 100.0);

            on = off + 1;
        }
        printf("Total amount: $%.2f\n", allPrice / 100.0);
    }

    return 0;
}