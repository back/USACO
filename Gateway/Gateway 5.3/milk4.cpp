/*
LANG: C++
PROG: milk4
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <string.h>
#include <cmath>
#define siji(i,x,y) for(int i=(x);i<=(y);++i)
#define gongzi(j,x,y) for(int j=(x);j>=(y);--j)
#define xiaosiji(i,x,y) for(int i=(x);i<(y);++i)
#define sigongzi(j,x,y) for(int j=(x);j>(y);--j)
#define inf 0x3f3f3f3f
//#define ivorysi
#define mo 97797977
#define hash 974711
#define base 47
#define pss pair<string,string>
#define MAXN 5000
#define fi first
#define se second
#define pii pair<int,int>
#define esp 1e-8
typedef long long ll;
using namespace std;
int q,p;
int f[20005];
int ld,used[105],w[105];
int flag=0,cnt;
bool calc(int tmp) {
    if(f[tmp]!=-1) return f[tmp];
    f[tmp]=0;
    siji(i,1,p) {
        if(used[i] && tmp%w[i]==0) return f[tmp]=1;
    }
    siji(i,1,p) {
        if(used[i] && tmp>=w[i]) {
            f[tmp]=(f[tmp] || calc(tmp-w[i]));
            if(f[tmp]==1) return f[tmp];
        }
    }
    return f[tmp];
}
void dfs(int d,int pr) {
    if(flag) return;
    if(d==ld){
        siji(i,1,q) f[i]=-1;
        f[0]=1;
        if(calc(q)) {
            flag=1;
            printf("%d ",ld);
            siji(i,1,p) {
                if(used[i]) {
                    ++cnt;
                    printf("%d%c",w[i]," \n"[cnt==ld]);
                }
            }
        }
        return;
    }
    siji(i,pr+1,p) {
        used[i]=1;
        dfs(d+1,i);
        if(flag) return;
        used[i]=0;
    }
}
void solve() {
    scanf("%d%d",&q,&p);
    siji(i,1,p) {
        scanf("%d",&w[i]);
    }
    sort(w+1,w+p+1);
    f[0]=1;
    siji(i,1,p) {
        ld=i;
        dfs(0,0);
        if(flag) break;
    }
}
int main(int argc, char const *argv[])
{
    freopen("milk4.in","r",stdin);
    freopen("milk4.out","w",stdout);
    solve();
    return 0;
}