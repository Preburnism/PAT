// World Cup Betting
#include <stdio.h>

int main()
{
    char wol[3] = {'W', 'T', 'L'};
    double a[3], res = 1, temp;
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        temp = 0.0;
        scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
        for (int j = 0; j < 3; j++)
        {
            if (a[j] >= temp)
            {
                temp = a[j];
                index = j;
            }
        }
        res *= a[index];

        printf("%c ", wol[index]);
    }
    res = (res * 0.65 - 1) * 2;
    printf("%.2f", res);

    return 0;
}