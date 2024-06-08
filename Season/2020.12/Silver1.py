Cowntagion (Python 3.6.9)
Roy One (royone)
Submitted: Sun, Dec 20, 2020 16:14:35 EST
Contest: USACO 2020 December Contest, Silver
"""
ID: royone
LANG: PYTHON3
"""
from functools import lru_cache
import math

n = int(input())
mx = [[0]*(n+1) for i in range(n+1)]

for i in range(n-1):
    a,b = map(int, input().split())
    mx[a][b] = mx[b][a] = 1

@lru_cache()
def calc(i):
    children = sum(mx[i][i:])
    if children:
        cost = math.ceil(math.log(children+1, 2))
        for j in range(i+1,n+1):
            if mx[i][j]:
                cost += calc(j)
        return cost
    else:
        return 1

ans = calc(1)
print (ans)
