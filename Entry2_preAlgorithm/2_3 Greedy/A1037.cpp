#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
long long cp_positive[maxn], cp_negative[maxn];
long long pd_positive[maxn], pd_negative[maxn];

bool pcmp(int a, int b)
{
    return a > b;
}
bool ncmp(int a, int b)
{
    return a < b;
}

int main()
{
    int nc; // the number of coupons
    scanf("%d", &nc);

    long long num;        //input
    int cpp = 0, cpn = 0; //number
    for (int i = 0; i < nc; i++)
    {
        scanf("%lld", &num);
        num >= 0 ? cp_positive[cpp++] = num : cp_negative[cpn++] = num;
    }

    int np; // the number of products
    scanf("%d", &np);
    int pdp = 0, pdn = 0;
    for (int i = 0; i < np; i++)
    {
        scanf("%lld", &num);
        num >= 0 ? pd_positive[pdp++] = num : pd_negative[pdn++] = num;
    }
    sort(cp_positive, cp_positive + cpp, pcmp);
    sort(cp_negative, cp_negative + cpn, ncmp);

    sort(pd_positive, pd_positive + pdp, pcmp);
    sort(pd_negative, pd_negative + pdn, ncmp);

    long long sum = 0;
    for (int i = 0; i < cpp && i < pdp; i++)
    {
        sum += cp_positive[i] * pd_positive[i];
    }
    for (int i = 0; i < cpn && i < pdn; i++)
    {
        sum += cp_negative[i] * pd_negative[i];
    }

    printf("%lld", sum);

    return 0;
}