/*
PROG: fact4
LANG: C++
*/
// Another way
#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
    ifstream cin("fact4.in");
    ofstream cout("fact4.out");
        int f,mod = 100000,b=1;
    cin >> f;
    for(int i=2;i<=f;i++)
    {
        b=b*i%mod;
        while(b%10==0) b/=10;
    }
    cout << b%10 << endl;
    return 0;
}