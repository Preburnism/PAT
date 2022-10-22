#include <stdio.h>
#include <time.h>
#define CLK_TCK 100
using namespace std;

int main()
{
    int c1, c2, t;
    int hh, mm, ss;

    scanf("%d%d", &c1, &c2);
    t = c2 - c1;
    if (t % 100 >= 50)
        t = t / CLK_TCK + 1;
    else
        t = t / CLK_TCK;
        
    ss = t % 60;
    hh = t / 3600;
    mm = t % 3600 / 60;
    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}