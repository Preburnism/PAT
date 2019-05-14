#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int cnt = 0;

    int num;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr[num] = i; //数组arr[num]的位置为i，num是数的值
    }

    int step = 1;
    do
    {
        if (arr[0] != arr[arr[0]])
        {
            swap(arr[0], arr[arr[0]]);
            cnt++;
        }

        if (arr[0] == 0) //判断置换是否正确完成
        {
            for (int i = step; i < n; i++) //step防止运行超时
            {
                if (arr[i] != i) //该点点位错误
                {
                    swap(arr[0], arr[i]);
                    cnt++;
                    step = i;
                    break;
                }
            }
        }
    } while (arr[0] != 0);

    printf("%d", cnt);

    return 0;
}