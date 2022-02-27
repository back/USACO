import sys

n=int(sys.stdin.readline())
p=[list(map(int, sys.stdin.readline().split())) for _ in range(n)]

def checkOrder(a, b):
    # is cow(a) prefer b?
    for x in p[a-1]:
        if x==b:
            return True
        elif x==a:
            return False

g=[[0] * (n+1) for _ in range(n+1)]

# double loop for each pair of cows:
for i in range(1, n+1):
    for j in range(i+1, n+1):
        if checkOrder(i, j) and checkOrder(j, i):
            g[i][j] = g[j][i] = 1
            
# Floyd-Warshall
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i!=j and g[i][j]==0 and g[i][k] and g[k][j]:
                if checkOrder(i, j):
                    g[i][j] = 1
                if checkOrder(j, i):
                    g[j][i] = 1
        
for i in range(1, n+1):
    for x in p[i-1]:
        if g[i][x] or x == i:
            print(x)
            break
