#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
struct node
{
    int x, y;
} Node;

int m, n; //m*n
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false}; //是否已入过队
int X[4] = {0, 0, 1, -1};       //增量数组，+X +Y，(0,1),(0,-1),(1,0),(-1,0)
int Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) //判断(x,y)是否需要入队
{
    if (x >= m || y >= n || x < 0 || y < 0) //出界
        return false;
    if (matrix[x][y] == 0 || inq[x][y] == true)
        return false;
    return true;
}

void BFS(int x, int y)
{
    queue<node> q;
    Node.x = x;
    Node.y = y;
    q.push(Node);
    inq[x][y] = true;
    while (!q.empty())
    {
        node top = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY))
            {
                Node.x = newX;
                Node.y = newY;
                q.push(Node);
                inq[newX][newY] = true; //表明x,y已入过队
            }
        }
    }
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
        {
            scanf("%d", &matrix[x][y]);
        }
    }
    int block = 0;
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (matrix[x][y] == 1 && inq[x][y] == false)
            {
                block++;
                BFS(x, y);
            }
        }
    }
    printf("The number of 1_blocks: %d\n", block);

    return 0;
}