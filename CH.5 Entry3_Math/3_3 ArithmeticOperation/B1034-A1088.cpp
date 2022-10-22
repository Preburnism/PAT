//Rational Arithmetic
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Fra
{
    ll up, down;
} res;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
Fra simplify(Fra f)
{
    if (f.down < 0) //分母为负，互取相反数
    {
        f.down = -f.down;
        f.up = -f.up;
    }
    if (f.up == 0)
        f.down = 1;
    else
    {
        int d = gcd(abs(f.up), abs(f.down));
        f.up /= d;
        f.down /= d;
    }
    return f;
}
void add(Fra a, Fra b)
{
    res.up = a.up * b.down + b.up * a.down;
    res.down = a.down * b.down;
    res = simplify(res);
}
void minus(Fra a, Fra b)
{
    res.up = a.up * b.down - b.up * a.down;
    res.down = a.down * b.down;
    res = simplify(res);
}
void multiple(Fra a, Fra b)
{
    res.up = a.up * b.up;
    res.down = a.down * b.down;
    res = simplify(res);
}
void divide(Fra a, Fra b)
{
    res.up = a.up * b.down;
    res.down = a.down * b.up;
    res = simplify(res);
}

void print1(Fra f)
{
    if (f.up < 0)
        printf("(");

    if (f.down == 1)
        printf("%lld", f.up);
    else if (abs(f.up) > f.down)
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    else
        printf("%lld/%lld", f.up, f.down);

    if (f.up < 0)
        printf(")");
}
void print2()
{
    if (res.up < 0)
        printf("(");

    if (res.down == 0)
    {
        printf("Inf\n");
        return;
    }
    if (res.down == 1)
        printf("%lld", res.up);
    else if (abs(res.up) > res.down)
        printf("%lld %lld/%lld", res.up / res.down, abs(res.up) % res.down, res.down);
    else
        printf("%lld/%lld", res.up, res.down);

    if (res.up < 0)
        printf(")");

    printf("\n");
}

int main()
{
    Fra f1, f2;
    scanf("%lld/%lld", &f1.up, &f1.down);
    scanf("%lld/%lld", &f2.up, &f2.down);
    f1 = simplify(f1);
    f2 = simplify(f2);

    add(f1, f2);
    print1(f1);
    printf(" + ");
    print1(f2);
    printf(" = ");
    print2();

    minus(f1, f2);
    print1(f1);
    printf(" - ");
    print1(f2);
    printf(" = ");
    print2();

    multiple(f1, f2);
    print1(f1);
    printf(" * ");
    print1(f2);
    printf(" = ");
    print2();

    divide(f1, f2);
    print1(f1);
    printf(" / ");
    print1(f2);
    printf(" = ");
    print2();

    return 0;
}