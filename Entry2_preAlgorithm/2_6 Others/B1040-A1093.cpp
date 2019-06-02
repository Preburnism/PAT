#include <stdio.h>
#include <string.h>

const int maxn = 100010;
const int mod = 1000000007;
char s[maxn];
int leftP[maxn] = {0};

int main()
{
    fgets(s, maxn, stdin); //最后输入的是\n
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        if (i > 0)
            leftP[i] = leftP[i - 1];
        if (s[i] == 'P')
            leftP[i]++;
    }

    int rightT = 0, ans = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == 'T')
            rightT++;
        else if (s[i] == 'A')
            ans = (leftP[i] * rightT + ans) % mod;
    }

    printf("%d", ans);

    return 0;
}