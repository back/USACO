/*
LANG: C++
PROG: rect1
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
int n,col[10005],an[2505];
struct data {
    int lx,ly,rx,ry;
}squ[10005];
int areas(data &t) {
    return (t.rx-t.lx+1)*(t.ry-t.ly+1);
}
void init() {
    scanf("%d%d%d",&squ[0].rx,&squ[0].ry,&n);
    --squ[0].rx;--squ[0].ry;
    siji(i,1,n) {
        scanf("%d%d%d%d",&squ[i].lx,&squ[i].ly,&squ[i].rx,&squ[i].ry);
        --squ[i].rx;
        --squ[i].ry;
        scanf("%d",&col[i]);
    }
    col[0]=1;
}
int dfs(int k,data q) {
    if(q.rx<q.lx || q.ry<q.ly) return 0;


    int ans=0;
    while((q.lx>squ[k].rx || q.rx<squ[k].lx || q.ly>squ[k].ry || q.ry<squ[k].ly )&&k<=n) ++k;
    if(k>n) return areas(q);
    if(q.lx<squ[k].lx)
        ans+=dfs(k+1,(data){q.lx,max(q.ly,squ[k].ly),squ[k].lx-1,min(squ[k].ry,q.ry)});
    if(q.rx>squ[k].rx)
        ans+=dfs(k+1,(data){squ[k].rx+1,max(q.ly,squ[k].ly),q.rx,min(squ[k].ry,q.ry)});
    if(q.ly<squ[k].ly)
        ans+=dfs(k+1,(data){q.lx,q.ly,q.rx,squ[k].ly-1});
    if(q.ry>squ[k].ry)
        ans+=dfs(k+1,(data){q.lx,squ[k].ry+1,q.rx,q.ry});
    return ans;
}
void solve() {
    init();
    siji(i,0,n)
        an[col[i]]+=dfs(i+1,squ[i]);
    siji(i,1,2500) if(an[i]!=0) printf("%d %d\n",i,an[i]);
}
int main(int argc, char const *argv[])
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w",stdout);
    solve();
    return 0;
}