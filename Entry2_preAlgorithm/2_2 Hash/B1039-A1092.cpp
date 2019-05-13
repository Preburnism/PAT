#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string shop, eva;
    getline(cin, shop);
    getline(cin, eva);

    int own[128];
    memset(own, 0, sizeof(own));

    int lens = shop.length();
    int lene = eva.length();

    for (int i = 0; i < lens; i++)
    {
        own[shop[i]]++;
    }

    int miss = 0;
    for (int i = 0; i < lene; i++)
    {
        own[eva[i]]--;
        if (own[eva[i]] < 0)
            miss++;
    }

    if (miss > 0)
        printf("No %d", miss);
    else
        printf("Yes %d", lens - lene);

    return 0;
}