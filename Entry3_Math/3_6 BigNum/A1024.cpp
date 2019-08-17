//Palindromic Number
#include <cstdio>
#include <cstring>

struct bign
{
    int d[100];
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
    }
    return a;
}

bign add(bign a)
{
    bign b;
    int carry = 0;
    b.len = a.len;
    for (int i = 0; i < a.len; i++)
    {
        b.d[i] = (a.d[i] + a.d[a.len - i - 1] + carry) % 10;
        carry = (a.d[i] + a.d[a.len - i - 1] + carry) / 10;
    }
    if (carry == 1)
    {
        b.d[a.len] = 1;
        b.len++;
    }
    return b;
}

bool isPal(bign a)
{
    for (int i = 0; i < a.len / 2; i++)
    {
        if (a.d[i] != a.d[a.len - i - 1])
            return false;
    }
    return true;
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
    char str[12];
    int k;
    scanf("%s%d", str, &k);
    bign a = change(str);

    int step = 0;
    while (step < k && !isPal(a))
    {
        a = add(a);
        step++;
    }

    show(a);
    printf("\n%d", step);

    return 0;
}