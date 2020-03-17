//Deduplication on a Linked List
//注意 无效结点 ，即结点不在给出的链表内
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int maxn = 100010;
struct Node
{
    int add, value, next;
    int order = maxn * 2;
} node[maxn];

bool cmp(Node a, Node b)
{
    return a.order < b.order;
}

int main()
{
    int start, n;
    scanf("%d%d", &start, &n);
    for (int i = 0; i < n; i++)
    {
        int add, val, next;
        scanf("%d%d%d", &add, &val, &next);
        node[add].add = add;
        node[add].value = val;
        node[add].next = next;
    }

    set<int> ns;
    int validNum = 0, removedNum = maxn;
    int now = start;
    while (now != -1)
    {
        if (ns.find(abs(node[now].value)) != ns.end())
        {
            node[now].order = removedNum++;
            now = node[now].next;
        }
        else
        {
            node[now].order = validNum++;
            ns.insert(abs(node[now].value));
            now = node[now].next;
        }
    }

    sort(node, node + maxn, cmp);

    for (int i = 0; i < validNum; i++)
    {
        if (i == validNum - 1)
            printf("%05d %d -1\n", node[i].add, node[i].value);
        else
            printf("%05d %d %05d\n", node[i].add, node[i].value, node[i + 1].add);
    }

    for (int i = 0; i < removedNum - maxn; i++)
    {
        if (i == removedNum - maxn - 1)
            printf("%05d %d -1\n", node[i + validNum].add, node[i + validNum].value);
        else
            printf("%05d %d %05d\n", node[i + validNum].add, node[i + validNum].value, node[i + validNum + 1].add);
    }
    

    if (n > validNum + removedNum)
    {
        for (int i = validNum + removedNum; i < n; i++)
        {
            if (node[i].next != -1)
                printf("%05d %d %05d\n", node[i].add, node[i].value, node[i].next);
            else
                printf("%05d %d -1\n", node[i].add, node[i].value);
        }
    }

    return 0;
}