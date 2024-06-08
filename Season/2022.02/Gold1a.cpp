#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[18][18]; // gift prefs
int b[18][18]; // swap prefs

long long chain[262145][18]; // 2^18
long long group[262145];
long long rings[262145];

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t = 1;
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
            if (t) b[i][a[i][j]] = 1;
            if (a[i][j] == i) t = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
        chain[1 << i][i] = 1;

    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if ((~i >> k & 1) && (1 << k) > (i & -i))
                        if (b[k][j])
                            chain[i | 1 << k][k] += chain[i][j];

    for (int i = 1; i < 1 << n; i++)
    {
        int k = __builtin_ctz (i);
        for (int j = 0; j < n; j++)
            if (b[k][j] && chain[i][j])
                rings[i] += chain[i][j];
    }
    
    group[0] = 1;

    for (int i = 1; i < 1 << n; i++)
    {
        if (rings[i] == 0) continue;
        int b = 1;
        while (b <= i) b *= 2;

        b -= 1 + i;
        for (int j = b;; --j &= b)
        {
            group[i | j] += rings[i] * group[j];
            if (j == 0) break;
        }
    }
    
    cin >> q;
    char breed[20];
    for (int i = 0; i < q; i++)
    {
        cin >> breed;
        int H = 0, G = 0;
        for (int i = 0; breed[i]; i++)
            if (breed[i] == 'H')
                H |= 1 << i;
            else
                G |= 1 << i;
        cout << group[H] * group[G] << endl;
    }
    return 0;
}


