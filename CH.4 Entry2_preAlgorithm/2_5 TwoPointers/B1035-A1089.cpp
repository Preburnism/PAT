#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int origin[maxn], temp[maxn], target[maxn];
int n;

bool isSame()
{
    for (int i = 0; i < n; i++)
    {
        if (temp[i] != target[i])
            return false;
    }
    return true;
}
bool isInsert()
{
    int flag = false;
    for (int i = 1; i < n; i++)
    {
        if (i != 1 && isSame()) //初始序列不参与比较
            flag = true;        //不能直接return true，因为需要输出下一轮的排序结果

        int tp = temp[i]; //待插入的值
        int j;
        for (j = i; j > 0 && tp < temp[j - 1]; j--) //插入的值小于前值，依次向前比较
        {
            temp[j] = temp[j - 1];
        }
        temp[j] = tp; //插入j位置

        if (flag)
            return true;
    }
    return false; //遍历完找不到相同的数列，返回false;
}
void outArr()
{
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", temp[i]);
    }
    printf("\n");
}
void mergeSort()
{
    bool flag = false;
    for (int step = 2; step / 2 <= n; step *= 2) //step/2 <= n  即单个子集的长度小于等于n
    {
        if (step != 2 && isSame())
            flag = true;
        for (int i = 0; i < n; i += step)
        {
            sort(temp + i, temp + min(i + step, n)); //min(step, n), 因为i + step到temp末端可能大于n
        }
        if (flag)
        {
            outArr();
            return;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &origin[i]);
        temp[i] = origin[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &target[i]);
    }

    //先比较是否为插排，若不是则进行归并排序
    if (isInsert())
    {
        printf("Insertion Sort\n");
        outArr();
    }
    else //MergeSort
    {
        printf("Merge Sort\n");
        for (int i = 0; i < n; i++)
        {
            temp[i] = origin[i];
        }
        mergeSort();
    }

    return 0;
}