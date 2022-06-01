import sys

n=int(sys.stdin.readline())
p=[list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# get prefered gifts:
g=[[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        g[i][p[i][j]-1] = 1
        if p[i][j]==i+1:
            break
            
# check for pairs could be swapped:
s=[[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if g[i][j] and g[j][i]:
            s[i][j] = s[j][i] = 1    

# Floyd-Warshall
for k in range(n):
    for i in range(n-1):
        for j in range(i+1, n):
            if k!=i and k!=j and g[i][j]==0 and g[i][k] and g[k][j]:
                s[i][j] = s[j][i] = 1

for i in range(n):
    for j in range(n):
        if s[i][p[i][j]-1]:
            print(p[i][j])
            break