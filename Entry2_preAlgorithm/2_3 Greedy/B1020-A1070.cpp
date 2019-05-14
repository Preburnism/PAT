#include <cstdio>
#include <algorithm>
using namespace std;

struct moon
{
    double amt;
    double p, up; //unit price
} product[1005];

bool cmp(moon a, moon b)
{
    return a.up > b.up;
}

int main()
{
    int n;
    double d;
    scanf("%d %lf", &n, &d);

    double res_p = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &product[i].amt);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &product[i].p);
        product[i].up = product[i].p / product[i].amt;
    }

    sort(product, product + n, cmp);

    int now = 0;
    while (d > 0 && now < n)
    {
        if (d > product[now].amt)
            res_p += product[now].p;
        else
            res_p += product[now].p / product[now].amt * d;

        d -= product[now].amt;
        now++;
    }
    printf("%.2f", res_p);

    return 0;
}