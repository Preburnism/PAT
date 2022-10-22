#include <stdio.h>

int main()
{
    int co, ex, a[1005] = {0}; //coefficient,exponent
    while (scanf("%d%d", &co, &ex) != EOF)
    {
        a[ex] = co; //指数为ex的项系数为co;
    }
    a[0] = 0;
    int count = 0;
    for (int i = 1; i <= 1000; i++)
    {
        a[i - 1] = a[i] * i; //对指数为i的项求导，指数-1变为第i-1项，系数为原第i项系数a[i] x i;
        a[i] = 0;            //对指数为i的项当前系数置为0(i=1000的情况下，nx^1000求导为1000nx^999，初始化时a[1000]=co，此时需ex为1000的项a[1000]置0),
                             //若不置0，则在输出时选择从指数为999的项开始输出
        if (a[i - 1] != 0)
            count++; //统计导数不为0的项数
    }

    if (count == 0)
        printf("0 0");
    else
    {
        for (int i = 1000; i >= 0; i--)
        {
            if (a[i] != 0)
            {
                printf("%d %d", a[i], i);
                count--;
                if (count)
                    printf(" ");
            }
        }
    }

    return 0;
}