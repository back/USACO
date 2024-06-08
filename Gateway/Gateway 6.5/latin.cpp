/*
LANG: C++
PROG: latin
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
int n;
int col[10],row[10],num[10][10];
bool v[10];
ll ans,h[50][5];//置换圈的长度乘积，个数
void init() {
    scanf("%d",&n);
    siji(i,1,n) {
        num[1][i]=i;
        num[i][1]=i;
        col[i]=(1<<i);
        row[i]=(1<<i);
    }
    memset(h,-1,sizeof(h));
}

ll dfs(int x,int y) {
    if(x>=n){
        return 1;
    }
    ll res=0;
    if(x==3&&y==2) {
        memset(v,0,sizeof(v));
        int cnt=0,len=1;
        siji(i,1,n) {
            if(v[i]) continue;
            v[i]=1;
            int rec=1;
            for(int l=num[2][i];l!=i;l=num[2][l]) {
                v[l]=1;
                ++rec;
            }
            len*=rec;
            ++cnt;
        }
        if(h[len][cnt]!=-1) return h[len][cnt];
        siji(i,1,n) {
            if(((col[y]&(1<<i))==0) && ((row[x]&(1<<i))==0)) {
                col[y]|=(1<<i);
                row[x]|=(1<<i);
                num[x][y]=i;
                if(y==n) res+=dfs(x+1,2);
                else res+=dfs(x,y+1);
                col[y]^=(1<<i);
                row[x]^=(1<<i);
                num[x][y]=0;
            }
        }
        return h[len][cnt]=res;
    }
    siji(i,1,n) {
        if(((col[y]&(1<<i))==0) && ((row[x]&(1<<i))==0)) {
            col[y]|=(1<<i);
            row[x]|=(1<<i);
            num[x][y]=i;
            if(y==n) res+=dfs(x+1,2);
            else res+=dfs(x,y+1);
            col[y]^=(1<<i);
            row[x]^=(1<<i);
            num[x][y]=0;
        }
    }
    return res;
}
void solve() {
    init();
    //if(n==7) {cout<<"12198297600"<<endl;return;}
    ans=dfs(2,2);
    siji(i,1,n-1) ans*=i;
    printf("%lld\n",ans);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("latin.in","r",stdin);
    freopen("latin.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
    //freopen("f1.out","w",stdout);
#endif
    solve();
    return 0;
}