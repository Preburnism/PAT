//Colors in Mars
#include <cstdio>

char toMarsNum(int n)
{
    switch (n % 9)
    {
    case 1:
        return 'A';
        break;

    case 2:
        return 'B';
        break;
    case 3:
        return 'C';
        break;
    default:
        break;
    }
}

int main()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    int m[6];
    for (int i = 0; i < 2; i++)
    {
        m[i + 4] = r % 13;
        r /= 13;
        m[i + 2] = g % 13;
        g /= 13;
        m[i] = b % 13;
        b /= 13;
    }
    printf("#");
    for (int i = 5; i >= 0; i--)
    {
        if (m[i] > 9)
            printf("%c", toMarsNum(m[i]));
        else
            printf("%d", m[i]);
    }

    return 0;
}