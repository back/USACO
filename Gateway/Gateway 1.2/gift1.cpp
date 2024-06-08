/*
TASK: gift1
LANG: C++
*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    fstream fin("gift1.in", ios_base::in);
    fstream fout("gift1.out", ios_base::out);
    int num;
    fin >> num;
    string name;
    vector<string> names;
    unordered_map<string, int> m1;
    for (int i = 0; i < num; i++) {
        fin >> name;
        names.push_back(name);
        m1[name] = 0;
    }

    while (fin >> name) {
        int amount;
        fin >> amount >> num;
        int dist = 0;
        if (num != 0) {
            dist = amount / num;
            int left = amount % num;
            m1[name] -= (amount-left);
        }
        else {
            continue;
        }

        for (int i = 0; i < num; i++) {
            fin >> name;
            m1[name] += dist;
        }
    }

    for (auto& e : names) {
        fout << e << " " << m1[e] << endl;
    }
}