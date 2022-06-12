/*
TASK: checker
LANG: C++

Submit: test 8 timeout...
*/
#include <iostream>
#include <cstdio>

using namespace std;

int N;
bool col_fill[15];
bool updia_fill[30];
bool dodia_fill[30];
int answer[15];
int cnt = 0;

void place_row(int r)
{
    if(r == N+1){
        ++cnt;
        if(cnt <= 3){
            printf("%d", answer[1]);
            for(int i = 2; i <= N; ++i)
                printf(" %d", answer[i]);
            printf("\n");
        }
    }
    for(int c = 1; c <= N; ++c){
        if(!col_fill[c] && !updia_fill[r-c+N] && !dodia_fill[r+c]){
            col_fill[c] = updia_fill[r-c+N] = dodia_fill[r+c] = true;
            answer[r] = c;
            place_row(r+1);
            col_fill[c] = updia_fill[r-c+N] = dodia_fill[r+c] = false;
        }
    }
}

int main()
{
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
    scanf("%d", &N);
    place_row(1);
    printf("%d\n", cnt);
    return 0;
}