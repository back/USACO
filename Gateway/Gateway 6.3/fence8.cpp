/*
LANG: C++
PROG: fence8
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
#define esp 1e-8
typedef long long ll;
using namespace std;
int n,r;
int bag[55],sp;
int wood[1505],sum[1505],mid,now;
bool used[1505];
void init() {
    scanf("%d",&n);
    siji(i,1,n) {
        scanf("%d",&bag[i]);
        sp+=bag[i];
    }
    sort(bag+1,bag+n+1);
    scanf("%d",&r);
    siji(i,1,r) {
        scanf("%d",&wood[i]);
    }
    sort(wood+1,wood+r+1);
    siji(i,1,r) {
        sum[i]=sum[i-1]+wood[i];
    }
}
bool dfs(int k,int pred) {
    if(k<=0) return 1;
    if(sp<sum[k]) return 0;
    sp-=wood[k];
    for(int i= k<mid&&wood[k]==wood[k+1] ?pred:1 ;i<=n;++i) {
        //有两个相同长度的木板需要切，让它们以一种非降序的顺序切出来
        if(bag[i]==bag[i-1]) continue;//这个木料和前一个一样，那么切之后会搜出来一个一模一样的结果
        if(bag[i]>=wood[k]) {
            bag[i]-=wood[k];
            if(bag[i]<wood[1]) sp-=bag[i];//这个木料不能切除任何一块木板了
            if(dfs(k-1,i)) {
                if(bag[i]<wood[1]) sp+=bag[i];
                sp+=wood[k];
                bag[i]+=wood[k];
                return 1;
            }
            if(bag[i]<wood[1]) sp+=bag[i];
            bag[i]+=wood[k];
        }
    }
    sp+=wood[k];
    return 0;
}
int binary() {
    int left=0,right=r;
    while(left<right) {
        mid=(left+right+1)>>1;
        if(sum[mid]>sp || wood[mid]>bag[n]) {right=mid-1;continue;}
        if(dfs(mid,0)) left=mid;
        else right=mid-1;
    }
    return left;
}
void solve() {
    init();
    printf("%d\n",binary());
}
int main(int argc, char const *argv[])
{
    freopen("fence8.in","r",stdin);
    freopen("fence8.out","w",stdout);
    solve();
    return 0;
}