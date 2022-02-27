#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int cnt = 1000000;

string uchange()
{
    string s = "\t\t\t\tuuid = \"" + to_string(cnt++) + "\",";
    return s;
}

int main()
{
    fstream infile;
    fstream outfile;
    string r_str;
    string w_str;
    vector<string> line;

    infile.open("E:\\Temp\\buff.txt");

    if (!infile.is_open())
        printf("Fail to open the file!");

    while (!infile.eof())
    {
        getline(infile, r_str);
        if (r_str.find("uuid") != string::npos)
            r_str = uchange();
        line.push_back(r_str);
    }
    infile.close();

    outfile.open("E:\\Temp\\buff_out.txt", ios::out);
    if (!outfile.is_open())
        printf("Fail to open the file!");

    for (vector<string>::iterator it = line.begin(); it != line.end(); it++)
    {
        outfile << *it << endl;
    }

    outfile.close();

    return 0;
}