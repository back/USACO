/*
PROG: range
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#define name "range"
using namespace std;
int a[255][255];
int dp[255][255],cnt[255];
int main()
{
    freopen(name ".in","r",stdin);
    freopen(name ".out","w",stdout);
    int i,j,k,n;char c;
    cin>>n;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
        cin>>c;
        if (c=='1') a[i][j]=1;
      }
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            if (a[i][j]==1)
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
    for (i=1;i<=n;i++)        
        for (j=1;j<=n;j++)
            for (k=2;k<=dp[i][j];k++)
                cnt[k]++;
    for (i=2;i<=n;i++)
        if (cnt[i]!=0) cout<<i<<" "<<cnt[i]<<endl;
    return 0;
}