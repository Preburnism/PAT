#include <cstdio>

int main()
{
    char temp;
    int num[10] = {0};
    while ((scanf("%c", &temp)) != EOF)
    {
        num[temp - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (num[i])
        {
            printf("%d:%d\n", i, num[i]);
        }
    }

    return 0;
}