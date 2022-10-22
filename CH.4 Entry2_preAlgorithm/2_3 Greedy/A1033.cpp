#include <cstdio>
#include <algorithm>
using namespace std;

struct gas
{
    double p;
    double d;
} gp[505]; //gas price

bool cmp(gas a, gas b)
{
    return a.d < b.d;
}

int main()
{
    double cmax, dis;
    double davg; //每升油可行驶里程
    int n;       //有n个加油站
    scanf("%lf%lf%lf%d", &cmax, &dis, &davg, &n);

    double cd = cmax * davg; //加满油可行驶里程

    gp[0].p = 0.0;
    gp[0].d = dis;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &gp[i].p, &gp[i].d);
    }
    sort(gp, gp + n + 1, cmp);

    if (gp[0].d == 0)
    {
        double total_p = 0;

        //1、行驶里程内有低于初始点（now = 0）的加油站（gasin），在start点加恰好到gasin点的油
        //2、行驶里程内没有低于初始点（now = 0）的加油站，在start点加满油，并在下一点重新判定   //且在第二便宜的点重新判定
        //3、start点加满油无法到达相邻的下一个点，输出
        //4、初始点没有加油站
        int gasin, now = 0;
        double left = 0;     //油箱油量
        bool isreach = true; //能否到达目的地
        bool isfull;         //是否加满油
        while (now < n)
        {
            if (cd < gp[now + 1].d - gp[now].d) //3、start点加满油无法到达相邻的下一个点，输出
            {
                isreach = false;
                break;
            }
            gasin = now;
            isfull = true;
            for (int i = now + 1; i <= n && gp[i].d - gp[now].d <= cd; i++) //gp[i].d - gp[now].d <= cd 此条件放在for()里防止超时，而不是在for{}内if判断
            {
                gasin = i;
                if (gp[i].p < gp[now].p)
                {
                    isfull = false;
                    break;
                }
            }
            if (isfull)
            {
                total_p += gp[now].p / davg * (cd - left * davg); //加满油
                left = cmax - (gp[gasin].d - gp[now].d) / davg;   //到达下一gasin点剩余油
            }
            else //到gasin点恰好用完油
            {
                total_p += gp[now].p / davg * (gp[gasin].d - gp[now].d - left * davg); //补加恰好足够的油到gasin点
                left = 0;                                                              //到达下一gasin点剩余0
            }
            now = gasin;
        }

        if (isreach)
            printf("%.2f", total_p);
        else
            printf("The maximum travel distance = %.2f", gp[now].d + cd);
    }
    else //4、初始点没有加油站
        printf("The maximum travel distance = 0.00");

    return 0;
}