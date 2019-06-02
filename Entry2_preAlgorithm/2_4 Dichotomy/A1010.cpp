#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Map[256];
long long inf = (1LL << 63) - 1;

void init() //只有35个字符并不代表最大只有36进制!!!!!!!
{
    for (char i = '0'; i <= '9'; i++)
    {
        Map[i] = i - '0';
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        Map[i] = i - 'a' + 10;
    }
}

long long toDecimal(char c[], long long r)
{
    int len = strlen(c);
    long long res = 0;
    for (int i = 0; i < len; i++)
    {
        res = res * r + Map[c[i]];
        if (res < 0) //溢出
            return -1;
    }

    return res;
}

long long BinarySearch(char c[], long long left, long long right, long long ref)
{
    long long mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        long long val = toDecimal(c, mid);
        if (val == ref)
            return mid;
        else if (val > ref || val == -1) //d2大于d1 或 d2溢出（即大于d1），左区间寻找
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1; //无解
}

int main()
{
    init();

    char d1[11], d2[11];
    scanf("%s", d1);
    scanf("%s", d2);

    int tag, roftag;
    scanf("%d%d", &tag, &roftag);

    if (tag == 2)
    {
        char temp[11];
        strcpy(temp, d1);
        strcpy(d1, d2);
        strcpy(d2, temp);
    }

    long long ref = toDecimal(d1, roftag);

    char obj[11];
    strcpy(obj, d2);
    int olen = strlen(obj);
    sort(obj, obj + olen);

    long long minbase = Map[obj[olen - 1]] + 1; //找到最小基数
    long long maxbase = max(minbase, ref) + 1;

    long long index = BinarySearch(d2, minbase, maxbase, ref);

    if (index == -1)
        printf("Impossible");
    else
        printf("%d", index);

    return 0;
}