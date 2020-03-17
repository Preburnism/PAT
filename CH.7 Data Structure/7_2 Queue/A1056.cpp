//Mice and Rice
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;
queue<int> q;

struct mr
{
    int weight;
    int r;
} mice[maxn];

int main()
{
    int np, ng;
    scanf("%d%d", &np, &ng);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &mice[i].weight);
    }

    int order;
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &order);
        q.push(order);
    }

    int temp = np, gp = 0;
    while (q.size() != 1)
    {
        if (temp % ng != 0)
            gp = temp / ng + 1;
        else
            gp = temp / ng;

        for (int i = 0; i < gp; i++)
        {
            int maxorder = q.front();

            for (int j = 0; j < ng; j++)
            {
                if (i * ng + j >= temp)
                    break;
                int frt = q.front();
                if (mice[frt].weight > mice[maxorder].weight)
                {
                    maxorder = frt;
                }
                mice[frt].r = gp + 1;
                q.pop();
            }
            q.push(maxorder);
        }
        temp = gp;
    }
    mice[q.front()].r = 1;

    for (int i = 0; i < np; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", mice[i].r);
    }

    return 0;
}