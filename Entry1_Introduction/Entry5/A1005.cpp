#include <cstdio>
//#include <string>
#include <cstring>
//using namespace std;

char match[10][8] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void print(int a)
{
    if (a / 10 == 0)
    {
        printf("%s", match[a]);
        return;
    }
    print(a / 10);
    printf(" %s", match[a % 10]);
}
int main()
{
    char num[105];
    scanf("%s", num);

    int len = strlen(num);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += (num[i] - '0');
    }

    /*
    string s_sum = to_string(sum);
    len = s_sum.length();
    for (int i = 0; i < len; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%s", match[s_sum[i] - '0']);
    }
    */
    print(sum);
    return 0;
}