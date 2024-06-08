/*
LANG: C++
PROG: clocks
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define siji(i,x,y) for(int i=(x) ; i <= (y) ; ++i)
#define xiaosiji(i,x,y) for(int i = (x) ; i < (y); ++i)
#define gongzi(j,x,y) for(int j = (x) ; j >= (y) ; --j)
#define ivorysi
#define mo 11447
#define eps 1e-8
#define o(x) ((x)*(x))
using namespace std;
typedef long long ll;
int clo[4][4],rec[10],ans[10],all=10000;
void span(int &a) {
    a=(a+1)%4;
}
bool check() {
    siji(i,1,3) {
        siji(j,1,3) {
            if(clo[i][j]!=3)return false;
        }
    }
    return true;
}
void del1() {
    span(clo[1][1]);
    span(clo[1][2]);
    span(clo[2][1]);
    span(clo[2][2]);
}
void del2() {
    span(clo[1][1]);
    span(clo[1][2]);
    span(clo[1][3]);
}
void del3() {
    span(clo[1][2]);
    span(clo[1][3]);
    span(clo[2][2]);
    span(clo[2][3]);
}
void del4() {
    span(clo[1][1]);
    span(clo[2][1]);
    span(clo[3][1]);
}
void del5() {
    span(clo[1][2]);
    span(clo[2][1]);
    span(clo[2][2]);
    span(clo[2][3]);
    span(clo[3][2]);
}
void del6() {
    span(clo[1][3]);
    span(clo[2][3]);
    span(clo[3][3]);
}
void del7() {
    span(clo[2][1]);
    span(clo[2][2]);
    span(clo[3][1]);
    span(clo[3][2]);
}
void del8() {
    span(clo[3][1]);
    span(clo[3][2]);
    span(clo[3][3]);
}
void del9() {
    span(clo[2][2]);
    span(clo[2][3]);
    span(clo[3][2]);
    span(clo[3][3]);
}
void dfs(int dep,int times) {
    if(times>=all) return;
    if(dep>9) {
        if(!check()) return;
        all=times;
        memcpy(ans,rec,sizeof(rec));
        return;
    }
    void (*cur)();
    if(dep==1) cur=&del1;
    else if(dep==2) cur=&del2;
    else if(dep==3) cur=&del3;
    else if(dep==4) cur=&del4;
    else if(dep==5) cur=&del5;
    else if(dep==6) cur=&del6;
    else if(dep==7) cur=&del7;
    else if(dep==8) cur=&del8;
    else if(dep==9) cur=&del9;

    siji(i,1,3) {
        (*cur)();
        rec[dep]=i;
        dfs(dep+1,times+i);
    }
    (*cur)();
    rec[dep]=0;
    dfs(dep+1,times);
}
void solve() {
    siji(i,1,3) {
        siji(j,1,3) {
            scanf("%d",&clo[i][j]);
            clo[i][j]/=3;
            --clo[i][j];
        }
    }
    int cnt=0;
    dfs(1,0);
    siji(i,1,9) {
        siji(j,1,ans[i]) {
            ++cnt;
            printf("%d%c",i," \n"[cnt==all]);
        }
    }
}
int main(int argc, char const *argv[])
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    solve();
    return 0;
}