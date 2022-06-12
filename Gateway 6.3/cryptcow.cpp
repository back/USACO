/*
LANG: C++
PROG: cryptcow
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
string os="Begin the Escape execution at the Break of Dawn";
string a;
int st[60][10],pt[60];
bool flag;
bool ha[hash+3];
int id(char c) {
    if('a'<=c && c<='z') return c-'a'+1;
    if('A'<=c && c<='Z') return c-'A'+1+26;
    else return 53;
}
int ELFhash() {
    int l=0,len=a.length();
    unsigned int h=0,g;
    while(l!=len) {
        h=(h<<4)+a[l];//右移四位加上一个字符
        if(g=h&0xF0000000L) {//最高四位不为0
            h^=(g>>24);//最高四位和5~8位异或
            h &= ~g;//删除最高四位
        }
        ++l;
    }
    return h&0x7FFFFFFF;//处理成非负数
}
void get_st() {
    int len=os.length();
    xiaosiji(i,0,len) {
        st[id(os[i])][++pt[id(os[i])]]=i;
    }
}
bool check_substr() {
    int len=a.length();
    int s=0,t=0;
    for(int i=0;i<len;++i) {
        if(a[i]!='C' && a[i]!='O' && a[i]!='W') {
            if(a[i]!=os[i]) return 0;
        }
        else {
            if(a[i]!='C') return 0;
            else {s=i;break;}
        }
    }
    for(int i=len-1,los=os.length()-1;i>=0;--i,--los) {
        if(a[i]!='C' && a[i]!='O' && a[i]!='W') {
            if(a[i]!=os[los]) return 0;
        }
        else {
            if(a[i]!='W') return 0;
            else {t=i;break;}
        }
    }
    for(int i=s+1;i<t;++i) {

        int rt=i,to;
        while(rt!=len &&(a[rt]=='C' || a[rt]=='O' || a[rt]=='W') )++rt;
        if(rt==len) break;
        to=rt;
        while(to!=len && a[to]!='C' && a[to]!='O' && a[to]!='W') ++to;
        --to;
        bool f=0;
        int pos=id(a[rt]);
        siji(k,1,pt[pos]) {
            siji(j,rt,to) {
                if(st[pos][k]+j-rt>=os.length() ||
                    a[j]!=os[st[pos][k]+j-rt]) goto fail;
            }
            f=1;
            break;
            fail:;
        }
        if(!f) return 0;
        i=to;
    }
    return 1;
}
bool dfs() {
    if(a==os) return true;
    int h=ELFhash()%hash;
    if(ha[h]!=0) return false;
    ha[h]=1;
    int len=a.length();
    siji(i,1,len-1) {
        if(a[i]=='O') {
            siji(j,0,i) {
                if(a[j]=='C') {
                    gongzi(k,len-1,i+1) {
                        if(a[k]=='W') {
                            string temp=a;
                            a.replace(j,k-j+1,temp.substr(i+1,k-i-1)+temp.substr(j+1,i-j-1));
                            if(check_substr() && dfs()) return true;
                            a=temp;
                        }
                    }
                }
            }

        }
    }
    return false;
}
void solve() {
    getline(cin,a);
    get_st();
    int len=a.length();
    flag=1;
    int c=0,o=0,w=0;
    xiaosiji(i,0,len) {
        if(a[i]=='W') ++w;
        if(a[i]=='C') ++c;
        if(a[i]=='O') ++o;
    }
    if(c!=o || c!=w || w!=o) flag=0;
    if(len-c*3!=os.length()) flag=0;
    if(flag) flag=check_substr();

    if(!flag) {printf("0 0\n");return;}
    flag=dfs();
    if(flag) printf("1 %d\n",c);
    else printf("0 0\n");
}
int main(int argc, char const *argv[])
{
    freopen("cryptcow.in","r",stdin);
    freopen("cryptcow.out","w",stdout);
    solve();
    return 0;
}