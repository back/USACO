/*
LANG: C++
PROG: prime3
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define siji(i,x,y) for(int i=(x); i<=(y) ; ++i)
#define gongzi(j,x,y) for(int j=(x); j>=(y) ; --j)
#define ivorysi
using namespace std;
int n,fi;
int p[1005][6],sum,prime[50005],tot,all;
bool noprime[100005];
typedef struct {
    int l,r[200];
}RECORD200;
/*typedef struct {
    int l,r[50];
}RECORD50;*/
typedef struct {
    int l,r[20];
}RECORD20;
//.0-9 _ 1.3.7.9  - non-zero
RECORD200 pat1[10];//X..._ 4*10*10
RECORD200 pat2[10];//_.X._ 4*4*10
RECORD20 pat3[10][10];//X___Y 4*4
RECORD20 pat4[10][10][10];//-X.YZ 9
RECORD20 pat7[10][10][10];//X.Y.Z 10
RECORD20 pat8[10][10][10];//.XYZ_ 4
string sol[1005];
int marks[6][6];
bool check(int x) {
    if(x%2==0 || x%5==0) return 0;
    return 1;
}
void makeprime() {
    siji(i,2,99999) {
        if(!noprime[i]) {
            prime[++tot]=i;
            if(i>10000) {
                int temp=0;
                for(int k=1;k<=10000;k*=10) {
                    temp+=i/k%10;
                }
                if(temp==n) {
                    ++sum;
                    for(int k=1,m=5;k<=10000 && m>=1;k*=10,--m) {
                        p[sum][m]=i/k%10;
                    }
                    int t1,t2,t3,t4,t5;
                    t1=p[sum][1],t2=p[sum][2],t3=p[sum][3],t4=p[sum][4],t5=p[sum][5];
                    pat1[t1].r[++pat1[t1].l]=sum;
                    if(check(t1)) pat2[t3].r[++pat2[t3].l]=sum;
                    if(check(t2)&&check(t3)&&check(t4)) {
                        pat3[t1][t5].r[++pat3[t1][t5].l]=sum;
                    }
                    pat4[t2][t4][t5].r[++pat4[t2][t4][t5].l]=sum;
                    pat7[t1][t3][t5].r[++pat7[t1][t3][t5].l]=sum;
                    pat8[t2][t3][t4].r[++pat8[t2][t3][t4].l]=sum;
                }
            }
        }
        for(int j=1;j<=tot && i<100000/prime[j];++j) {
            noprime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
void addsolution() {
    ++all;
    siji(i,1,5) {
        siji(j,1,5) {
            sol[all].append(1,marks[i][j]+'0');
        }
    }
}
int num(int x) {
    int res=0;
    siji(i,1,5) res=res*10+p[x][i];
    return res;
}
void solve() {
    scanf("%d%d",&n,&fi);
    makeprime();
    int us,tj,tk,tm,tw,ty,tx,tq,temp,temp1,temp2;
    for(int i=1;i<=pat1[fi].l;++i) {
        memset(marks,0,sizeof(marks));
        us=pat1[fi].r[i];
        siji(iv,1,5) marks[iv][iv]=p[us][iv];
        tj=pat2[marks[3][3]].l;
        for(int j=1;j<=tj;++j) {
            us=pat2[marks[3][3]].r[j];
            siji(iv,1,5) marks[5-iv+1][iv]=p[us][iv];
            tk=pat3[marks[5][1]][marks[5][5]].l;
            for(int k=1;k<=tk;++k) {
                us=pat3[marks[5][1]][marks[5][5]].r[k];
                siji(iv,2,4) marks[5][iv]=p[us][iv];
                tm=pat4[marks[2][2]][marks[4][2]][marks[5][2]].l;
                for(int m=1;m<=tm;++m) {
                    us=pat4[marks[2][2]][marks[4][2]][marks[5][2]].r[m];
                    marks[1][2]=p[us][1];
                    marks[3][2]=p[us][3];
                    tw=pat4[marks[2][4]][marks[4][4]][marks[5][4]].l;
                    for(int w=1;w<=tw;++w) {
                        us=pat4[marks[2][4]][marks[4][4]][marks[5][4]].r[w];
                        marks[1][4]=p[us][1];
                        marks[3][4]=p[us][3];
                        marks[1][3]=0;
                        temp=0;
                        siji(iv,1,5) temp+=marks[1][iv];
                        marks[1][3]=n-temp;
                        if(marks[1][3]<1 || marks[1][3]>9) continue;
                        temp=0;
                        siji(iv,1,5) {
                            temp=temp*10+marks[1][iv];
                        }
                        if(noprime[temp]) continue;
                        ty=pat7[marks[1][3]][marks[3][3]][marks[5][3]].l;
                        for(int y=1;y<=ty;++y) {
                            us=pat7[marks[1][3]][marks[3][3]][marks[5][3]].r[y];
                            marks[2][3]=p[us][2];
                            marks[4][3]=p[us][4];
                            tx=pat8[marks[2][2]][marks[2][3]][marks[2][4]].l;
                            for(int x=1;x<=tx;++x) {
                                us=pat8[marks[2][2]][marks[2][3]][marks[2][4]].r[x];
                                marks[2][1]=p[us][1];
                                marks[2][5]=p[us][5];
                                tq=pat8[marks[4][2]][marks[4][3]][marks[4][4]].l;
                                for(int q=1;q<=tq;++q) {
                                    us=pat8[marks[4][2]][marks[4][3]][marks[4][4]].r[q];
                                    marks[4][1]=p[us][1];
                                    marks[4][5]=p[us][5];
                                    marks[3][1]=marks[3][5]=0;
                                    temp1=temp2=0;
                                    siji(iv,1,5) temp1+=marks[iv][1],temp2+=marks[iv][5];
                                    marks[3][1]=n-temp1;marks[3][5]=n-temp2;
                                    if(marks[3][1]<1 || marks[3][5]<1 ||marks[3][1]>9 || marks[3][5]>9)
                                        continue;
                                    temp1=temp2=0;
                                    siji(iv,1,5)
                                        temp1=temp1*10+marks[iv][1],temp2=temp2*10+marks[iv][5];
                                    if(noprime[temp1]||noprime[temp2]) continue;
                                    temp1=temp2=0;
                                    siji(iv,1,5)
                                        temp1=temp1*10+marks[3][iv],temp2+=marks[3][iv];
                                    if(noprime[temp1] || temp2!=n) continue;
                                    addsolution();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(all==0) puts("NONE");
    sort(sol+1,sol+all+1);
    siji(i,1,all) {
        for(int j=0;j<5;++j) {
            cout<<sol[i].substr(j*5,5)<<endl;
        }
        if(i!=all) puts("");
    }
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("prime3.in","r",stdin);
    freopen("prime3.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
    freopen("f1.out","w",stdout);
#endif
    solve();
    return 0;
}