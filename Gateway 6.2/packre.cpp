/*
LANG: C++
PROG: packrec
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
int n,area=inf;
vector<pii> v;
void record(pii t) {
    if(t.fi>t.se) swap(t.fi,t.se);
    if(t.fi*t.se==area) v.push_back(t);
    else if(t.fi*t.se<area) {
        v.clear();
        area=t.fi*t.se;
        v.push_back(t);
    }
}
struct data {
    int l,r;
}squ[5],rec[5];
inline void rotate(data &a) {
    swap(a.l,a.r);
}
bool used[5];
void calc() {
    pii w;
    //fi是竖边,se是横边
    //case 1
    w.fi=0;
    siji(i,1,4) w.fi=max(w.fi,rec[i].l);
    siji(i,1,4) w.se+=rec[i].r;
    record(w);
    //case 2
    int temp2=0;
    siji(i,1,3) temp2=max(rec[i].l,temp2);
    w.fi=rec[4].l+temp2;
    w.se=0;
    siji(i,1,3) w.se+=rec[i].r;
    w.se=max(w.se,rec[4].r);
    record(w);
    //case 3
    w.fi=max(rec[1].l,rec[2].l)+rec[3].l;
    w.fi=max(w.fi,rec[4].l);
    w.se=max(rec[3].r,rec[1].r+rec[2].r)+rec[4].r;
    record(w);
    //case 4,5
    w.fi=max(rec[1].l,rec[2].l);
    w.fi=max(w.fi,rec[3].l+rec[4].l);
    w.se=rec[1].r+rec[2].r;
    w.se+=max(rec[3].r,rec[4].r);
    record(w);
    //case 6
    // 1 2
    // 3 4
    w.fi=max(rec[1].l+rec[3].l,rec[2].l+rec[4].l);
    w.se=rec[3].r+rec[4].r;
    // 1与2
    if(rec[1].l+rec[3].l>rec[4].l) w.se=max(w.se,rec[1].r+rec[2].r);
    // 2与3
    if(rec[3].l>rec[4].l) w.se=max(w.se,rec[2].r+rec[3].r);
    // 1与4
    if(rec[4].l>rec[3].l) w.se=max(w.se,rec[1].r+rec[4].r);
    // 1 或 2 特别长
    w.se=max(w.se,rec[1].r);
    w.se=max(w.se,rec[2].r);
    record(w);
}
void dfs1(int k) {
    if(k>4) {
        calc();
        return;
    }
    dfs1(k+1);//不转这个
    rotate(rec[k]);
    dfs1(k+1);//转这个
    rotate(rec[k]);
}
void dfs(int k) {
    if(k>4) {
        dfs1(1);
    }
    siji(i,1,4) {
        if(!used[i]) {
            rec[k]=squ[i];
            used[i]=1;
            dfs(k+1);
            used[i]=0;
        }
    }
}
void solve() {
    siji(i,1,4) scanf("%d%d",&squ[i].l,&squ[i].r);
    dfs(1);
    sort(v.begin(),v.end());
    vector<pii>::iterator it=unique(v.begin(),v.end());
    v.erase(it,v.end());
    printf("%d\n",area);
    siji(i,0,v.size()-1) {
        printf("%d %d\n",v[i].fi,v[i].se);
    }
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}