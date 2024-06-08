/*
LANG: C++
PROG: snail
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
#define inf 0x7fffffff
#define ivorysi
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
int n,b;
char a[10];
int graph[130][130];
int ans;
bool g[130][130];
void dfs(int x,int y,int step) {
    int t1,z;
    ans=max(ans,step);
    if(graph[x-1][y]!=1) {
        t1=x-1,z=step;
        while(graph[t1][y]!=1) {
            if(g[t1][y]) {ans=max(ans,z);goto fail1;}
            g[t1][y]=1;
            ++z;
            --t1;
        }
        dfs(t1+1,y,z);
        fail1://如果不符合仍要更新回来
        siji(i,t1+1,x-1) g[i][y]=0;
    }

    if(graph[x+1][y]!=1) {
        t1=x+1,z=step;
        while(graph[t1][y]!=1) {
            if(g[t1][y]) {ans=max(ans,z);goto fail2;}
            g[t1][y]=1;
            ++z;
            ++t1;
        }
        dfs(t1-1,y,z);
        fail2:
        siji(i,x+1,t1-1) g[i][y]=0;
    }

    if(graph[x][y-1]!=1) {
        t1=y-1,z=step;
        while(graph[x][t1]!=1) {
            if(g[x][t1]) {ans=max(ans,z);goto fail3;}
            g[x][t1]=1;
            ++z;
            --t1;
        }
        dfs(x,t1+1,z);
        fail3:
        siji(i,t1+1,y-1) g[x][i]=0;
    }

    if(graph[x][y+1]!=1) {
        t1=y+1,z=step;
        while(graph[x][t1]!=1) {
            if(g[x][t1]) {ans=max(ans,z);goto fail4;}
            g[x][t1]=1;
            ++z;
            ++t1;
        }
        dfs(x,t1-1,z);
        fail4:
        siji(i,y+1,t1-1) g[x][i]=0;
    }
}
void init() {
    scanf("%d%d",&n,&b);
    int c;
    siji(i,1,b) {
        scanf("%s",a);
        sscanf(a+1,"%d",&c);
        graph[c][a[0]-'A'+1]=1;
    }
    siji(i,0,n+1) {graph[0][i]=1;graph[n+1][i]=1;}
    siji(i,0,n+1) {graph[i][0]=1;graph[i][n+1]=1;}
}
void solve() {
    init();
    g[1][1]=1;
    dfs(1,1,1);
    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("snail.in","r",stdin);
    freopen("snail.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}