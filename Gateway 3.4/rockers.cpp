/*
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <string.h>
#define siji(i,x,y) for(int i=(x);i<=(y);++i)
#define gongzi(j,x,y) for(int j=(x);j>=(y);--j)
#define xiaosiji(i,x,y) for(int i=(x);i<(y);++i)
#define sigongzi(j,x,y) for(int j=(x);j>(y);--j)
#define inf 0x3f3f3f3f
#define MAXN 400005
#define ivorysi
#define mo 97797977
#define ha 974711
#define ba 47
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long ll;
int n,m,t;
int song[25];
int getso[25][25];
int f[25];
inline int max(int a,int b){return a>b?a:b;}
int check(int b,int e) {
    if(e<b) return 0;
    memset(f,0,sizeof(f));
    siji(i,b,e) {
        gongzi(j,t,song[i]) {
            f[j]=max(f[j],f[j-song[i]]+1);
        }
    }
    return f[t];
}
void solve() {
    scanf("%d%d%d",&n,&t,&m);
    siji(i,1,n) scanf("%d",&song[i]);
    siji(i,1,m) {
        siji(j,1,n) {
            xiaosiji(k,0,j) {
                getso[i][j]=max(getso[i][j],getso[i-1][k]+check(k+1,j));
            }
        }
    }
    printf("%d\n",getso[m][n]);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
}