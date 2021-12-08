#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1000;
struct sum
{
    int a, b;
    int sq, s;
} temp;
vector<sum> xy, ab;
void init()
{
    for (int i = 1; i < maxn; i++)
    {
        for (int j = i; j < maxn; j++)
        {
            temp.a = i;
            temp.b = j;
            temp.sq = i * i + j * j;
            temp.s = i + j;
            xy.push_back(temp);
            ab.push_back(temp);
        }
    }
}
int main()
{
    init();
    for (int i = 0; i < xy.size(); i++)
    {
        for (int j = 0; j < ab.size(); j++)
        {
            if (xy[i].a != ab[j].a && xy[i].b != ab[j].b && xy[i].sq == ab[j].sq && xy[i].s == ab[j].s)
                printf("%d %d %d %d\n", xy[i].a, xy[i].b, ab[j].a, ab[j].b);
        }
    }
    return 0;
}