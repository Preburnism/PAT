#include <cstdio>
#include <algorithm>
using namespace std;

int hash[1005] = {0};

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int val;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        hash[val]++;
    }

    int v1 = -1;
    for (int i = 1; i <= m / 2; i++)
    {
        if (hash[i] && hash[m - i])
        {
            if (i != m - i || (i == m - i && hash[i] >= 2))
            {
                v1 = i;
                break;
            }
        }
    }

    if (v1 == -1)
        printf("No Solution");
    else
        printf("%d %d", v1, m - v1);

    return 0;
}