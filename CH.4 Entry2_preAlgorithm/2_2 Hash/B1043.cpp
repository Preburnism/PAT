#include <cstdio>
#include <cstring>

int main()
{
    char s[10005];
    int hash[128] = {0};
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        hash[s[i]]++;
    }

    char p[6] = {'P', 'A', 'T', 'e', 's', 't'};
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        index %= 6;
        while (index < 6 && !hash[p[index]])
        {
            index++;
        }
        if (index != 6)
        {
            printf("%c", p[index]);
            hash[p[index]]--;
            index++;
        }
    }

    return 0;
}