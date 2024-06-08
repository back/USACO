# https://cses.fi/problemset/task/1643/

import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

for i in range(1,len(a)):
    if a[i-1] > 0:
        a[i] += a[i-1]

print(max(a))
