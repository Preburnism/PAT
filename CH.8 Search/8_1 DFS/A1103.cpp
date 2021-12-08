//Integer Factorization
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 410;
int N, K, P;     //k个因子的p次幂，和为n;
int maxsum = -1; //取因子之和最大的一组,若相同则逐个比较因子大小取最大一个;
vector<int> ans, temp;
int arr[maxn];

bool cmp(vector<int> a, vector<int> b)
{
    int len = a.size();
    for (int i = 0; i < len; i++)
    {
        if (a[i] > b[i])
            return true;
    }
    return false;
}

int power(int x)
{
    int val = 1;
    for (int i = 0; i < P; i++)
    {
        val *= x;
    }
    return val;
}

void DFS(int index, int selnum, int sum_of_KP, int sum_of_factors) //下标，已选数，条件1，筛选条件
{
    if (sum_of_KP == N && selnum == K) //因子的幂和为N且已选因子个数为K时，进行比较筛选;
    {
        if (sum_of_factors > maxsum) //比较因子之和大小;
        {
            ans = temp;
            maxsum = sum_of_factors;
        }
        else if (sum_of_factors == maxsum) //因子之和相等的情况逐个比较;
        {
            if (cmp(temp, ans))
                ans = temp;
        }
        return;
    }

    if (sum_of_KP > N || selnum > K) //超限返回;
        return;

    if (index + 1 <= arr[0])
    {
        temp.push_back(arr[index]);
        DFS(index, selnum + 1, sum_of_KP + power(arr[index]), sum_of_factors + arr[index]); //复选index,叠加自身幂，如2^2+2^2;
        temp.pop_back();

        DFS(index + 1, selnum, sum_of_KP, sum_of_factors); //不选自身的分支
    }
}

int main()
{
    scanf("%d%d%d", &N, &K, &P);
    arr[0] = pow(N, 1.0 / P) + 1;
    for (int i = 1; i < arr[0]; i++)
    {
        arr[i] = arr[i - 1] - 1;
    }

    DFS(0, 0, 0, 0);

    if (maxsum == -1)
        printf("Impossible");
    else
    {
        printf("%d = %d^%d", N, ans[0], P);
        for (int i = 1; i < ans.size(); i++)
        {
            printf(" + %d^%d", ans[i], P);
        }
    }
    return 0;
}