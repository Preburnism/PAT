//Sign In and Sign Out
#include <stdio.h>

struct sign
{
    char id[16];
    int ihh, imm, iss;
    int ohh, omm, oss;
} first, last, temp;

void init()
{
    first.ihh = 24;
    first.imm = 60;
    first.iss = 60;

    last.ohh = 0;
    last.omm = 0;
    last.oss = 0;
}

bool earlier(sign a, sign b)
{
    if (a.ihh != b.ihh)
        return a.ihh <= b.ihh;
    else if (a.imm != b.imm)
        return a.imm <= b.imm;
    else
        return a.iss <= b.iss;
}

bool later(sign a, sign b)
{
    if (a.ohh != b.ohh)
        return a.ohh >= b.ohh;
    else if (a.omm != b.omm)
        return a.omm >= b.omm;
    else
        return a.oss >= b.oss;
}

int main()
{
    init(); //initiate first and last;

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", &temp.id, &temp.ihh, &temp.imm, &temp.iss, &temp.ohh, &temp.omm, &temp.oss);
        if (earlier(temp, first))
            first = temp;
        if (later(temp, last))
            last = temp;
    }

    printf("%s %s", first.id, last.id);

    return 0;
}