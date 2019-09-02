//Speech Patterns
#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;

set<char> valid;
map<string, int> speech;

void init()
{
    for (int i = 0; i < 9; i++)
    {
        valid.insert('0' + i);
    }
    for (int i = 0; i < 26; i++)
    {
        valid.insert('a' + i);
    }
    for (int i = 0; i < 26; i++)
    {
        valid.insert('A' + i);
    }
}

int main()
{
    init();

    string text;
    getline(cin, text);

    int index = 0;
    while (index < text.length())
    {
        string word;
        while (valid.find(text[index]) != valid.end())
        {
            if (text[index] >= 'A' && text[index] <= 'Z')
                text[index] = tolower(text[index]);

            word.push_back(text[index]);
            index++;
        }
        if (word.length() != 0)
            speech.find(word) != speech.end() ? speech[word]++ : speech[word] = 1;

        index++;
    }

    string word;
    int maxcnt = 0;
    for (map<string, int>::iterator it = speech.begin(); it != speech.end(); it++)
    {
        if (maxcnt < it->second)
        {
            word = it->first;
            maxcnt = it->second;
        }
    }

    cout << word << " " << maxcnt << endl;

    return 0;
}