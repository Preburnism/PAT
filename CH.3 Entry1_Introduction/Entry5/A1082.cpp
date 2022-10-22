//yi  er  san  si  wu  liu  qi  ba  jiu
#include <cstdio>
#include <cstring>

char match[10][6] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    char num[11];
    scanf("%s", num);

    int len = strlen(num);
    if (num[0] == '-')
    {
        printf("Fu ");
        for (int i = 0; i < len - 1; i++)
        {
            num[i] = num[i + 1];
        }
        len -= 1;
    }

    if (num[0] == '0') //特判输入0，测试点3
    {
        printf("ling");
    }

    for (int i = 0; i < len; i++)
    {
        while (num[i] == '0')
        {
            if (len - i == 5)
            {
                if (!(len == 9 && num[i - 1] == '0' && num[i - 2] == '0' && num[i - 3] == '0'))
                    printf(" Wan");
            }
            if (num[i + 1] == '0' || num[i + 1] == '\0')
                i++;
            else
                break;
            if (i >= len)
                break;
        }
        if (i >= len)
            break;

        if (i != 0)
            printf(" ");
        printf("%s", match[num[i] - '0']);

        if (num[i] != '0')
        {
            if (len - i == 9)
                printf(" Yi");
            if ((len - 1 - i) % 4 == 3)
                printf(" Qian");
            else if ((len - 1 - i) % 4 == 2)
                printf(" Bai");
            else if ((len - 1 - i) % 4 == 1)
                printf(" Shi");
            if (len - i == 5)
                printf(" Wan");
        }
    }

    return 0;
}
