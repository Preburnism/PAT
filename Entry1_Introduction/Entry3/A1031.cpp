//Hello World for U
#include <stdio.h>
#include <cstring>

int main()
{
    char str[85];
    fgets(str, 85, stdin);
    int len = strlen(str) - 1;
    int n1, n2;
    n1 = (len + 2) / 3;
    n2 = len + 2 - n1 - n1;
    for (int i = 0; i < n1 - 1; i++) //i-1行
    {
        printf("%c", str[i]);
        for (int j = 1; j < n2 - 1; j++) //j-2列
        {
            printf(" ");
        }
        printf("%c\n", str[len - 1 - i]);
    }
    for (int i = 0; i < n2; i++)
    {
        printf("%c", str[n1 - 1 + i]);
    }
    return 0;
}