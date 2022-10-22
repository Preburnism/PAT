#include <cstdio>
#include <cstring>

char pron[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}; //不能用'',''仅用于包围字符

int main()
{
    char num[105];
    scanf("%s", num);
    int len = strlen(num);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        int add = num[i] - '0';
        sum += add;
    }
    int change[4] = {0}, count = 0;
    while (sum)
    {
        change[count] = sum % 10;
        sum /= 10;
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%s", pron[change[i]]);
        if (i != 0)
            printf(" ");
    }

    return 0;
}