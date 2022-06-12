/*
PROG:ditch
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#define inf 0x7fffffff
#define ivorysi
#define siji(i,x,y) for(int i=x;i<=y;++i)
#define gongzi(j,x,y) for(int j=x;j>=y;--j)
#define xiaosiji(i,x,y) for(int i=x;i<y;++i)
#define sigongzi(j,x,y) for(int j=x;j>y;--j)
using namespace std;
struct node {
    int to,next,val;
}edge[505];
int head[305],sum=1;
void add(int u,int v,int c) {
    edge[++sum].to=v;
    edge[sum].next=head[u];
    edge[sum].val=c;
    head[u]=sum;
}
void AddTwoWays(int u,int v,int c) {
    add(u,v,c);
    add(v,u,0);//反向边
}
int n,m,dis[305],gap[305],ans;
int sap(int u,int aug){//O（玄学）
    if(u==m) return aug;
    int dmin=m-1,flow=0,v,t;

    for(int i=head[u];i;i=edge[i].next) {
        v=edge[i].to;
        if(edge[i].val>0) {//只有还能流动的地方才能分层
            if(dis[u]==dis[v]+1) {
                t=sap(v,min(aug-flow,edge[i].val));//限制流量不超过该点流量和边的限制
                edge[i].val-=t;
                edge[i^1].val+=t;
                flow+=t;
                if(aug==flow) return flow;//流尽
                if(dis[1]>=m) return flow;//搜索已在某处达到结束条件
            }
            dmin=min(dmin,dis[v]);
        }
    }
    if(!flow) {
        --gap[dis[u]];
        if(gap[dis[u]]==0) dis[1]=m;//出现断层说明无法再流
        dis[u]=dmin+1;//分层
        ++gap[dis[u]];
    }
    return flow;
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    int u,v,c;
    siji(i,1,n) {
        scanf("%d%d%d",&u,&v,&c);
        AddTwoWays(u,v,c);
    }
    while(dis[1]<m) {ans+=sap(1,inf);}
    printf("%d\n",ans);
    return 0;
}