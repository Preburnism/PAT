#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool hash[4700];//最大值为4616

void calla(int a)
{
    if (a == 1)
        return;
    if (a % 2 == 0)
    {
        calla(a / 2);
        a /= 2;
    }
    else
    {
        calla((a * 3 + 1) / 2);
        a = (a * 3 + 1) / 2;
    }
    hash[a] = true;
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int k;
    scanf("%d", &k);

    memset(hash, false, sizeof(hash));
    int arr[105];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
        calla(arr[i]);
    }

    sort(arr, arr + k, cmp);
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        if (!hash[arr[i]])
        {
            if (num)
                printf(" ");
            else
                num++;
            printf("%d", arr[i]);
        }
    }

    return 0;
}