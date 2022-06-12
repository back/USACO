/*
PROG:job
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
#define siji(i,x,y) for(int i=(x);i<=(y);++i)
#define gongzi(j,x,y) for(int j=(x);j>=(y);--j)
#define xiaosiji(i,x,y) for(int i=(x);i<(y);++i)
#define sigongzi(j,x,y) for(int j=(x);j>(y);--j)
using namespace std;
int n,m1,m2;
int a[35],b[35],usea[35],useb[35];
int spa[1005],spb[1005],ans;
void init() {
    scanf("%d%d%d",&n,&m1,&m2);
    siji(i,1,m1) {
        scanf("%d",&a[i]);
    }
    siji(i,1,m2) {
        scanf("%d",&b[i]);
    }
}
void solve() {
    init();
    int mina,ida,minb,idb;
    siji(i,1,n) {
        mina=usea[1]+a[1];ida=1;
        minb=useb[1]+b[1];idb=1;
        siji(j,2,m1) {
            if(usea[j]+a[j]<mina) {
                mina=usea[j]+a[j];
                ida=j;
            }
        }
        siji(j,2,m2) {
            if(useb[j]+b[j]<minb) {
                minb=useb[j]+b[j];
                idb=j;
            }
        }
        usea[ida]=mina;
        useb[idb]=minb;
        spa[i]=mina;
        spb[i]=minb;
    }
    siji(i,1,n) {
        ans=max(ans,spa[i]+spb[n-i+1]);
    }
    printf("%d %d\n",mina,ans);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}