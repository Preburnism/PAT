//Dating
#include <cstdio>
#include <cstring>

bool first(char a, char b) //is Capital, A-G
{
    if (a == b && a >= 'A' && a <= 'G')
        return true;
    else
        return false;
}
int second(char a, char b) //0-9, A-N
{
    if (a == b)
    {
        if (a >= '0' && a <= '9')
            return 1;
        else if (a >= 'A' && a <= 'N')
            return 2;
        else
            return -1;
    }
    else
        return -1;
}
bool third(char a, char b) //just common is enough
{
    if (a == b)
    {
        if (a >= 'a' && a <= 'z')
            return true;
        else if (a >= 'A' && a <= 'Z')
            return true;
        else
            return false;
    }
    else
        return false;
}
char match1[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
//char match2[]

int main()
{
    char str[4][65];
    for (int i = 0; i < 4; i++)
    {
        scanf("%s", str[i]);
    }
    int len0 = strlen(str[0]);
    int len1 = strlen(str[1]);
    int len2 = strlen(str[2]);
    int len3 = strlen(str[3]);

    int curr = 0;
    for (int i = 0; i < len0 && i < len1; i++)
    {
        if (first(str[0][i], str[1][i]))
        {
            printf("%s ", match1[str[0][i] - 'A']);
            curr = i;
            break;
        }
    }
    for (int i = curr + 1; i < len0 && i < len1; i++)
    {
        if (second(str[0][i], str[1][i]) == 1) //is 0-9
        {
            printf("%02d:", str[0][i] - '0');
            break;
        }
        else if (second(str[0][i], str[1][i]) == 2) //is A-N
        {
            printf("%02d:", str[0][i] - 'A' + 10);
            break;
        }
    }
    for (int i = 0; i < len2 && i < len3; i++)
    {
        if (third(str[2][i], str[3][i]))
        {
            printf("%02d", i);
        }
    }

    return 0;
}