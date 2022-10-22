#include <cstdio>
#include <cstring>

void reverse(char a[])
{
    int len = strlen(a);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); //enter

    char s[260], temp[260];
    fgets(s, 260, stdin);

    strcpy(temp, s);
    reverse(temp);

    char res[260];

    for (int i = 1; i < n; i++)
    {
        char t[260];
        fgets(t, 260, stdin);

        reverse(t);

        int len1 = strlen(t);
        int len2 = strlen(temp);
        memset(res, '\0', sizeof(res));

        for (int j = 0; j < len1; j++)
        {
            if (t[j] != temp[j])
            {
                break;
            }
            if (t[j] == temp[j])
            {
                res[j] = temp[j];
            }
        }
        memset(temp, '\0', sizeof(temp));
        strcpy(temp, res);
    }

    reverse(res);
    char *a = strchr(res, '\n');
    if (a)
        *a = '\0';
    int len = strlen(res);
    if (len == 0)
    {
        printf("nai");
    }
    else
    {
        printf("%s", res);
    }

    return 0;
}