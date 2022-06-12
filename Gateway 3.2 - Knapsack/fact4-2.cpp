/*
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
 
const int N = 501;
int n[N],f;
 
int main()
{
    ifstream cin("fact4.in");
    ofstream cout("fact4.out");
    n[0]=1;
    cin >> f;
    for(int i=1;i<=f;i++)
    {
        for(int j=0;j!=N-1;j++)
            n[j]*=i;
        for(int j=0;j!=N-1;j++)
        if(n[j]>=10)
        {
            n[j+1]+=n[j]/10;
            n[j]%=10;
        }
    }
    for(int i=0;i!=N-1;i++) if(n[i])
    {
        cout << n[i] << endl;
        break;
    }
    return 0;
}