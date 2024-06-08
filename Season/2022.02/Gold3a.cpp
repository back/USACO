#include <bits/stdc++.h>
using namespace std;

int n;
pair < int, int > p[100020];
vector < pair < long long, pair < int, int >>> e;

long long weight (int i, int j)
{
    long long x = p[i].first - p[j].first;
    long long y = p[i].second - p[j].second;
    return x * x + y * y;
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
                e.push_back (make_pair (weight (tp[j], i), make_pair (tp[j], i)));
        tp[p[i].second] = i;
    }
    sort (e.begin(), e.end());
    
    long long answer = 0;
    for (int i = 0; i < e.size(); i++)
    {
        int z1 = k_zone (e[i].second.first);
        int z2 = k_zone (e[i].second.second);
        if (z1 != z2)
        {
            answer += e[i].first;
            k_node[z1] = z2;
        }
    }
    cout << answer << endl;
    return 0;
}
