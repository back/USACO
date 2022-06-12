/*
LANG: C++
PROG: betsy
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define siji(i,x,y) for(int i=(x) ; i <= (y) ; ++i)
#define xiaosiji(i,x,y) for(int i = (x) ; i < (y); ++i)
#define gongzi(j,x,y) for(int j = (x) ; j >= (y) ; --j)
#define ivorysi
#define mo 11447
#define eps 1e-8
#define o(x) ((x)*(x))
using namespace std;
typedef long long ll;
/*
0:#
1:(
2:)
3:
*/
int n,ans;
int sum[2][66000],hush[66000],code[2][66000],base[10],tot[2];
//用hash是因为可能会有不同的原始状态转移到同一个新状态
//sum存储的是code[cur][i]情况数总和
//code[cur][i]是四进制的压位后的编码
void put_in_hash(int cur,int op,int data) {
    if(!hush[op]) {
        code[cur][++tot[cur]]=op;
        hush[op]=tot[cur];
    }
    sum[cur][hush[op]]+=data;
}//这题很小，hash直接开就好，要不然还得挂link不断取模什么的
int Change_state(int state,int pos,int val) {
    return state+val*(1<<base[pos]);
}
int Get(int state,int pos) {
    return (state>>base[pos])&3;
}
void solve() {
    scanf("%d",&n);
    if(n==1) {puts("1");return;}
    base[1]=0;
    siji(i,2,9) {
        base[i]=base[i-1]+2;
    }
    int cur=0;
    code[0][1]=Change_state(code[0][1],1,1);
    code[0][1]=Change_state(code[0][1],n,2);//把多添的一行的第一个设成1，第n个设成2，求回路
    sum[cur][1]=1,tot[cur]=1;
    siji(i,1,n) {
        siji(j,1,n) {
            cur^=1;//换情况
            tot[cur]=0;
            memset(hush,0,sizeof(hush));
            memset(sum[cur],0,sizeof(sum[cur]));
            siji(k,1,tot[cur^1]) {
                int state=code[cur^1][k];
                if(j==1) state<<=2;//移到1这一位相当于多了一个轮廓线
                int p=Get(state,j+1),q=Get(state,j);//p上方 q左方
                state=Change_state(state,j+1,-1*p);state=Change_state(state,j,-1*q);
                //将拿出来的p、q删除
                if(p==0 && q==0) {
                    if(j!=n && i!=n) {
                        int change=Change_state(state,j,1);//向下延伸
                        change=Change_state(change,j+1,2);//向右延伸
                        put_in_hash(cur,change,sum[cur^1][k]);
                    }
                }
                if(p==0 && q>0) {
                    if(j!=n){
                        int change=Change_state(state,j+1,q);//向右延伸
                        put_in_hash(cur,change,sum[cur^1][k]);
                    }
                    if(i!=n) {
                        int change=Change_state(state,j,q);//向下延伸
                        put_in_hash(cur,change,sum[cur^1][k]);
                    }
                }
                if(p>0 && q==0) {
                    if(j!=n) {
                        int change=Change_state(state,j+1,p);//向右延伸
                        put_in_hash(cur,change,sum[cur^1][k]);
                    }
                    if(i!=n) {
                        int change=Change_state(state,j,p);//向下延伸
                        put_in_hash(cur,change,sum[cur^1][k]);
                    }
                }
                if(p==1 && q==1) {
                    int change=state,l,top;
                    for(l = j+2 ,top=1;top;++l) {
                        if(Get(change,l)==1) ++top;
                        if(Get(change,l)==2) --top;
                    }
                    //不能直接找右侧第一个右括号，因为可能有这样((()))()()
                    //删掉前两个括号时，我们需要找第5个括号更改方向
                    change=Change_state(change,l-1,-1);//2-1=1
                    //2-1=1
                    //相当于把原值删除加上新值
                    put_in_hash(cur,change,sum[cur^1][k]);
                }
                if(p==2 && q==2) {
                    int change=state,l,top;
                    for(l = j-1 ,top=1; top ;--l) {
                        if(Get(change,l)==2) ++top;
                        if(Get(change,l)==1) --top;
                    }
                    change=Change_state(change,l+1,1);//1+1=2
                    put_in_hash(cur,change,sum[cur^1][k]);
                }
                if(p==1 && q==2) {
                    int change=state;
                    put_in_hash(cur,change,sum[cur^1][k]);
                }
                if(p==2&&q==1) {
                    if(i==n && j==n) ans+=sum[cur^1][k];
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
    freopen("betsy.in","r",stdin);
    freopen("betsy.out","w",stdout);
    solve();
    return 0;
}