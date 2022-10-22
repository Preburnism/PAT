#include <cstdio>
#include <cmath>

bool isPrime(int a)
{
    if (a == 1)
        return false;
    int sqr = sqrt(a * 1.0);
    for (int i = 2; i <= sqr; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int reverse(int n, int r)
{
    int d[110];
    int len = 0;
    do //除基取余
    {
        d[len++] = n % r;
        n /= r;
    } while (n != 0);
    for (int i = 0; i < len; i++)//逆序并转十进制
    {
        n = n * r + d[i];
    }
    return n;
}
int main()
{
    int n, d;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 0)
            break;
        scanf("%d", &d);

        if (!isPrime(n))
        {
            printf("No\n");
            continue;
        }
        int rev_n = reverse(n, d);
        if (isPrime(rev_n))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}