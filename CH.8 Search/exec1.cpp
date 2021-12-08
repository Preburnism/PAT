#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 10010;
int arr[maxn];
int k, n, tar, maxSqr = -1; //从n个数内选出k个和为tar的数,取sqr最大的;
vector<int> temp, ans;

void DFS(int index, int selnum, int sum, int sumSqr)
{
    if (selnum == k && sum == tar)
    {
        if (sumSqr > maxSqr)
        {
            maxSqr = sumSqr;
            ans = temp;
        }
        return;
    }

    if (index == n || selnum > k || sum > tar) //DFS到达底部条件：界限（共n个数），限制条件1，限制条件2
        return;

    temp.push_back(arr[index]);
    DFS(index + 1, selnum + 1, sum + arr[index], sumSqr + arr[index] * arr[index]);
    temp.pop_back();

    DFS(index + 1, selnum, sum, sumSqr);
}

int main()
{
    scanf("%d%d%d", &n, &k, &tar);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    DFS(0, 0, 0, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}