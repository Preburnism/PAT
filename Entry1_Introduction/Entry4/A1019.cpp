//General Palindromic Number
#include <stdio.h>

int main()
{
    int n, b;
    scanf("%d%d", &n, &b);
    int ans[31], count = 0;
    do
    {
        ans[count++] = n % b;
        n /= b;
    } while (n);

    int flag = 1;
    for (int i = 0; i <= count / 2; i++)
    {
        if (ans[i] != ans[count - 1 - i])
            flag = 0;
    }
    if (flag == 0)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", ans[i]);
        if (i != 0)
            printf(" ");
    }

    return 0;
}