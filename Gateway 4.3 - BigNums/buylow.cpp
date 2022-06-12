/*
PROG:buylow
LANG:C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#define inf 0x7fffffff
#define ivorysi
#define siji(i,x,y) for(int i=(x);i<=(y);++i)
#define gongzi(j,x,y) for(int j=(x);j>=(y);--j)
#define xiaosiji(i,x,y) for(int i=(x);i<(y);++i)
#define sigongzi(j,x,y) for(int j=(x);j>(y);--j)
using namespace std;
struct bignum {
    vector<int> s;
    bignum operator =(int x) {
        s.clear();
        do {
            s.push_back(x%10);
            x/=10;
        }while(x>0);
        return *this;
    }
    bignum operator + (const bignum &b) const {
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
    bignum &operator +=(const bignum &b)  {
        *this=*this+b;
        return *this;
    }
}d[5005];
ostream& operator << (ostream &out, const bignum& x) {
  gongzi(i,x.s.size()-1,0) {
    out<<x.s[i];
  }
  return out;
}
int n,a[5005],f[5005],ans,ans1,follow[5005];
void solve() {
    scanf("%d",&n);
    siji(i,1,n) scanf("%d",&a[i]);
    ++n;
    a[n]=0;
    siji(i,1,n) {f[i]=1;d[i]=0;}
    siji(i,1,n) {
        siji(j,i+1,n) {
            if(a[i]>a[j]) {
                if(f[i]+1>f[j]) {
                    f[j]=f[i]+1;
                }
            }
        }
    }
    siji(i,1,n) {
        siji(j,i+1,n) {
            if(a[i]==a[j]) {follow[i]=j;break;}
        }
    }
    siji(i,1,n) {
        if(f[i]==1) d[i]=1;
        xiaosiji(j,1,i) {
            if(a[j]>a[i]) {
                if(f[j]+1==f[i] && (follow[j]==0 || follow[j]>i)) {
                    d[i]=d[i]+d[j];
                }
            }
        }
    }
    printf("%d ",f[n]-1);
    cout<<d[n]<<endl;
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("buylow.in","r",stdin);
    freopen("buylow.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}