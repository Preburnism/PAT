#include <stdio.h>

struct people
{
    char name[16];
    int yy, mm, dd;
} a, old, young, left, right;

bool moreEqual(people a, people b) //出生日期大即年龄小
{
    if (a.yy != b.yy)
        return a.yy >= b.yy;
    else if (a.mm != b.mm)
        return a.mm >= b.mm;
    else
        return a.dd >= b.dd;
}

bool lessEqual(people a, people b) //出生日期小即年龄大
{
    if (a.yy != b.yy)
        return a.yy <= b.yy;
    else if (a.mm != b.mm)
        return a.mm <= b.mm;
    else
        return a.dd <= b.dd;
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0; //有效个数

    left.yy = 1814;
    left.mm = 9;
    left.dd = 6;
    right.yy = 2014;
    right.mm = 9;
    right.dd = 6;
    old = right;
    young = left;

    for (int i = 0; i < n; i++)
    {
        scanf("%s%d/%d/%d", &a.name, &a.yy, &a.mm, &a.dd);
        if (lessEqual(a, right) && moreEqual(a, left))
        {
            count++;
            if (moreEqual(a, young))
                young = a;
            if (lessEqual(a, old))
                old = a;
        }
    }
    if (count == 0)
        printf("0");
    else
        printf("%d %s %s", count, old.name, young.name);

    return 0;
}