/*
LANG: C++
PROG: cowcycle
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#define siji(i,x,y) for(int i=(x);i<=(y);++i)
#define gongzi(j,x,y) for(int j=(x);j>=(y);--j)
#define xiaosiji(i,x,y) for(int i=(x);i<(y);++i)
#define sigongzi(j,x,y) for(int j=(x);j>(y);--j)
#define inf 0x5f5f5f5f
#define ivorysi
#define mo 97797977
#define hash 974711
#define base 47
#define fi first
#define se second
#define pii pair<int,int>
#define esp 1e-10
typedef long long ll;
using namespace std;
int f,r;
int f1,f2,r1,r2;
int numf[15],numr[15],ansf[15],ansr[15];
double line[55],sub[55],ans;
void calc() {
    if(numf[f]*numr[r] < numf[1]*numr[1]*3) return;
    siji(i,1,f) {
        siji(j,1,r) {
            line[(i-1)*r+j]=(double)numf[i]/numr[j];
        }
    }
    sort(line+1,line+f*r+1);
    double aver=0.0,cal=0.0;
    siji(i,1,f*r-1) {
        sub[i]=fabs(line[i+1]-line[i]);
        aver+=sub[i]/(f*r-1);
    }
    siji(i,1,f*r-1) {
        cal+=(sub[i]-aver)*(sub[i]-aver)/(f*r-1);
    }
    if(fabs(cal-ans)>esp && cal<ans) {
        memcpy(ansf,numf,sizeof(ansf));
        memcpy(ansr,numr,sizeof(ansr));
        ans=cal;
    }
}
void dfs2(int k,int prev) {
    siji(i,prev,r2) {
        numr[k]=i;
        if(k==r) calc();
        else dfs2(k+1,i+1);
    }
}
void dfs1(int k,int prev) {
    siji(i,prev,f2) {
        numf[k]=i;
        if(k==f) dfs2(1,r1);
        else dfs1(k+1,i+1);
    }
}
void init() {
    scanf("%d%d",&f,&r);
    scanf("%d%d%d%d",&f1,&f2,&r1,&r2);
}
void solve() {
    init();
    ans=10000000.0;
    dfs1(1,f1);
    siji(i,1,f) printf("%d%c",ansf[i]," \n"[i==f]);
    siji(i,1,r) printf("%d%c",ansr[i]," \n"[i==r]);
}
int main(int argc, char const *argv[])
{
    freopen("cowcycle.in","r",stdin);
    freopen("cowcycle.out","w",stdout);
    solve();
    return 0;
}