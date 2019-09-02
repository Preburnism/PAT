//Digital Library
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, set<int>> book; //最好将不同的查询分类，如 b_title, b_author, b_kw等

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int id;
        string title, author, kw, pr, pr_y;
        scanf("%d%*c", &id); //%*c, 跳过输入值 '\n'

        getline(cin, title);
        book[title].insert(id);

        getline(cin, author);
        book[author].insert(id);

        while (cin >> kw)
        {
            book[kw].insert(id);
            char c;
            c = getchar();
            if (c == '\n')
                break;
        }

        getline(cin, pr);
        book[pr].insert(id);

        getline(cin, pr_y);
        book[pr_y].insert(id);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int order;
        string s;
        scanf("%d: ", &order);
        getline(cin, s);

        printf("%d: ", order);
        cout << s << endl;

        if (book.find(s) == book.end())
            printf("Not Found\n");
        else
        {
            for (set<int>::iterator it = book[s].begin(); it != book[s].end(); it++)
            {
                printf("%07d\n", *it); //the 7-digit ID number;
            }
        }
    }

    return 0;
}