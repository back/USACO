/*
LANG: C++
PROG: vans
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
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
struct bignum {
    vector<int> s;

    bignum operator =(string x) {
        s.clear();
        gongzi(i,x.length()-1,0) {
            s.push_back(x[i]-'0');
        }
        return *this;
    }
    bignum operator =(long long x) {
        s.clear();
        do {
            s.push_back(x%10);
            x/=10;
        }while(x>0);
        return *this;
    }
    bignum(string x) {
        *this=x;
    }
    bignum(long long x=0LL) {
        *this=x;
    }
    bignum operator + (const bignum b) const {
        bignum c;
        c.s.clear();
        for(int g=0,k=0;;++k) {
            if(g==0 && k>=b.s.size() && k>=s.size()) {break;}
            int x=g;
            if(k<b.s.size()) x+=b.s[k];
            if(k<s.size()) x+=s[k];
            c.s.push_back(x%10);
            g=x/10;
        }
        return c;
    }
    bignum operator - (const bignum b) const {
        bignum c;
        c.s.clear();
        for(int g=0,k=0;;++k) {
            if(g==0 && k>=s.size()) {break;}
            int x=s[k]-g;
            if(k<b.s.size()) x-=b.s[k];
            if(x<0) {g=1;x+=10;}
            else g=0;
            c.s.push_back(x);
        }
        return c;
    }
    bignum operator * (const bignum b) const {
        bignum c;
        int g=0,x;
        c.s.clear();
        siji(i,1,s.size()+b.s.size()+2) c.s.push_back(0);
        for(int i=0;i<s.size();++i) {
            for(int j=0;j<b.s.size();++j) {
                x=s[i]*b.s[j]+g+c.s[i+j];
                c.s[i+j]=x%10;
                g=x/10;
            }
            while(g!=0) {c.s[i+b.s.size()]=g;g=0;}
        }
        while(c.s[c.s.size()-1]==0) c.s.pop_back();
        return c;//没打返回值……
    }
    bignum &operator +=(const bignum b)  {
        *this=*this+b;
        return *this;
    }
    bignum &operator -=(const bignum b) {
        *this=*this-b;
        return *this;
    }
    bignum &operator *=(const bignum b) {
        *this=*this*b;
        return *this;
    }
    friend ostream& operator << (ostream &out, const bignum& x) {
          for(int i=x.s.size()-1;i>=0;--i) {
            out<<x.s[i];
          }
          return out;
    }
    friend istream& operator >> (istream &in,bignum &x) {
        string str;
        if(!(in>>str)) return in;
        x=str;
        return in;
    }
}f[1005],g[1005];
int n;
void solve() {
    scanf("%d",&n);
    g[1]=2;g[2]=2;g[3]=8;f[1]=0;f[2]=2;f[3]=4;
    siji(i,4,n) {
        g[i]=f[i-1]*bignum(2)+g[i-1]+g[i-2]-g[i-3];
        f[i]=f[i-1]+g[i-1];
    }
    cout<<f[n]<<endl;
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("vans.in","r",stdin);
    freopen("vans.out","w",stdout);
#else
    //freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}