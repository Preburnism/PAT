// Course List for Student
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxm = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[maxm]; //名字为 m 的学生选择的课程编号

int getID(char name[])
{
    int id = 0;
    for (int i = 0; i < 3; i++)
    {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + name[3] - '0';

    return id;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    char name[5];
    for (int i = 0; i < k; i++)
    {
        int course, num;
        scanf("%d%d", &course, &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%s", name);
            selectCourse[getID(name)].push_back(course);
        }
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        printf("%s ", name);

        int id = getID(name);
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%d", selectCourse[id].size());

        for (int j = 0; j < selectCourse[id].size(); j++)
        {
            printf(" %d", selectCourse[id][j]);
        }
        printf("\n");
    }

    return 0;
}