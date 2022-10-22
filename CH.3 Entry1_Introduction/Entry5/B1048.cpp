#include <cstdio>
#include <cstring>

char match[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

void reverse(char a[])
{
    int len = strlen(a);
    char temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = a[len - 1 - i];
        a[len - 1 - i] = a[i];
        a[i] = temp;
    }
}

int main()
{
    char a[105], b[105], c[105] = {0};
    scanf("%s%s", a, b);

    int len1 = strlen(a);
    int len2 = strlen(b);

    reverse(a);
    reverse(b);

    int num1 = 0, num2 = 0; //a[i],b[i]的int值

        for (int i = 0; i < len1 || i < len2; i++)
    {
        i >= len1 ? num1 = 0 : num1 = a[i] - '0';
        i >= len2 ? num2 = 0 : num2 = b[i] - '0';
        if (i % 2 == 0) //odd
        {
            c[i] = match[(num1 + num2) % 13];
        }
        else //even
        {
            int temp = num2 - num1;
            if (temp < 0)
                temp += 10;
            c[i] = (char)(temp + '0');
        }
    }

    reverse(c);

    printf("%s", c);

    return 0;
}