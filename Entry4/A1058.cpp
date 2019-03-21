#include <cstdio>

int main()
{
    int a[3], b[3], c[3];
    scanf("%d.%d.%d %d.%d.%d", &a[2], &a[1], &a[0], &b[2], &b[1], &b[0]);
    int carry = 0, sum = 0;
    sum = a[0] + b[0];
    c[0] = sum % 29;
    carry = sum / 29;

    sum = a[1] + b[1] + carry;
    c[1] = sum % 17;
    carry = sum / 17;

    sum = a[2] + b[2] + carry;  
    c[2] = sum;

    printf("%d.%d.%d", c[2], c[1], c[0]);

    return 0;
}