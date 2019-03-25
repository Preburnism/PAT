//replace 1 (one) by @, 0 (zero) by %, l by L, and O by o
#include <cstdio>
#include <cstring>

int main()
{
    int N;
    scanf("%d", &N);

    char name[1005][11], pw[1005][11];
    bool flag[1005] = {false};
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%s%s", name[i], pw[i]);

        int len = strlen(pw[i]);
        for (int j = 0; j < len; j++)
        {
            switch (pw[i][j])
            {
            case '1':
                pw[i][j] = '@';
                flag[i] = true;
                break;
            case '0':
                pw[i][j] = '%';
                flag[i] = true;
                break;
            case 'l':
                pw[i][j] = 'L';
                flag[i] = true;
                break;
            case 'O':
                pw[i][j] = 'o';
                flag[i] = true;
                break;
            default:
                break;
            }
        }
        if (flag[i])
            count++;
    }
    if (count == 0)
    {
        if (N == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified", N);
    }
    else
    {
        printf("%d\n", count);
        for (int i = 0; i < N; i++)
        {
            if (flag[i] == true)
            {
                printf("%s %s\n", name[i], pw[i]);
            }
        }
    }

    return 0;
}