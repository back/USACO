/*
LANG: C++
PROG: window
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
char a[50];
int f,cut[205];
int cnt;
struct data{
    int lx,ly,rx,ry;
    int h;
}window[205];
int calc(char c) {
    if(c>='a' && c<='z') return c-'a'+1;
    else if (c>='A' && c<='Z') return c-'A'+27;
    else if(c>='0' && c<='9') return c-'0'+53;
}
void ins(int x,int y,int X,int Y,char c) {
    int t=calc(c);
    ++cnt;
    window[t].lx=min(x,X);
    window[t].ly=min(y,Y);
    window[t].rx=max(x,X);
    window[t].ry=max(y,Y);
    window[t].h=1;
    siji(i,1,62) {//这里原来打成xiaosiji忘改了
        if(window[i].h!=0 && i!=t) ++window[i].h;
    }
}
void top(char c) {
    int t=calc(c);
    int he=window[t].h;
    window[t].h=1;
    siji(i,1,62) {
        if(window[i].h!=0 && window[i].h<he && i!=t) ++window[i].h;
    }
}
void del(char c) {
    int t=calc(c);
    int he=window[t].h;
    window[t].h=0;
    siji(i,1,62) {
        if(window[i].h!=0 && window[i].h>he) --window[i].h;
    }
}
void bottom(char c) {
    int t=calc(c);
    int he=window[t].h;
    window[t].h=cnt;
    siji(i,1,62) {
        if(window[i].h!=0 && window[i].h>he && i!=t) --window[i].h;
    }
}
int solute(int k,int x1,int y1,int x2,int y2) {
    if(x2<=x1 || y2<=y1) return 0;
    int t=k;
    while(t>0&&(window[cut[t]].rx <=x1 || window[cut[t]].ry<=y1
        || window[cut[t]].lx>=x2 || window[cut[t]].ly>=y2)) --t;
    if(t<=0) return (x2-x1)*(y2-y1);

    int res=0;
    if(window[cut[t]].lx>x1) {
        res+=solute(t-1,x1,y1,window[cut[t]].lx,y2);
    }
    if(window[cut[t]].ly>y1) {
        res+=solute(t-1,max(x1,window[cut[t]].lx),y1,min(x2,window[cut[t]].rx),window[cut[t]].ly);
    }
    if(window[cut[t]].rx<x2) {
        res+=solute(t-1,window[cut[t]].rx,y1,x2,y2);
    }
    if(window[cut[t]].ry<y2) {
        res+=solute(t-1,max(x1,window[cut[t]].lx),window[cut[t]].ry,min(x2,window[cut[t]].rx),y2);
    }
    return res;
}
void solve() {
    int x1,y1,x2,y2;
    while(scanf("%s",a+1)!=EOF) {
        if(a[1]=='w') {
            siji(i,4,strlen(a+1)) {
                if(a[i]<'0' || a[i] > '9') a[i]=' ';
            }
            sscanf(a+4,"%d%d%d%d",&x1,&y1,&x2,&y2);
            ins(x1,y1,x2,y2,a[3]);
        }
        else if(a[1]=='t') {
            top(a[3]);
        }
        else if(a[1]=='b') {
            bottom(a[3]);
        }
        else if(a[1]=='d') {
            del(a[3]);
        }
        else {
            f=0;
            int t=calc(a[3]);
            if(window[t].h==0) {puts("0.000");continue;}

            siji(i,1,62) {
                if(window[t].h>window[i].h && window[i].h!=0) cut[++f]=i;
            }
            int sa=solute(f,window[t].lx,window[t].ly,window[t].rx,window[t].ry);
            int sb=(window[t].ry-window[t].ly)*(window[t].rx-window[t].lx);
            printf("%.3lf\n",(double)sa/sb*100);
        }
    }
}
int main(int argc, char const *argv[])
{
    freopen("window.in","r",stdin);
    freopen("window.out","w",stdout);
    solve();
    return 0;
}