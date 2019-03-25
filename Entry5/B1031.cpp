#include <cstdio>

int main()
{
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; //前17位权重
    char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};   //取模后对应校验位

    int n;
    char id[19];
    int isPass[105] = {-1};
    int z, count = 0; //count统计错误数
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        isPass[i] = 1;

        getchar(); //回车
        fgets(id, 19, stdin);
        for (int j = 0; j < 17; j++)
        {
            if (id[j] >= '0' && id[j] <= '9') //前17位为数字
            {
                sum += (id[j] - '0') * weight[j];
                z = sum % 11;
            }
            else //否则不通过
            {
                isPass[i] = 0;
                count++;
                break;
            }
        }
        if (M[z] != id[17]) //校验位不同，则不通过
        {
            isPass[i] = 0;
            count++;
        }
        if (isPass[i] == 0) //若未通过，输出
            printf("%s\n", id);
    }
    if (count == 0)
    {
        printf("All passed");
    }
    return 0;
}