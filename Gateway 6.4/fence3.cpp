/*
LANG: C++
PROG: fence3
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define siji(i,x,y) for(int i=(x); i<=(y) ; ++i)
#define ivorysi
#define o(x) ((x)*(x))
using namespace std;
typedef long long ll;
int f;
struct data{
    int xs,ys,xt,yt;
}seg[155];
void init() {
    scanf("%d",&f);
    siji(i,1,f) {
        scanf("%d%d%d%d",&seg[i].xs,&seg[i].ys,&seg[i].xt,&seg[i].yt);
        if(seg[i].xt<seg[i].xs) swap(seg[i].xt,seg[i].xs);
        if(seg[i].yt<seg[i].ys) swap(seg[i].yt,seg[i].ys);
    }
}
double dist(double x,double y) {
    double res=0.0;
    siji(i,1,f) {
        double xid=min(fabs(seg[i].xt-x),fabs(seg[i].xs-x));
        if(x>=seg[i].xs && x<=seg[i].xt) xid=0;
        double yid=min(fabs(seg[i].yt-y),fabs(seg[i].ys-y));
        if(y>=seg[i].ys && y<=seg[i].yt) yid=0;
        res+=sqrt(o(xid)+o(yid));
    }
    return res;
}
void solve() {
    init();
    //if(n==7) {cout<<"12198297600"<<endl;return;}
    double elecx=0.0,elecy=0.0;
    double direx[4]={1.0,0.0,-1.0,0.0},direy[4]={0.0,1.0,0.0,-1.0};
    double T=20.0;
    double bestnum=dist(0.0,0.0);
    siji(b,1,50) {
        if(b%10==0) T*=0.1;
        int best=-1;
        siji(i,0,3) {
            elecx+=direx[i]*T;
            elecy+=direy[i]*T;
            double temp=dist(elecx,elecy);
            if(temp<bestnum)
                bestnum=temp,best=i;
            elecx-=direx[i]*T;
            elecy-=direy[i]*T;
        }
        if(best!=-1) {
            elecx+=direx[best]*T;
            elecy+=direy[best]*T;
        }
        bestnum=dist(elecx,elecy);
    }
    printf("%.1lf %.1lf %.1lf\n",elecx,elecy,bestnum);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("fence3.in","r",stdin);
    freopen("fence3.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
    //freopen("f1.out","w",stdout);
#endif
    solve();
    return 0;
}