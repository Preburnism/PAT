//计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。
#include <cstdio>
#include <cstring>

struct bign
{
    int d[1010]; //高位放末尾
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign divide(bign a, int b, int &r) //a: divident; b: divisor; c: quotient; r: redundant;
{
    bign c;
    c.len = a.len;
    for (int i = c.len - 1; i >= 0; i--)
    {
        r = r * 10 + a.d[i];
        if (r < b)
            c.d[i] = 0;
        else
        {
            c.d[i] = r / b;
            r %= b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) //去除商首位的 0
        c.len--;

    return c;
}
bign change(char s[])
{
    bign a;
    a.len = strlen(s);
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = s[a.len - i - 1] - '0';
    }
    return a;
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
    char str[1010];
    int b, rdt = 0;
    scanf("%s%d", str, &b);

    bign a = change(str);
    bign ans = divide(a, b, rdt);
    show(ans);
    printf(" %d", rdt);

    return 0;
}