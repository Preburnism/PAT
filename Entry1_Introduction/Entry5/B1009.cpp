#include <cstdio>
#include <cstring>

int main()
{
    char str[81][81];
    int num = 0;
    while ((scanf("%s", str[num])) != EOF)
    {
        num++;
    }

    for (int i = num - 1; i >= 0; i--)
    {
        printf("%s", str[i]);
        if (i != 0)
            printf(" ");
    }

    return 0;
}