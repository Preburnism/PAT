#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    string s;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);

        int len = s.length();
        int pn = 0, tn = 0, others = 0;
        int ploc = 0, tloc = 0;
        for (int j = 0; j < len; j++)
        {
            if (s[j] == 'P')
            {
                pn++;
                ploc = j;
            }
            else if (s[j] == 'T')
            {
                tn++;
                tloc = j;
            }
            else if (s[j] != 'A')
            {
                others++;
            }
        }

        if (pn != 1 || tn != 1 || others > 0 || tloc - ploc <= 1) //P T 个数不为 1, 有其他字符, P左T右中间有字符
        {
            printf("NO\n");
            continue; 
        }

        int x = ploc, y = tloc - ploc - 1, z = len - tloc - 1;
        if (x * y == z)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}