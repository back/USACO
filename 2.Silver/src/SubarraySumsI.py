import sys

n, m = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

l = s = count = 0

for r in range(n):
    s += a[r]
    while s > m:
        s -= a[l]
        l += 1
    if s == m and l <= r:
        count += 1

print(count)

