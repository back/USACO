/*
LANG: C++
PROG: checker

Submit: test 8 timeout...
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define siji(i,x,y) for(int i=(x) ; i <= (y) ; ++i)
#define xiaosiji(i,x,y) for(int i = (x) ; i < (y); ++i)
#define gongzi(j,x,y) for(int j = (x) ; j >= (y) ; --j)
#define ivorysi
#define mo 11447
#define eps 1e-8
#define o(x) ((x)*(x))
using namespace std;
typedef long long ll;
int LeftDiagonal,RightDiagonal,Column;
int rec[15];
int n,ans,cnt;
void Print() {
    siji(i,1,n) {
        printf("%d%c",rec[i]," \n"[i==n]);
    }
}
void dfs(int k) {
    if(k>n) {
        ++ans;
        if(cnt<3) {++cnt;Print();}
    }
    siji(i,1,n){
        if((LeftDiagonal>>(k+i)&1)==0 && (RightDiagonal>>(k+n-i+1)&1)==0 && (Column>>i&1)==0 ){
            rec[k]=i;
            LeftDiagonal|=(1<<(k+i));
            RightDiagonal|=(1<<(k+n-i+1));
            Column|=(1<<i);
            dfs(k+1);
            LeftDiagonal^=(1<<(k+i));
            RightDiagonal^=(1<<(k+n-i+1));
            Column^=(1<<i);
        }
    }
}
void solve() {
    scanf("%d",&n);
    dfs(1);
    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    solve();
    return 0;
}