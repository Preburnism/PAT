#include <cctype> //toupper,tolower,大小写转换，否则返回原值
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string broken, s;
    getline(cin, broken);
    getline(cin, s);

    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (broken.find(toupper(s[i])) != string::npos) //键位损坏无法输出
            continue;
        if (isupper(s[i]) && broken.find('+') != string::npos) //shift坏掉无法输出大写
            continue;
        printf("%c", s[i]);
    }

    return 0;
}