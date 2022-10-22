//Have Fun with Numbers
#include <cstdio>
#include <cstring>

int hash1[11] = {0};
int hash2[11] = {0};

struct bign
{
    int d[30];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char s[])
{
    bign a;
    a.len = strlen(s);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = s[a.len - i - 1] - '0';
        hash1[a.d[i]]++; //统计各位数出现次数
    }
    return a;
}

bign add(bign a)
{
    int carry = 0;
    bign b;
    for (int i = 0; i < a.len; i++)
    {
        b.d[i] = (a.d[i] + a.d[i] + carry) % 10;
        carry = (a.d[i] + a.d[i] + carry) / 10;

        hash2[b.d[i]]++;
    }
    if (carry == 1)
    {
        b.d[a.len] = 1;
        b.len = a.len + 1;

        hash2[1]++;
    }
    else
        b.len = a.len;

    return b;
}

void show(bign a)
{
    for (int i = a.len - 1; i >= 0; i--)
    {
        printf("%d", a.d[i]);
    }
}

int main()
{
    char str[30];
    scanf("%s", str);
    bign num = change(str);

    bign ans = add(num);
    int pos = 0;
    while (hash1[pos] == hash2[pos] && pos <= 9)
    {
        pos++;
    }
    pos < 10 ? printf("No\n") : printf("Yes\n");

    show(ans);

    return 0;
}