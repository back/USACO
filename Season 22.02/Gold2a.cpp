#include <bits/stdc++.h>
using namespace std;

double a[1020]; // score
double b[1020]; // probs
double c[1020]; // dp

int t, n;

int main()
{
    cin >> t >> n;
    
    c[1] = 1;
    for (int i = 2; i <= t; i++)
        for (int j = i; j >= 1; j--)
            c[j] = (c[j - 1] + c[j]) / 2.0;
            
    for (int i = t; i > 0; i--)
    {
        a[i] = a[i + 1] + c[i];
        b[i] = b[i + 1] + c[i] * i;
    }
    
    double answer = (t + 1) / 2.0;
    
    for (int i = 2, j = 0; i <= n;)
    {
        while (j <= answer) j++;
        int d = n - i + 1;
        if (j < t)
        {
            int k = int(ceil(log((b[j] - j * a[j]) / (b[j] - answer * a[j])) / log(1 - a[j]))); 
            d = min(d, k);
        }
        answer = b[j] / a[j] - pow(1 - a[j], d) * (b[j] / a[j] - answer);
        i += d;
    }
    cout << fixed << setprecision(8) << answer << endl;
    return 0;
}




