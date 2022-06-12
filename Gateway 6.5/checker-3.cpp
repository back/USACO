/*
TASK: checker
LANG: C++
*/
#include<cstdio>
using namespace std;
int n,ans;
int a[100],b[100],c[100],d[100];
void out()
{
    if(ans<=2)
    {
        for(int i=1;i<n;i++)
            printf("%d ",a[i]);
        printf("%d",a[n]);
        puts("");
    }
    ans++;
}
void dfs(int x)
{
    if(x==n+1)
    {
        out();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0 && c[x+i]==0 && d[x-i+n]==0)
        {
            a[x]=i;
            b[i]=1;
            c[x+i]=1;
            d[x-i+n]=1;
            dfs(x+1);
            b[i]=0;
            c[x+i]=0;
            d[x-i+n]=0;
        }
    }
}
int main()
{
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d",&n);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
