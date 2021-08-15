"""
Stuck in a Rut (Python 3.6.9)
Roy One (royone)
Submitted: Sat, Dec 19, 2020 17:29:08 EST
Contest: USACO 2020 December Contest, Bronze
"""
import operator

n = int(input())
c = list()
for i in range(n):
    d, a, b = input().split()
    x = int(a)
    y = int(b)
    c.append([x+y, i, d, x, y, 0])
    #    0,  1,   2, 3, 4,     5
    # rank, id, dir, x, y, grass(0 means infinite)

c.sort()

for i in range(n-2,-1,-1):
    for j in range(i+1, n):
        if c[i][0] < c[j][0]:
            if c[i][2] == 'E' and c[j][2] == 'N':
                if c[i][4]>c[j][4]:
                    if c[j][5]==0 or c[j][5]+c[j][4]>c[i][4]:
                        x = c[j][3]-c[i][3]
                        if c[i][5]==0 or x < c[i][5]:
                            c[i][5] = x
            elif c[i][2] == 'N' and c[j][2] == 'E':
                if c[i][3]>c[j][3]:
                    if c[j][5]==0 or c[j][5]+c[j][3]>c[i][3]:
                        x = c[j][4]-c[i][4]
                        if c[i][5]==0 or x < c[i][5]:
                            c[i][5] = x
        
for x in sorted(c, key = operator.itemgetter(1)):
    print(x[5] if x[5] > 0 else 'Infinity')

