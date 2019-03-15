//Given three integers A, B and C in [−2^​63​,2^​63], you are supposed to tell whether A+B>C.
#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        long long res = a + b; //result=正整数相加溢出后区间为[-2^63,-2], 负整数相加溢出后区间为[0,2^63);
        if (a > 0 && b > 0 && res <= -2)
        {
            //a+b正溢出，即a+b>c;
            printf("Case #%d: true\n", i);
        }
        else if (a < 0 && b < 0 && res >= 0)
        {
            //a+b负溢出，即a+b<c;
            printf("Case #%d: false\n", i);
        }
        else
        {
            //未溢出，直接相加判断a+b?c
            a + b > c ? printf("Case #%d: true\n", i) : printf("Case #%d: false\n", i);
        }
    }
    return 0;
}