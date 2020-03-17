//Reversing Linked List
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node
{
    int add, data, next;
    int order = maxn;
} node[maxn];

bool cmp(Node a, Node b)
{
    return a.order < b.order;
}

int main()
{
    int add1, n, k;
    scanf("%d%d%d", &add1, &n, &k);
    for (int i = 0; i < n; i++)
    {
        int ad;
        scanf("%d", &ad);
        scanf("%d%d", &node[ad].data, &node[ad].next);
        node[ad].add = ad;
    }

    int now = add1, count = 0;
    while (now != -1)
    {
        node[now].order = count++;
        now = node[now].next;
    }

    sort(node, node + maxn, cmp);

    int group, ncnt = count;
    group = count / k;
    for (int i = 0; i < group; i++) //进行reverse的组别
    {
        for (int j = k - 1; j >= 0; j--)
        {
            if (count == 1) //最后一个node的next为 -1
                printf("%05d %d -1\n", node[i * k + j].add, node[i * k + j].data);
            else
            {
                if (j != 0)
                    printf("%05d %d %05d\n", node[i * k + j].add, node[i * k + j].data, node[i * k + j - 1].add);
                else //每组最后一个
                {
                    if (ncnt % k && i == group - 1) //遍历到reverse组的最后一组，next是下一不完全组（最后一组）的第一个数
                        printf("%05d %d %05d\n", node[i * k + j].add, node[i * k + j].data, node[group * k].add);
                    else //next是下一组的末尾node
                        printf("%05d %d %05d\n", node[i * k + j].add, node[i * k + j].data, node[(i + 1) * k + k - 1].add);
                }
            }
            count--;
        }
    }
    if (count) //不进行 reverse 的 node
    {
        for (int i = group * k; i < group * k + count - 1; i++)
        {
            printf("%05d %d %05d\n", node[i].add, node[i].data, node[i + 1].add);
        }
        printf("%05d %d -1\n", node[ncnt - 1].add, node[ncnt - 1].data);
    }

    return 0;
}