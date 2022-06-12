/*
LANG: C++
TASK: race3
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
#define inf 0x7fffffff
#define ivorysi
#define mo 97797977
#define hash 974711
#define base 47
#define MAXN 30005
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
struct node {
    int to,next;
}edge[205];
int head[205],sumedge;
void add(int u,int v) {
    edge[++sumedge].to=v;
    edge[sumedge].next=head[u];
    head[u]=sumedge;
}

int vis1[55],vis2[55],cnt;
queue<int> q;
void bfs(int u,int *w,int p) {
    while(!q.empty()) {q.pop();}
    q.push(u);
    siji(i,1,cnt) w[i]=0;
    while(!q.empty()) {
        int now=q.front();q.pop();
        w[now]=1;
        for(int i=head[now];i;i=edge[i].next) {
            int v=edge[i].to;
            if(v!=p && w[v]==0) q.push(v);
        }
    }
}
void init() {
    cnt=1;
    int u;
    while(1) {
        scanf("%d",&u);
        if(u==-2) ++cnt;
        else if(u==-1) break;
        else {
            add(cnt,u+1);
        }
    }
}
vector<int> ans1,ans2;
void solve() {
    init();
    --cnt;
    siji(i,2,cnt-1) {
        bfs(1,vis1,i);
        if(vis1[cnt]==0) ans1.push_back(i);
    }
    printf("%d",ans1.size());
    xiaosiji(i,0,ans1.size()) {
        printf(" %d",ans1[i]-1);
    }
    puts("");
    xiaosiji(i,0,ans1.size()) {
        bfs(1,vis1,ans1[i]);
        bfs(ans1[i],vis2,0);
        bool flag=1;
        siji(j,1,cnt) {
            if(vis1[j] && vis2[j]) {flag=0;break;}
        }
        if(flag) {
            ans2.push_back(ans1[i]);
        }
    }
    printf("%d",ans2.size());
    xiaosiji(i,0,ans2.size()) {
        printf(" %d",ans2[i]-1);
    }
    puts("");
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("race3.in","r",stdin);
    freopen("race3.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}