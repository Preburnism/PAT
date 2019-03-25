#include <stdio.h>
using namespace std;

int main()
{
    int t, tcase = 1;
    long long a, b, c;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c)
        {
            printf("Case #%d: true\n", tcase++);
        }
        else
        {
            printf("Case #%d: false\n", tcase++);
        }
    }

    return 0;
}