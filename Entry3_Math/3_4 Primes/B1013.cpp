#include <cstdio>
#include <cmath>

bool isPrime(int a)
{
    int sqr = sqrt(a * 1.0);
    for (int i = 2; i <= sqr; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int p[10005];

int main()
{
    int m1, m2;
    scanf("%d%d", &m1, &m2);

    int count = 2;
    int pr = 3;
    p[1] = 2;
    while (count <= m2)
    {
        if (isPrime(pr))
            p[count++] = pr;
        pr += 2;
    }

    for (int i = 0; i <= m2 - m1; i++)
    {
        if (i != 0)
            i % 10 == 0 ? printf("\n") : printf(" ");
        printf("%d", p[i + m1]);
    }

    return 0;
}