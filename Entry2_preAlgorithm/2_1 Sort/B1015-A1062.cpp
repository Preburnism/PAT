#include <cstdio>
#include <algorithm>

struct v_t
{
    int id;
    int vg;
    int tg;
    int sum;   //vg+tg;
    int grade; //sage 1, nobleman 2, fool man 3, others 4, below L 5;
} Rank[100005];

bool cmp(v_t a, v_t b)
{
    if (a.grade != b.grade)
        return a.grade < b.grade;
    else if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.vg != b.vg)
        return a.vg > b.vg;
    else if (a.id != b.id)
        return a.id < b.id;
}

int main()
{
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);

    int passn = N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d", &Rank[i].id, &Rank[i].vg, &Rank[i].tg);
        Rank[i].sum = Rank[i].vg + Rank[i].tg;

        if (Rank[i].vg < L || Rank[i].tg < L)
        {
            Rank[i].grade = 5;
            passn--;
        }
        else if (Rank[i].vg >= H && Rank[i].tg >= H)
            Rank[i].grade = 1;
        else if (Rank[i].vg >= H && Rank[i].tg < H)
            Rank[i].grade = 2;
        else if (Rank[i].vg >= Rank[i].tg)
            Rank[i].grade = 3;
        else
            Rank[i].grade = 4;
    }
    std::sort(Rank, Rank + N, cmp);

    printf("%d\n", passn);
    for (int i = 0; i < N; i++)
    {
        if (Rank[i].grade != 5)
        {
            printf("%d %d %d\n", Rank[i].id, Rank[i].vg, Rank[i].tg);
        }
    }

    return 0;
}