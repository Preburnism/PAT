#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string s[10010];

bool cmp(string a, string b)
{
    return a + b < b + a;
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    sort(s, s + n, cmp);

    string str;
    for (int i = 0; i < n; i++)
    {
        str += s[i];
    }

    while (str[0] == '0' && str.length() > 1) //删除后确保有元素存在
    {
        str.erase(str.begin());
    }
    cout << str;

    return 0;
}