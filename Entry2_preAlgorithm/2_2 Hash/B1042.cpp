#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int hash[128] = {0};
    int len = s.length();

    int maxn = 0;
    char maxc;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(s[i]))
        {
            char c = tolower(s[i]);
            hash[c]++;
            if (maxn < hash[c] || (maxn == hash[c] && maxc > c))
            {
                maxn = hash[c];
                maxc = c;
            }
        }
    }
    printf("%c %d", maxc, maxn);

    return 0;
}