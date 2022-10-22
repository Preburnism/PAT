#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int sum = a + b;
    if (sum < 0)
    {
        printf("-");
        sum = -sum;
    }

    string s = to_string(sum);
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (len % 3 == i % 3 && i != 0)
            printf(",");
        printf("%c", s[i]);
    }

    return 0;
}