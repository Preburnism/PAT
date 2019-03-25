//Shuffling Machine
#include <stdio.h>

const int N = 54;
int card[N + 1], pos[N + 1];
char mp[5] = {'S', 'H', 'C', 'D', 'J'};

int main()
{
    for (int i = 0; i < N; i++)
    {
        card[i] = i + 1; //初始化牌组
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &pos[i]);
    }

    for (int i = 0; i < k; i++)
    {
        int flag[N + 1] = {0};

        for (int j = 0; j < N; j++)
        {
            int m = j;           //赋予m初值
            int next = card[j];  //next为初始点j处的牌面
            int temp = next;     //存档牌面
            while (flag[m] == 0) //当flag为0表示还未进行转化
            {
                flag[m] = 1;             //表示已进行转换
                next = card[pos[m] - 1]; //pos[m]为转移位置，card[pos[m]-1]为将转移位置处的牌面
                card[pos[m] - 1] = temp; //牌面转移
                temp = next;             //temp为下一次转移存档
                m = pos[m] - 1;          //m指向下一位置，即pos[m]
            }
        }
    }
    for (int j = 0; j < N; j++)
    {
        if (j)
            printf(" ");
        printf("%c%d", mp[(card[j] - 1) / 13], (card[j] - 1) % 13 + 1);
    }

    return 0;
}