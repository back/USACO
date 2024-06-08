/*
LANG: C++
PROG: wissqu
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
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
#define esp 1e-10
typedef long long ll;
using namespace std;
char c[10][10];
int calc[6][6][6];
int dirx[]={-1,1,0,0,1,-1,-1,1,0};
int diry[]={0,0,-1,1,1,-1,1,-1,0};
int num[6];

bool used[6][6];
char tempchange[20];
int row[20],col[20];
int ans;
bool flag;
void init() {
    siji(i,1,4) {scanf("%s",c[i]+1);}
    siji(i,1,4) {
        siji(j,1,4) {
            siji(z,0,8) {
                int xx=i+dirx[z],yy=j+diry[z];
                if(xx>=1 && xx<=4 && yy>=1 && yy<=4) {
                    ++calc[xx][yy][c[i][j]-'A'+1];
                }
            }
        }
    }
    siji(i,1,5) num[i]=3;
    ++num[4];
}
void PRINT() {
    siji(i,1,16) {
        printf("%c %d %d\n",tempchange[i],row[i],col[i]);
    }
}
void dfs(int dep) {
    if(dep>16) {
        ++ans;
        if(!flag) {PRINT();flag=1;}
        return;
    }
    siji(z,1,5) {
         if(num[z]==0) continue;
        siji(i,1,4) {
            siji(j,1,4){
                if(used[i][j]) continue;
                if(calc[i][j][z]==0) {
                    used[i][j]=1;
                    --num[z];
                    siji(k,0,8) {
                        int xx=i+dirx[k],yy=j+diry[k];
                        if(xx>=1 && xx<=4 && yy>=1 && yy<=4) {
                            --calc[xx][yy][c[i][j]-'A'+1];
                            ++calc[xx][yy][z];
                        }
                    }
                    if(!flag) {
                        tempchange[dep]='A'+z-1;
                        row[dep]=i;
                        col[dep]=j;
                    }

                    dfs(dep+1);
                    used[i][j]=0;
                    ++num[z];
                    siji(k,0,8) {
                        int xx=i+dirx[k],yy=j+diry[k];
                        if(xx>=1 && xx<=4 && yy>=1 && yy<=4) {
                            ++calc[xx][yy][c[i][j]-'A'+1];
                            --calc[xx][yy][z];
                        }
                    }
                }
            }
        }
    }

}
void solve() {
    init();
    siji(i,1,4) {
        siji(j,1,4) {
            if(calc[i][j][4]==0) {
                used[i][j]=1;
                --num[4];
                siji(k,0,8) {
                    int xx=i+dirx[k],yy=j+diry[k];
                    if(xx>=1 && xx<=4 && yy>=1 && yy<=4) {
                        --calc[xx][yy][c[i][j]-'A'+1];
                        ++calc[xx][yy][4];
                    }
                }
                if(!flag) {
                    tempchange[1]='D';
                    row[1]=i;
                    col[1]=j;
                }
                dfs(2);
                used[i][j]=0;
                ++num[4];
                siji(k,0,8) {
                    int xx=i+dirx[k],yy=j+diry[k];
                    if(xx>=1 && xx<=4 && yy>=1 && yy<=4) {
                        ++calc[xx][yy][c[i][j]-'A'+1];
                        --calc[xx][yy][4];
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
#ifdef ivorysi
    freopen("wissqu.in","r",stdin);
    freopen("wissqu.out","w",stdout);
#else
    freopen("f1.in","r",stdin);
#endif
    solve();
    return 0;
}