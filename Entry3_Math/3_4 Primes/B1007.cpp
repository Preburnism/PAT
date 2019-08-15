#include <cstdio>
#include <cmath>

bool isPrime(int n)
{
    int sqr = sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 3; i <= n - 2; i += 2)
    {
        if (isPrime(i) && isPrime(i + 2))
            count++;
    }
    printf("%d", count);

    return 0;
}