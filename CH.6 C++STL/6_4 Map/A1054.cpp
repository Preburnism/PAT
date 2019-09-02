// The Dominant Color
#include <cstdio>
#include <map>
using namespace std;

map<int, int> color;

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int pix;
    for (int i = 0; i < m * n; i++)
    {
        scanf("%d", &pix);
        if (color.find(pix) != color.end())
            color[pix]++;
        else
            color[pix] = 1;
    }

    int maxn = 0;
    for (map<int, int>::iterator it = color.begin(); it != color.end(); it++)
    {
        if (maxn < it->second)
        {
            maxn = it->second;
            pix = it->first;
        }
    }

    printf("%d", pix);

    return 0;
}