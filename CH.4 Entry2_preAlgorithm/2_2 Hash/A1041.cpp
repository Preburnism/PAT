#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int hash[10005] = {0};
    int a[100005];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        hash[a[i]]++;
    }

    int i;
    for (i = 0; i < n; i++)
    {
        if (hash[a[i]] == 1)
            break;
    }

    if (i != n)
        printf("%d", a[i]);
    else
        printf("None");

    return 0;
}