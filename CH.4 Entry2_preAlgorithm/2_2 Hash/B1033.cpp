#include <cstdio>
#include <cstring>

int main()
{
    char broken[100005], input[100005];

    //scanf("%s%s", broken, input);
    //scanf读入不了'\n'
    fgets(broken, sizeof(broken), stdin);
    int len1 = strlen(broken);
    broken[len1 - 1] = '\0';
    bool hash[256];
    memset(hash, true, sizeof(hash));

    for (int i = 0; i < len1; i++)
    {
        int index = broken[i] - '\0';
        hash[index] = false;
        if (broken[i] >= 'A' && broken[i] <= 'Z')
            hash[index + ('a' - 'A')] = false;
    }

    fgets(input, sizeof(input), stdin);
    int len2 = strlen(input);
    input[len2 - 1] = '\0';
    for (int i = 0; i < len2; i++)
    {
        if (hash[input[i]])
        {
            if (hash['+'] || (!hash['+'] && (input[i] < 'A' || input[i] > 'Z')))
                printf("%c", input[i]);
        }
    }
    printf("\n");

    return 0;
}