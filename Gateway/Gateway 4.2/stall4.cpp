/*
PROG:stall4
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#define inf 0x7fffffff
#define ivorysi
#define siji(i,x,y) for(int i=(x);i<=(y);++i)
#define gongzi(j,x,y) for(int j=(x);j>=(y);--j)
#define xiaosiji(i,x,y) for(int i=(x);i<(y);++i)
#define sigongzi(j,x,y) for(int j=(x);j>(y);--j)
#define p(x) (x)*(x)
using namespace std;
vector<int> g[505];
int used[505],from[505];
int n,m,ans;
bool find(int x){
    used[x]=1;
    for(int i=0;i<g[x].size();++i) {
        if(from[g[x][i]]) {
            if(used[from[g[x][i]]]==0 && find(from[g[x][i]])) {
                from[g[x][i]]=x;
                return true;
            }
        }
        else {
            from[g[x][i]]=x;
            return true;
        }
    }
    return false;
}
void init() {
    scanf("%d%d",&n,&m);
    int s,b;
    siji(i,1,n) {
        scanf("%d",&s);
        siji(j,1,s) {
            scanf("%d",&b);
            g[i].push_back(b+200);
        }
    }

}
void solve() {
    init();
    siji(i,1,n) {
        memset(used,0,sizeof(used));
        if(find(i)) ++ans;
    }
    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}