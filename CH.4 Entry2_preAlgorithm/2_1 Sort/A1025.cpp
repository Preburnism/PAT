#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct testee
{
    char id[15]; //long long 测试3报错，注册号前面可能带0
    int score;
    int fr; //final_rank
    int location;
    int lr; //local_rank
} t[30005];

bool cmp(testee a, testee b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%s %d", &t[sum].id, &t[sum].score);
            t[sum].location = i + 1;
            sum++;
        }

        sort(t + sum - k, t + sum, cmp);
        t[sum - k].lr = 1;
        for (int j = 1; j < k; j++) //local rank
        {
            if (t[sum - k + j].score == t[sum - k + j - 1].score)
                t[sum - k + j].lr = t[sum - k + j - 1].lr;
            else
                t[sum - k + j].lr = j + 1;
        }
    }

    printf("%d\n", sum);

    sort(t, t + sum, cmp);

    int r = 1;
    for (int i = 0; i < sum; i++) //final rank
    {
        if (i > 0 && t[i].score != t[i - 1].score)
            r = i + 1;
        printf("%s %d %d %d\n", t[i].id, r, t[i].location, t[i].lr);
    }
    return 0;
}