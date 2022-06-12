/*
LANG: C++
PROG: calfflac
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
char str[40005],cmp[40005];
int l,cnt,pos[40005];
void init() {
    char t[105];
    t[81]='\0';
    while(fgets(t+1,80,stdin)!=NULL) {
        strcat(str+1,t+1);
        //str[strlen(str+1)]='\0';
    }
    l=strlen(str+1);
    cmp[0]='%';
    cmp[++cnt]='@';
    siji(i,1,l) {
        if(str[i]>='a' && str[i] <='z') {
            cmp[++cnt]=str[i];
            pos[cnt]=i;
            cmp[++cnt]='@';
        }
        else if(str[i]>='A' && str[i] <='Z') {
            cmp[++cnt]=str[i]-'A'+'a';
            pos[cnt]=i;
            cmp[++cnt]='@';
        }
    }
    cmp[cnt+1]='%';
    cmp[cnt+2]='\0';
}
int p[40005],id,mx;
void solve() {
    init();
    siji(i,1,cnt) {
        if(mx>i) {
            p[i]=min(p[id*2-i],mx-i+1);
            //要么就是对称的部分，如果它对称点长度超过了最大回文串的左边界，那就用右边界减去i
        }
        else {
            p[i]=1;
        }
        for(;cmp[i+p[i]]==cmp[i-p[i]];++p[i]) ;
        if(mx<i+p[i]-1) {
            mx=i+p[i]-1;
            id=i;
        }
    }
    id=1;
    siji(i,1,cnt) {
        if(p[id]<p[i]) id=i;
    }
    int ansl,ansr;
    if(cmp[id+p[id]-1]!='@') ansr=pos[id+p[id]-1];
    else  ansr=pos[id+p[id]-2];
    str[ansr+1]='\0';
    if(cmp[id-p[id]+1]!='@') ansl=pos[id-p[id]+1];
    else ansl=pos[id-p[id]+2];
    printf("%d\n%s\n",p[id]-1,str+ansl); 
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}