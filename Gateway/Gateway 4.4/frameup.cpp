/*
LANG: C++
TASK: frameup
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
    string as;
    char gr[35][35];
    int used[30];
    node() {
        as="";
        memset(gr,'\0',sizeof(gr));
        memset(used,0,sizeof(used));
    }
};
queue<node> q;
int h,w;
int top[30],bottom[30],lef[30],righ[30],view[30];
vector<string> ans;
vector<int> le;
void init() {
    scanf("%d%d",&h,&w);
    node f;
    siji(i,1,h) {
        scanf("%s",f.gr[i]+1);
    }
    q.push(f);
    fill(top,top+27,inf);//fill(first,last,val);
    fill(lef,lef+27,inf);//这里写错了，应该是lef而不是lef+1
    siji(i,1,h) {
        siji(j,1,w) {
            if(f.gr[i][j]<'A' || f.gr[i][j]>'Z' ) continue;
            int k=f.gr[i][j]-'A';
            if(!view[k]) {le.push_back(k);view[k]=1;}

            if(i<top[k]) top[k]=i;
            if(i>bottom[k]) bottom[k]=i;
            if(j<lef[k]) lef[k]=j;
            if(j>righ[k]) righ[k]=j;

        }
    }
    sort(le.begin(),le.end());
}
void bfs() {
    init();
    int cnt=0;
    int wrong=0;
    while(!q.empty()) {
        node now=q.front();q.pop();
        /*printf("-----%d-----\n",++cnt);
        for(int i=1;i<=h;++i) {
            printf("%s\n",now.gr[i]+1);
        }*/
        if(now.as.length()==le.size()) {ans.push_back(now.as);continue;}
        node t=now;
        xiaosiji(i,0,le.size()) {
            if(t.used[le[i]]) continue;
            siji(j,lef[le[i]],righ[le[i]]) {
                if(now.gr[top[le[i]]][j]=='*' || now.gr[top[le[i]]][j]=='A'+le[i]) {
                    t.gr[top[le[i]]][j]='*';
                }
                else {wrong=1;goto fail;}
            }
            siji(j,lef[le[i]],righ[le[i]]) {
                if(now.gr[bottom[le[i]]][j]=='*' || now.gr[bottom[le[i]]][j]=='A'+le[i]) {
                    t.gr[bottom[le[i]]][j]='*';
                }
                else {wrong=2;goto fail;}
            }
            siji(j,top[le[i]],bottom[le[i]]) {
                if(now.gr[j][lef[le[i]]]=='*' || now.gr[j][lef[le[i]]]=='A'+le[i]) {
                    t.gr[j][lef[le[i]]]='*';
                }
                else {wrong=3;goto fail;}
            }
            siji(j,top[le[i]],bottom[le[i]]) {
                if(now.gr[j][righ[le[i]]]=='*' || now.gr[j][righ[le[i]]]=='A'+le[i]) {
                    t.gr[j][righ[le[i]]]='*';
                }
                else {wrong=4;goto fail;}
            }
            t.as.append(1,'A'+le[i]);
            t.used[le[i]]=1;
            q.push(t);
            t=now;continue;
            fail:
            //printf("%d %c %d\n",cnt,le[i]+'A',wrong);
            //printf("%d %d %d %d\n",top[le[i]],bottom[le[i]],lef[le[i]],righ[le[i]]);
            t=now;
        }
    }
}
void solve() {
    bfs();
    xiaosiji(i,0,ans.size()) {
        reverse(ans[i].begin(),ans[i].end());
    }
    sort(ans.begin(),ans.end());
    xiaosiji(i,0,ans.size()) {
        cout<<ans[i]<<endl;
    }
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("frameup.in","r",stdin);
    freopen("frameup.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}