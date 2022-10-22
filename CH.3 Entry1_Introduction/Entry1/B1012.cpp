#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int k;
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    double a4 = 0.0;
    int flag1 = 0, flag2 = 0, pflag = 1, flag3 = 0, flag4 = 0, count4 = 0, flag5 = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        // 能被 5 整除的数字中所有偶数的和；
        if (k % 10 == 0)
        {
            flag1 = 1;
            a1 += k;
        }
        //将被 5 除后余 1 的数字按给出顺序进行交错求和
        else if (k % 5 == 1)
        {
            flag2 = 1;
            a2 += k * pflag;
            pflag = -pflag; //flag=~flag+1;//正整数按位取反+1
        }
        //被 5 除后余 2 的数字的个数
        else if (k % 5 == 2)
        {
            flag3 = 1;
            a3 += 1;
        }
        //被 5 除后余 3 的数字的平均数，精确到小数点后 1 位
        else if (k % 5 == 3)
        {
            flag4 = 1;
            a4 += k;
            count4 += 1;
        }
        //被 5 除后余 4 的数字中最大数字
        else if (k % 5 == 4)
        {
            flag5 = 1;
            if (a5 <= k)
            {
                a5 = k;
            }
        }
    }

    flag1 ? printf("%d ", a1) : printf("N ");
    flag2 ? printf("%d ", a2) : printf("N ");
    flag3 ? printf("%d ", a3) : printf("N ");
    flag4 ? printf("%.1f ", a4/count4) : printf("N ");
    flag5 ? printf("%d", a5) : printf("N");

    return 0;
}