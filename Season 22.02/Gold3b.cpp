#include <bits/stdc++.h>
using namespace std;

int n;
pair < int, int > p[100020];
vector < pair < long long, pair < int, int >>> e;

long long dis (int i, int j)
{
    return (long long) (p[i].first - p[j].first) * (p[i].first - p[j].first) +
           (long long) (p[i].second - p[j].second) * (p[i].second - p[j].second);
}

int k_node[100020];
int k_zone (int x)
{
    return k_node[x] != x ? k_node[x] = k_zone (k_node[x]) : x;
}

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
        k_node[i] = i;
    }
    
    sort (p, p + n);

    int tp[11]; // tail points
    memset (tp, -1, sizeof tp);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 10; j++)
            if (tp[j] != -1)
                e.push_back (make_pair (dis (tp[j], i), make_pair (tp[j], i)));
        tp[p[i].second] = i;
    }
    sort (e.begin(), e.end());
    
    long long answer = 0;
    for (int i = 0; i < e.size(); i++)
    {
        int x = k_zone (e[i].second.first);
        int y = k_zone (e[i].second.second);
        if (x != y)
        {
            answer += e[i].first;
            k_node[x] = y;
        }
    }
    cout << answer << endl;
    return 0;
}




