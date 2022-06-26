/*
PROG: fence6
LANG: C++
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
#define inf 0x1f1f1f1f
#define ivorysi
#define mo 97797977
#define ha 974711
#define ba 47
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long ll;
int s,len[105],num[105][4],cnt,a1[105],a2[105],use[105];
int g[205][205],f[205][205];
int n,t1,t2,ans;
void solve(){
    scanf("%d",&n);
    siji(i,1,n) {
        scanf("%d",&s);
        scanf("%d",&len[s]);
        scanf("%d%d",&t1,&t2);

        bool f1=1,f2=1;
        siji(j,1,t1) {
            scanf("%d",&a1[j]);
            if(use[a1[j]]) f1=0;
        }
        siji(j,1,t2) {
            scanf("%d",&a2[j]);
            if(use[a2[j]]) f2=0;
        }
        if(num[s][0]>=2)continue;
        if(f1) {
            num[s][++num[s][0]]=++cnt;
            siji(j,1,t1) {
                num[a1[j]][++num[a1[j]][0]]=cnt;
            }
        }
        if(f2) {
            num[s][++num[s][0]]=++cnt;
            siji(j,1,t2) {
                num[a2[j]][++num[a2[j]][0]]=cnt;
            }
        }
        use[s]=1;
    }
    memset(g,inf,sizeof(g));
    memset(f,inf,sizeof(f));
    siji(i,1,n) {
        g[num[i][1]][num[i][2]]=g[num[i][2]][num[i][1]]=len[i];
        f[num[i][1]][num[i][2]]=f[num[i][2]][num[i][1]]=len[i];
    }
    siji(i,1,cnt) {g[i][i]=0;f[i][i]=0;}
    ans=inf;
    siji(k,1,cnt) {
        xiaosiji(i,1,k) {//因为不能用k点所以是<k
            xiaosiji(j,i+1,k) {
                ans=min(ans,g[i][j]+f[i][k]+f[k][j]);
            }
        }
        siji(i,1,cnt) {
            siji(j,1,cnt) {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }

    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("fence6.in","r",stdin);
    freopen("fence6.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
}