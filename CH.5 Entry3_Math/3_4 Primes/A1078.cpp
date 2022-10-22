#include <cstdio>
#include <cmath>

const int maxn = 10010;
bool h[maxn];

bool isPrime(int a)
{
    if (a <= 1)
        return false;
    int sqr = sqrt(a * 1.0);
    for (int i = 2; i <= sqr; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int toPrime(int a)
{
    while (!isPrime(a))
    {
        a++;
    }
    return a;
}

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        h[i] = false;
    }
}

int main()
{
    init();
    int msize, n;
    scanf("%d%d", &msize, &n);

    msize = toPrime(msize);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);

        k = k % msize;

        if (i != 0)
            printf(" ");
        if (h[k])
        {
            //Quadratic probing (with positive increments only) is used to solve the collisions.
            int step = 1;
            while (step < msize && h[(k + step * step) % msize])
                step++;
            if (step == msize)
                printf("-");
            else
            {
                printf("%d", (k + step * step) % msize);
                h[(k + step * step) % msize] = true;
            }
        }
        else
        {
            printf("%d", k);
            h[k] = true;
        }
    }

    return 0;
}