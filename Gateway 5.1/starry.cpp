/*
LANG: C++
TASK: starry
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
char m[105][105];
int maze[105][105],id[105][105];
int w,h,cnt,fa[505],color[505],tot,used[505];
int dix[8]={1,-1,0,0,1,-1,1,-1};
int diy[8]={0,0,1,-1,1,1,-1,-1};
vector<pii > v[505];
pii size[505],poi[505];
int getfa(int x) {
    return fa[x]==x ? x : fa[x]=getfa(fa[x]);
}
int to[505],bo[505],lf[505],ri[505];
void dfs(int x,int y) {
    id[x][y]=cnt;
    if(y<lf[cnt]) lf[cnt]=y;
    if(y>ri[cnt]) ri[cnt]=y;
    if(x<to[cnt]) to[cnt]=x;
    if(x>bo[cnt]) bo[cnt]=x;
     v[cnt].push_back(make_pair(x,y));
    xiaosiji(i,0,7) {
        if(maze[x+dix[i]][y+diy[i]] && id[x+dix[i]][y+diy[i]]==0) {
            dfs(x+dix[i],y+diy[i]);
        }
    }
}
bool circ(int ori,int ch) {
    pii t=make_pair(0,0);
    xiaosiji(i,0,v[ori].size()) {
        int temp=v[ori][i].fi;
        v[ori][i].fi=v[ori][i].se;
        v[ori][i].se=100-temp+1;
        if(v[ori][i]>t) t=v[ori][i];
    }
    int inx=poi[ch].fi-t.fi,iny=poi[ch].se-t.se;
    xiaosiji(i,0,v[ori].size()) {
        v[ori][i].fi+=inx;
        v[ori][i].se+=iny;
    }
    sort(v[ori].begin(),v[ori].end());
    xiaosiji(i,0,v[ori].size()) {
        if(v[ori][i]!=v[ch][i]) {
            return false;
        }
    }
    return true;
}
void sym(int ori) {
    xiaosiji(i,0,v[ori].size()) {
        v[ori][i].se=100-v[ori][i].se;
    }
}
void solve() {
    scanf("%d%d",&w,&h);
    siji(i,1,h) {
        scanf("%s",m[i]+1);
    }
    siji(i,1,h) {
        siji(j,1,w) {
            maze[i][j]=m[i][j]-'0';
        }
    }
    memset(to,1,sizeof(to));
    memset(lf,1,sizeof(lf));
    siji(i,1,h){
        siji(j,1,w) {
            if(maze[i][j]) {
                if(id[i][j]==0) {
                    v[++cnt].clear();
                    dfs(i,j);
                    size[cnt]=make_pair(bo[cnt]-to[cnt],ri[cnt]-lf[cnt]);
                    if(size[cnt].fi > size[cnt].se)
                        swap(size[cnt].fi,size[cnt].se);
                }
            }
        }
    }
    siji(i,1,cnt) fa[i]=i;
    siji(i,1,cnt) {
        sort(v[i].begin(),v[i].end());
        pii t=make_pair(0,0);
        xiaosiji(j,0,v[i].size()) {
            if(v[i][j]>t) t=v[i][j];
        }
        poi[i]=t;
        siji(j,i+1,cnt) {
            if(getfa(i)!=getfa(j)) {
                if(v[j].size() != v[i].size()) {continue;}
                if(size[i] != size[j]) {continue;}
                siji(k,1,4){
                    if(circ(j,i)) {fa[getfa(j)]=getfa(i);break;}
                }
                sym(j);
                siji(k,1,4){
                    if(circ(j,i)) {fa[getfa(j)]=getfa(i);break;}
                }
            }
        }
    }
    siji(i,1,cnt) {
        if(!used[getfa(i)]) {
            used[getfa(i)]=1;
            color[getfa(i)]=++tot;
        }
        else {
            color[i]=color[getfa(i)];
        }
    }
    siji(i,1,h) {
        siji(j,1,w) {
            if(id[i][j]!=0) {
                printf("%c",color[id[i][j]]+'a'-1);
            }
            else {printf("0");}
        }
        puts("");
    }
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("starry.in","r",stdin);
    freopen("starry.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}