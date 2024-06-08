/*
LANG: C++
TASK: theme
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
#define MAXN 5000
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
using namespace std;
int h[5005];
int e[5005];
int num[5005],n,lis[5005],f[5005],ans;
vector<int> v[200];
bool check(int s1,int s2,int len) {
    if(s1+len > n+1 || s2+len > n+1) return false;
    return ((ll)e[MAXN-s1]*(h[s1+len-1]-h[s1-1])-(ll)e[MAXN-s2]*(h[s2+len-1]-h[s2-1]))%mo==0;
}
void init() {
    scanf("%d",&n);
    siji(i,1,n) {
        scanf("%d",&num[i]);
    }
    --n;
    siji(i,1,n) {
        lis[i]=num[i+1]-num[i]+88;
        v[lis[i]].push_back(i);
    }
    siji(i,0,180) {
        if(!v[i].empty()) {
            sort(v[i].begin(),v[i].end());
        }
    }
    e[0]=1;
    siji(i,1,5000) {
        e[i]=(ll)e[i-1]*base%mo;
    }
    siji(i,1,n) {
        h[i]=((ll)h[i-1]+(ll)lis[i]*e[i]%mo)%mo;
    }
}
int binary(int s1,int s2,int minz,int maxz) {
    if(maxz<=minz) return -1;
    if(maxz<=ans) return -1;
    int l=minz,r=maxz;
    while(l<r) {
        int mid=(l+r+1)>>1;
        if(check(s1,s2,mid)) l=mid;
        else {
            r=mid-1;
            if(r<=ans) return -1;
        }
    }
    return l;
}
void solve() {
    init();
    siji(i,0,180) {
        if(v[i].empty() || v[i].size()==1) continue;
        xiaosiji(j,0,v[i].size()) {
            if(f[v[i][j]-1]>=2) f[v[i][j]]=f[v[i][j]-1]-1;
            else f[v[i][j]]=1;
            xiaosiji(k,j+1,v[i].size()) {
                int x=binary(v[i][j],v[i][k],f[v[i][j]],v[i][k]-v[i][j]-1);
                f[v[i][j]]=max(f[v[i][j]],x);
                f[v[i][k]]=max(f[v[i][k]],x);
            }
            ans=max(ans,f[v[i][j]]);
        }
    }
    ++ans;
    if(ans<5) puts("0");
    else {
        printf("%d\n",ans);
    }
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("theme.in","r",stdin);
    freopen("theme.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}