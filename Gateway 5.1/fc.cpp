/*
LANG: C++
TASK: fc
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
struct vec {
    double x,y;
    vec(double x=0.0,double y=0.0) :x(x),y(y) {}
    vec operator - (const vec &b) const{
        return vec(x-b.x,y-b.y);
    }
    double norm() const{
        return x*x+y*y;
    }
}a[10005];
int n;
bool dcmp(double a,double b=0.0) {
    return fabs(a-b) < esp ? 1 :0 ;
}
double cross(vec a,vec b) {
    return  a.x*b.y-a.y*b.x;
}
inline bool cmp(const vec &c,const vec &d) {
    vec t1= c-a[1],t2=d-a[1];
    double t=cross(t1,t2);
    if(!dcmp(t)) return t>0;//逆时针为正，顺时针为负
    else return c.norm()<d.norm();
}
double o(double a){
    return a*a;
}
struct poly {
    vector<vec> poi;
    double peri() {
        double res=0.0;
        siji(i,1,poi.size()-1) {
            res+=sqrt(o(poi[i].x-poi[i-1].x)+o(poi[i].y-poi[i-1].y));
        }
        res+=sqrt(o(poi[0].x-poi[poi.size()-1].x)+o(poi[0].y-poi[poi.size()-1].y));
        return res;
    }
    void convex() {
        int id=1;
        siji(i,2,n) {
            if(a[i].x<a[id].x || (a[i].x==a[id].x && a[i].y<a[id].y)) {
                id=i;
            }
        }
        if(id!=1) swap(a[id],a[1]);
        sort(a+2,a+1+n,&cmp);
        poi.push_back(a[1]);
        siji(i,2,n) {
            while(poi.size() >=2 &&
                cross(poi[poi.size()-1]-poi[poi.size()-2],a[i]-poi[poi.size()-1])<=0)
                poi.pop_back();
            poi.push_back(a[i]);
        }
    }
}tw;

void solve() {
    scanf("%d",&n);
    siji(i,1,n) {
        scanf("%lf%lf",&a[i].x,&a[i].y);
    }
    tw.convex();
    printf("%.2lf\n",tw.peri());
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("fc.in","r",stdin);
    freopen("fc.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}