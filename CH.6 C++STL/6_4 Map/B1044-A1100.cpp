//Mars Numbers
#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;

string lowdigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highdigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> strToNum;
string numToStr[170];

void init()
{
    for (int i = 0; i < 13; i++) //0-12, 13*n
    {
        numToStr[i] = lowdigit[i];
        strToNum[lowdigit[i]] = i;

        numToStr[i * 13] = highdigit[i];
        strToNum[highdigit[i]] = i * 13;
    }
    for (int i = 1; i < 13; i++)
    {
        for (int j = 1; j < 13; j++)
        {
            string s = highdigit[i] + " " + lowdigit[j];
            numToStr[i * 13 + j] = s;
            strToNum[s] = i * 13 + j;
        }
    }
}

int main()
{
    init();

    int n;
    scanf("%d%*c", &n); //"*"表示该输入项读入后不赋予任何变量，即跳过该输入值，等效于 getchar()
    string s;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        if (s[0] >= '0' && s[0] <= '9')
        {
            int num = stoi(s);
            printf("%s\n", numToStr[num].c_str());
        }
        else
        {
            printf("%d\n", strToNum[s]);
        }
    }

    return 0;
}