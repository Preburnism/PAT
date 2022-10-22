//Rational Sum
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Fra
{
    ll up = 0;   //numerator
    ll down = 1; //denominator
} temp, res;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void simplify()
{
    if (res.up == 0) //分子为0，分母设为1
        res.down = 1;
    else
    {
        int d = gcd(abs(res.up), abs(res.down));
        res.up /= d;
        res.down /= d;
    }
}

void add()
{
    res.up = res.up * temp.down + temp.up * res.down;
    res.down = temp.down * res.down;
    simplify();
}

void showRes()
{
    if (res.down == 1) //simplify()中已将分子为0的分数分母设为1，无需讨论分子为1的情况（并入分母为1的情况）
        printf("%lld\n", res.up);
    else if (abs(res.up) > res.down)
        printf("%lld %lld/%lld\n", res.up / res.down, abs(res.up) % res.down, res.down);
    else
        printf("%lld/%lld\n", res.up, res.down);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &temp.up, &temp.down);
        add();
    }

    showRes();
    return 0;
}