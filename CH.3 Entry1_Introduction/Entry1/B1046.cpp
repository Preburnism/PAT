#include <stdio.h>
using namespace std;

int main()
{
    int n, lc1 = 0, lc2 = 0;
    scanf("%d", &n);
    while (n--)
    {
        int add1, ans1, add2, ans2;
        scanf("%d%d%d%d", &add1, &ans1, &add2, &ans2);
        if (ans1 != ans2)
        {
            if (add1 + add2 == ans1)
                lc2 += 1;
            else if (add1 + add2 == ans2)
                lc1 += 1;
        }
    }
    printf("%d %d", lc1, lc2);

    return 0;
}