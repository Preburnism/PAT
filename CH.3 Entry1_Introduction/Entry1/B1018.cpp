//剪刀石头布
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    char p1, p2;
    int p1_win = 0, p1_lose = 0, p_draw = 0;
    int b1 = 0, c1 = 0, j1 = 0;
    int b2 = 0, c2 = 0, j2 = 0;
    for (int i = 0; i < n; i++)
    {
        getchar(); //记录输入的换行符
        scanf("%c %c", &p1, &p2);
        switch (p1 - p2)
        {
        case 0:
            p_draw += 1;
            break;
        case -1:
            p1_win += 1;
            b1 += 1;
            break;
        case -7:
            p1_win += 1;
            c1 += 1;
            break;
        case 8:
            p1_win += 1;
            j1 += 1;
            break;
        case 1:
            p1_lose += 1;
            b2 += 1;
            break;
        case 7:
            p1_lose += 1;
            c2 += 1;
            break;
        case -8:
            p1_lose += 1;
            j2 += 1;
            break;
        default:
            printf("illegal input!");
            return 0;
        }
    }

    printf("%d %d %d\n", p1_win, p_draw, p1_lose);
    printf("%d %d %d\n", p1_lose, p_draw, p1_win);
    if (b1 >= c1)
    {
        if (b1 >= j1)
            printf("B");
        else
            printf("J");
    }
    else
    {
        if (c1 >= j1)
            printf("C");
        else
            printf("J");
    }
    printf(" ");
    if (b2 >= c2)
    {
        if (b2 >= j2)
            printf("B");
        else
            printf("J");
    }
    else
    {
        if (c2 >= j2)
            printf("C");
        else
            printf("J");
    }

    return 0;
}