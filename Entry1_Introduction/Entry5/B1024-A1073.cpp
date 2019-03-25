//Scientific Notation, 指数<小数部分长度, 指数>小数部分长度
#include <cstdio>
#include <cstring>

int main()
{
    char s[10005];
    scanf("%s", s);
    if (s[0] == '-')
        printf("-");

    int len = strlen(s);
    int pos = 0;
    while (s[pos] != 'E') //pos is the position of E
    {
        pos++;
    }

    int exp = 0;
    for (int i = pos + 2; i < len; i++) //calculate exponent
    {
        exp *= 10;
        exp += s[i] - '0';
    }

    if (s[pos + 1] == '-')
    {
        for (int i = 0; i < exp; i++)
        {
            if (i == 1)
                printf(".");
            printf("0");
        }
        for (int i = 1; i < pos; i++)
        {
            if (i != 2)
                printf("%c", s[i]);
        }
    }

    if (s[pos + 1] == '+')
    {
        for (int i = 1; i < pos; i++)
        {
            if (i - 3 == exp) //小数点移动的相对位置==指数
                printf(".");
            if (i != 2)
                printf("%c", s[i]);
        }
        for (int i = 0; i < exp - (pos - 3); i++)
        {
            printf("0");
        }
    }

    return 0;
}