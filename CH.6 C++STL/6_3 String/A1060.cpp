//Are They Equal
//1. 用例： 00.00xxx,0.1234, 0011234, 1234.56, 统一格式成 0.xxx*10^e
//2. 去0 => 若有小数点确定小数点位置，去小数点同时确定指数 e =>  根据有效位数把 s 中的字符赋值给 res
#include <iostream>
#include <string>
using namespace std;

int n;
string deal(string s, int &e)
{
    int k = 0;
    while (s[0] == '0') //000xxx  000.000xxx
        s.erase(s.begin());
    if (s[0] == '.') //0.xxx
    {
        s.erase(s.begin());
        while (s.length() > 0 && s[0] == '0') // 0.00xxx, e指数为负
        {
            s.erase(s.begin());
            e--;
        }
    }
    else //xxx.xxx
    {
        while (k < s.length() && s[k] != '.') // 12345.678
        {
            k++;
            e++;
        }
        if (k < s.length())
        {
            s.erase(s.begin() + k);
        }
    }

    if (s.length() == 0) //排除 0 的干扰
        e = 0;

    k = 0;
    string res;
    for (int i = 0; i < n; i++) //按 n 的值赋值给res
    {
        if (k < s.length())
            res += s[k++];
        else
            res += '0'; //1234.56 => 12345600*10^-4
    }
    return res;
}
int main()
{
    string a, b;
    cin >> n >> a >> b;
    int e1 = 0, e2 = 0;
    a = deal(a, e1);
    b = deal(b, e2);

    if (a == b && e1 == e2)
        cout << "YES 0." << a << "*10^" << e1 << endl;
    else
        cout << "NO 0." << a << "*10^" << e1 << " 0." << b << "*10^" << e2 << endl;

    return 0;
}