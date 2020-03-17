//Sharing
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 100010;

struct Node
{
    int ad, next;
    char data;
    int order = maxn;
} node1[maxn], node2[maxn];

bool cmp(Node a, Node b)
{
    return a.order < b.order;
}

int main()
{
    int start1, start2, n;
    scanf("%d%d%d", &start1, &start2, &n);

    for (int i = 0; i < n; i++)
    {
        int add, next;
        char c;
        scanf("%d%*c%c%d", &add, &c, &next);
        node1[add].ad = add;
        node1[add].data = c;
        node1[add].next = next;

        node2[add].ad = add;
        node2[add].data = c;
        node2[add].next = next;
    }

    int now = start1;
    int count1 = 0, count2 = 0;
    set<int> ns;
    while (now != -1)
    {
        ns.insert(now);
        now = node1[now].next;
    }

    now = start2;
    while (now != -1)
    {
        if (ns.find(now) != ns.end())
        {
            printf("%05d", now);
            break;
        }
        now = node2[now].next;
    }

    if (now == -1)
        printf("-1");

    return 0;
}