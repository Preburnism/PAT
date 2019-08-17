#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxk = 2510;
vector<string> selectCourse[maxk];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    char name[5];
    for (int i = 0; i < n; i++)
    {
        int c;
        scanf("%s%d", name, &c);
        int course;
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &course);
            selectCourse[course].push_back(name);
        }
    }

    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", i, selectCourse[i].size());
        sort(selectCourse[i].begin(), selectCourse[i].end());
        
        for (int j = 0; j < selectCourse[i].size(); j++)
        {
            printf("%s\n", selectCourse[i][j].c_str());
        }
    }

    return 0;
}