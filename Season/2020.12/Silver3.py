Stuck in a Rut (Python 3.6.9)
Roy One (royone)
Submitted: Sun, Dec 20, 2020 14:46:57 EST
Contest: USACO 2020 December Contest, Silver
"""
ID: royone
LANG: PYTHON3
"""
from operator import itemgetter

n = int(input())
c = list()
for i in range(n):
    d, a, b = input().split()
    x = int(a)
    y = int(b)
    c.append([x+y, i, d, x, y, 0, -1, 0])
    #    0,  1,   2, 3, 4,     5,          6,             7
    # rank, id, dir, x, y, grass, stopped by, final blocked

c.sort()

for i in range(n-2,-1,-1):    #in java: for(int i = n-2;  i>-1;  i--)
    for j in range(i+1, n):
        if c[i][0] < c[j][0]:
            if c[i][2] == 'E' and c[j][2] == 'N':
                if c[i][4]>c[j][4]:
                    if c[j][5]==0 or c[j][5]+c[j][4]>c[i][4]:
                        x = c[j][3]-c[i][3]
                        if c[i][5]==0 or x < c[i][5]:
                            c[i][5] = x
                            c[i][6] = j
            elif c[i][2] == 'N' and c[j][2] == 'E':
                if c[i][3]>c[j][3]:
                    if c[j][5]==0 or c[j][5]+c[j][3]>c[i][3]:
                        x = c[j][4]-c[i][4]
                        if c[i][5]==0 or x < c[i][5]:
                            c[i][5] = x
                            c[i][6] = j
        
for i in range(n):
    if c[i][6] > 0:
        c[c[i][6]][7] += c[i][7] + 1

for x in sorted(c, key = itemgetter(1)):
    print(x[7])

