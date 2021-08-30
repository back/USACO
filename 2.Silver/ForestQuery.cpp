#include <iostream>
using namespace std;

const int N = 1001;
long long ar[N][N];
 
long long calc(int sx , int sy , int ex , int ey) {
    return ar[ex][ey] - ar[sx-1][ey] - ar[ex][sy-1] + ar[sx-1][sy-1];
}

int main() {
    int n , q;
    int a , b , c , d;
    char ch;
    
    cin>>n>>q;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1, k = 0; j <= n; j++)
            cin>>ch, k += ch=='*', ar[i][j] = k + ar[i-1][j];
    
    while(q--)
        cin>>a>>b>>c>>d , cout<<calc(a , b , c , d)<<endl;
}