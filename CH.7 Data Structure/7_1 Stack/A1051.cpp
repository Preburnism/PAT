//Pop Sequence
#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1010;
stack<int> st;

int main()
{
    int m, n, k;
    int arr[maxn];
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 0; i < k; i++)
    {
        while (!st.empty())
        {
            st.pop(); //清空栈
        }
        bool islegal = true;

        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[j]);
        }

        int pos = 1; //输入数组的下标
        for (int j = 1; j <= n; j++)
        {
            st.push(j);        //入栈
            if (st.size() > m) //入栈元素超过容量，非法
            {
                islegal = false;
                break;
            }

            while (!st.empty() && st.top() == arr[pos]) //判断输入数字是否与模拟栈的栈顶元素想等，想等则出栈
            {
                st.pop();
                pos++;
            }
        }

        if (st.empty() && islegal)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}