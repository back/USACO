/*
LANG: C++
TASK: lgame
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
#define inf 0x7fffffff
#define ivorysi
#define mo 97797977
#define hash 974711
#define base 47
#define pss pair<string,string>
#define MAXN 30005
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
struct node {
    node *le[28];
    int end;
    node() {
        memset(le,0,sizeof(le));
        end=0;
    }
}*root;
int val[26]= {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
char word[10],len;
int used[10],ans;
vector< pss > astr;
void ins(char *s){
    int l=strlen(s+1);
    node *p=root;
    siji(i,1,l) {
        if(p->le[s[i]-'a']==0) {
            p->le[s[i]-'a']=new node;
        }
        p=p->le[s[i]-'a'];
    }
    p->end=1;
}
void init() {
    char str[10];
    scanf("%s",word+1);
    len=strlen(word+1);
    root=new node;
    FILE *fin  = fopen ("lgame.dict", "r");
    while(fscanf(fin,"%s",str+1) && str[1]!='.') {
        ins(str);
    }
}
int srch(string str) {
    if(str.length()==0) return 0;
    node *p=root;
    int gz=0;
    //____
    //if(str=="ag") gz=1;
    //_____
    int flag=1;
    int res=0;
    //if(gz) printf("%d\n",str.length());
    xiaosiji(i,0,str.length()) {
        //if(gz)printf("%d %d %d\n",i,flag,res);
        /*if(gz) {
            printf("-----------\n");
            siji(i,0,25) {
                printf("%d %c\n",p->le[i],i+'a');
            }
        }*/
        if(p->le[str[i]-'a']==0) {
            flag=-1000;
            break;
        }
        else {
            p=p->le[str[i]-'a'];
            res+=val[str[i]-'a'];

        }
    }
    if(p->end == 0) flag=-1000;
    return flag*res;

}
void calc(string str,int l) {
    xiaosiji(i,0,l) {
        int temp=srch(str.substr(0,i+1))+srch(str.substr(0+i+1,233));
        if(temp>ans) {
            astr.clear();
            astr.push_back(make_pair(str.substr(0,i+1),str.substr(0+i+1,233)));
            int k=astr.size();
            if(astr[k-1].fi>astr[k-1].se && astr[k-1].se!=""){
                swap(astr[k-1].fi,astr[k-1].se);
            }
            ans=temp;
        }
        else if(temp==ans) {
            astr.push_back(make_pair(str.substr(0,i+1),str.substr(0+i+1,233)));
            int k=astr.size();
            if(astr[k-1].fi>astr[k-1].se && astr[k-1].se!=""){
                swap(astr[k-1].fi,astr[k-1].se);
            }
        }
    }
}
void dfs(string str,int l) {
    if(l>len) return;
    siji(i,1,len) {
        if(!used[i]) {
            str.append(1,word[i]);
            used[i]=1;
            calc(str,l+1);
            dfs(str,l+1);
            used[i]=0;
            str.erase(l,1);
        }
    }
}
void solve() {
    init();
    dfs("",0);
    sort(astr.begin(),astr.end());
    vector<pss >::iterator iter=unique(astr.begin(),astr.end());
    astr.erase(iter,astr.end());
    printf("%d\n",ans);
    xiaosiji(i,0,astr.size()) {
        cout<<astr[i].fi;
        if(astr[i].se!="") {
            cout<<" "<<astr[i].se;
        }
        puts("");
    }
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("lgame.in","r",stdin);
    freopen("lgame.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}