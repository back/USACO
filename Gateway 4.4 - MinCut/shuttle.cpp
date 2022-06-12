/*
LANG: C++
TASK: shuttle
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
#define pss pair<string,string>
#define MAXN 30005
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
struct node {
    int line[30],bl;
    vector<int> v;
}f;
queue<node > q;
int n;
bool check(node tem) {
    if(tem.bl==n+1) {
        bool flag=1;
        siji(i,1,n) {
            if(tem.line[i]!=2) flag=0;
        }
        siji(i,n+2,2*n+1) {
            if(tem.line[i]!=1) flag=0;
        }
        if(flag) return true;
    }
    return false;
}
void bfs() {
    scanf("%d",&n);
    siji(i,1,n) {
        f.line[i]=1;
    }
    f.bl=n+1;
    siji(i,n+2,2*n+1) {
        f.line[i]=2;
    }
    q.push(f);
    while(!q.empty()) {
        node now=q.front();q.pop();
        if(check(now)) {f=now;break;}
        node t=now;
        if(t.bl>2 && t.line[t.bl-1]!=t.line[t.bl-2] && t.line[t.bl-2]==1) {
            t.v.push_back(t.bl-2);
            t.line[t.bl]=t.line[t.bl-2];
            t.line[t.bl-2]=0;
            t.bl=t.bl-2;
            q.push(t);
            t=now;
        }

        if(t.bl>1 && t.line[t.bl-1]==1) {
            t.v.push_back(t.bl-1);
            t.line[t.bl]=t.line[t.bl-1];
            t.line[t.bl-1]=0;
            t.bl=t.bl-1;
            q.push(t);
            t=now;
        }

        if(t.bl<2*n+1 && t.line[t.bl+1]==2) {
            t.v.push_back(t.bl+1);
            t.line[t.bl]=t.line[t.bl+1];
            t.line[t.bl+1]=0;
            t.bl=t.bl+1;
            q.push(t);
            t=now;
        }

        if(t.bl<2*n && t.line[t.bl+1]!=t.line[t.bl+2] && t.line[t.bl+2]==2) {
            t.v.push_back(t.bl+2);
            t.line[t.bl]=t.line[t.bl+2];
            t.line[t.bl+2]=0;
            t.bl=t.bl+2;
            q.push(t);
        }
    }
    xiaosiji(i,0,f.v.size()) {
        printf("%d%c",f.v[i]," \n"[i==f.v.size()-1 || (i+1)%20==0]);
    }
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("shuttle.in","r",stdin);
    freopen("shuttle.out","w",stdout);
#else
    //freopen("f1.in","r",stdin);
#endif
    bfs();
    return 0;
}