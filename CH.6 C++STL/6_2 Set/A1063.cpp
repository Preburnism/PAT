//Set Similarity
#include <cstdio>
#include <set>
using namespace std;

set<int> st[51];

void calculate(int a, int b)
{
    int totalNum = st[b].size(), sameNum = 0;
    for (set<int>::iterator it = st[a].begin(); it != st[a].end(); it++)
    {
        if (st[b].find(*it) != st[b].end())
            sameNum++;
        else
            totalNum++;
    }

    printf("%.1f%%\n", sameNum * 100.0 / totalNum);
}
int main()
{
    int n;
    int m, mnum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mnum);
            st[i].insert(mnum);
        }
    }
    int k;
    scanf("%d", &k);
    int a, b;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &a, &b);
        calculate(a - 1, b - 1);
    }

    return 0;
}