fileName="""
LANG: PYTHON3
TASK: cowtour
""".split()[-1]

from math import sqrt

def geo_dis(x, y):
    a = loc[x][0] - loc[y][0]
    b = loc[x][1] - loc[y][1]
    return sqrt( a*a + b*b )

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())
    d = fin.readlines()
    loc = [list(map(int,line.split())) for line in d[:n]]
    con = [[int(i) for i in line.strip()]  for line in d[n:]]
    dis = [[0]*n for _ in range(n)]

    for i in range(n-1):
        for j in range(i+1,n):
            dis[i][j] = dis[j][i] = geo_dis(i,j) if con[i][j] else -1 # -1 means infinite
    
    for k in range(n):
        for i in range(n-1):
            for j in range(i+1,n):
                if dis[i][k] > 0 and dis[k][j] > 0:
                    x = dis[i][k] + dis[k][j]
                    if dis[i][j] < 0 or dis[i][j] > x: # -1 means infinite
                        dis[i][j] = dis[j][i] = x

    max_dis = [max(row) for row in dis]
    ans = min(geo_dis(i, j) + max_dis[i] + max_dis[j]
                for i in range(n-1)
                for j in range(i+1, n)
                if dis[i][j] < 0)

    fout.write('{:.6f}\n'.format(max(ans, max(max_dis))))
