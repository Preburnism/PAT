#include <stdio.h>
using namespace std;

int main()
{
    int n, step = 0;
    scanf("%d", &n);
    while (n != 1)
    {
        if (n % 2)
        {
            n = 3 * n + 1;
            n /= 2;
        }
        else
        {
            n /= 2;
        }
        step++;
    }
    printf("%d\n", step);

    return 0;
}