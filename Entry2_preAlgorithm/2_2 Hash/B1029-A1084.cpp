#include <cstdio>
#include <cstring>

int main()
{
    char s1[90], s2[90];
    scanf("%s%s", &s1, &s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    bool hashtable[128] = {false};
    for (int i = 0; i < len1; i++)
    {
        int index = s1[i] - '\0';
        for (int j = 0; j < len2; j++)
        {
            if (s1[i] == s2[j])
            {
                hashtable[index] = true;
                break;
            }
        }
    }

    for (int i = 0; i < len1; i++)
    {
        int index = s1[i] - '\0';
        if (hashtable[index] == false)
        {
            if (s1[i] >= 'a' && s1[i] <= 'z')
            {
                printf("%c", s1[i] - ('a' - 'A'));     //输出大写字母
                hashtable[index - ('a' - 'A')] = true; //大写字母的hash为true
            }
            else if (s1[i] >= 'A' && s1[i] <= 'Z')
            {
                hashtable[index + ('a' - 'A')] = true; //小写字母的hash为true
                printf("%c", s1[i]);
            }
            else
                printf("%c", s1[i]);

            hashtable[index] = true;
        }
    }

    return 0;
}