//Linked List Sorting
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node
{
    int ad, key = maxn, next;
    bool isvalide = false;
} node[maxn];

bool cmp(Node a, Node b)
{
    return a.key < b.key;
}

int main()
{
    int n, head;
    scanf("%d%d", &n, &head);

    for (int i = 0; i < n; i++)
    {
        int add;
        scanf("%d", &add);
        node[add].ad = add;

        scanf("%d%d", &node[add].key, &node[add].next);
    }
    int now = head, cnt = 0; //cnt: 有效结点个数
    while (now != -1)
    {
        node[now].isvalide = true;
        now = node[now].next;
        cnt++;
    }
    sort(node, node + maxn, cmp);

    if (cnt == 0)
        printf("0 -1\n");
    else
    {
        printf("%d ", cnt);

        int temp = cnt;
        for (int i = 0; i < n; i++)
        {
            while (!node[i].isvalide) //存在不在链表中的无效结点
            {
                i++;
            }
            if (i >= n)
                break;
            printf("%05d\n", node[i].ad); //各结点末尾next，初始行head可理解为 null->next

            printf("%05d %d ", node[i].ad, node[i].key);

            temp--;
            if (temp == 0)
                printf("-1\n"); //最后结点的next=NULL
        }
    }

    return 0;
}