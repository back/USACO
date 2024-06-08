/*
LANG: C++
PROG: cowxor
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
int pop[100005][2],best[100005],a[100005],xr[100005],n,e,t;
int tmp[2];
void solve() {
    scanf("%d",&n);
    siji(i,1,n) {
        scanf("%d",&a[i]);
        xr[i]=xr[i-1]^a[i];
        best[i]=i-1;
        pop[i][0]=i-1;
        pop[i][1]=-1;
    }
    pop[0][0]=-1;pop[0][1]=-1;best[0]=-1;
    e=22;
    bool one;
    while(e--) {
        siji(i,1,n) {
            if(pop[i][0]==-1) {
                pop[i][1]=-1;
            }
            else {
                if(xr[pop[i][0]] >> e != xr[i] >> e) {
                    tmp[0]=pop[pop[i][0]][1];
                    /*pop[pop[i][0]]已经计算好了，
                    xr[pop[pop[i][0]][1]]的[e+1,22]与xr[pop[i][0]]相同
                    第e位不同，然而现在这种情况正好需要第e位与xr[pop[i][0]]不同
                    */
                    tmp[1]=pop[i][0];
                    /*
                    正好满足前[e+1,22]位相同，第e位不同
                    */
                }
                else {
                    tmp[0]=pop[i][0];
                    /*
                    正好满足前[e,22]位相同
                    */
                    tmp[1]=pop[pop[i][0]][1];
                    /*pop[pop[i][0]]已经计算好了，
                    xr[pop[pop[i][0]][1]]的[e+1,22]与xr[pop[i][0]]相同
                    第e位不同，然而现在这种情况正好需要第e位与xr[pop[i][0]]不同
                    */
                }
                pop[i][0]=tmp[0];
                pop[i][1]=tmp[1];
            }
        }
        one=false;
        siji(i,1,n) {
            if(best[i]>=0) {
                if((xr[best[i]]>>e)%2 != (xr[i]>>e)%2 || pop[best[i]][1]>=0) {
                    /*
                    如果e位不相同或者还可以找到更新的说明e位可以为1
                    */
                    one=true;break;
                }
            }
        }
        if(one) {
            siji(i,1,n) {
                if(best[i]>=0) {
                    if((xr[best[i]]>>e)%2 == (xr[i]>>e)%2) {
                        best[i]=pop[best[i]][1];
                    }
                }
            }

        }
    }
    for(t=1;best[t]<0;++t);
    printf("%d %d %d\n",xr[t]^xr[best[t]],best[t]+1,t);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("cowxor.in","r",stdin);
    freopen("cowxor.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}