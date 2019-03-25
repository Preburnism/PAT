#include <stdio.h>

int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int r;
    if (n % 2)
        r = n / 2 + 1;
    else
        r = n / 2;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == r - 1)
                printf("%c", c);
            else if (j == 0 || j == n - 1)
                printf("%c", c);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}