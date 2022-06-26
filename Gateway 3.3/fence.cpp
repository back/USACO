/*
PROG:fence
LANG:C++
*/
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int maxn=510,maxm=1110;
int sum[10],tot[maxn];
int f[maxn][maxn];
int a[maxn][maxm],b[10],ans[maxm];
int cnt,n,x,y,maxx;
bool vis[maxn];

void close()
{
    fclose(stdin);
    fclose(stdout);
    exit(0);
}

void dfs(int k)
{

    for (int i=1;i<=maxn;i++)
    {
        if (f[k][i]>0)
        {
            f[k][i]--;
            f[i][k]--;
            dfs(i);
        }
    }
            cnt++;
            ans[cnt]=k;
}

void work()
{
    x=-100;
    for (int i=1;i<=maxx;i++)
        if (tot[i] % 2==1)
        {
            x=i;
            break;
        }
    if (x==-100)
    {
        for (int i=1;i<=maxx;i++)
        {
            if (tot[i]>0)
            {
                x=i;
                break;
            }
        }
    }
    dfs(x);
    for (int i=1;i<=cnt;i++)
        cout<<ans[cnt-i+1]<<endl;
}

void init ()
{
freopen("fence.in","r",stdin);
freopen("fence.out","w",stdout);
    scanf("%d",&n);
     memset(tot,0,sizeof(tot));
     memset(f,0,sizeof(f));
     maxx=0;
     for (int i=1;i<=n;i++)
     {
         scanf("%d %d",&x,&y);
         maxx=max(max(maxx,x),y);
         f[x][y]++;
         f[y][x]++;
         tot[x]++;
         tot[y]++;
    //     vis[x]=true;
    //     vis[y]=true;
     }

}

int main ()
{
    init();
    work();
    close();
    return 0;
}