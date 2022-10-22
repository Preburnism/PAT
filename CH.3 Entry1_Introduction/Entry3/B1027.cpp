//等差数列 an=a1+(n-1)d,和S=n(a1+an)/2;
#include <stdio.h>
#include <math.h>

int main()
{
    int n, c;
    scanf("%d %c", &n, &c);
    int x; //共2x-1行，多了n-((x^2-1)*2+1)个符号，第一行有2x-1个符号
    x = (int)sqrt(((double)n + 1) / 2);
    for (int i = 0; i < x; i++)
    {
        int m1 = i;                 //空格数
        int m2 = 2 * x - 1 - 2 * i; //字符数

        while (m1--)
        {
            printf(" ");
        }
        while (m2--)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    for (int i = 1; i < x; i++)
    {
        int m1 = x - (i + 1);
        int m2 = 1 + 2 * i;
        while (m1--)
        {
            printf(" ");
        }
        while (m2--)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    printf("%d", n - (x * x * 2 - 1));

    return 0;
}