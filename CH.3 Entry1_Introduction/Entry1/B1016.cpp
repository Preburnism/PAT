#include <stdio.h>
using namespace std;

int main()
{
    long long a, b, pa = 0, pb = 0;
    int da, db;
    scanf("%lld%d%lld%d", &a, &da, &b, &db);
    while (a)
    {
        if (a % 10 == da)
        {
            pa = pa * 10 + da;
        }
        a /= 10;
    }
    while (b)
    {
        if (b % 10 == db)
        {
            pb = pb * 10 + db;
        }
        b /= 10;
    }
    printf("%lld\n", pa + pb);

    return 0;
}