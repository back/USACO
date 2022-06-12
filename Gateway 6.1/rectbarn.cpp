/*
LANG: C++
PROG: rectbarn
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#define siji(i,x,y) for(int i=(x);i<=(y);++i)
#define gongzi(j,x,y) for(int j=(x);j>=(y);--j)
#define xiaosiji(i,x,y) for(int i=(x);i<(y);++i)
#define sigongzi(j,x,y) for(int j=(x);j>(y);--j)
#define inf 0x5f5f5f5f
#define ivorysi
#define mo 97797977
#define hash 974711
#define base 47
#define fi first
#define se second
#define pii pair<int,int>
#define esp 1e-8
typedef long long ll;
using namespace std;
bool damage[3005][3005];
int h[3005],l[3005],r[3005],tl[3005],tr[3005];
int n,m,p,x,y,ans;
void solve() {
    scanf("%d%d%d",&n,&m,&p);
    siji(i,1,p) {
        scanf("%d%d",&x,&y);
        damage[x][y]=1;
    }
    siji(i,1,m) {r[i]=m+1;l[i]=1;}
    siji(i,1,n) {
        tl[0]=0;tl[m+1]=m+1;
        siji(j,1,m) {
            if(damage[i][j]) tl[j]=j;
            else tl[j]=tl[j-1];
        }
        tr[0]=0;tr[m+1]=m+1;
        gongzi(j,m,1) {
            if(damage[i][j]) tr[j]=j;
            else tr[j]=tr[j+1];
        }
        siji(j,1,m) {
            if(damage[i][j]) {
                h[j]=0;
                l[j]=0;
                r[j]=m+1;
            }
            else {
                h[j]=h[j]+1;
                l[j]=max(l[j],tl[j]+1);
                r[j]=min(r[j],tr[j]-1);
                ans=max(ans,(r[j]-l[j]+1)*h[j]);
            }
        }
    }
    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("rectbarn.in","r",stdin);
    freopen("rectbarn.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}