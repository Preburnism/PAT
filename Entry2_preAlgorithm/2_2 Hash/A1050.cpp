#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        if (s2.find(s1[i]) == string::npos)
            printf("%c", s1[i]);
    }

    return 0;
}