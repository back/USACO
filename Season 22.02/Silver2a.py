import sys


n=int(sys.stdin.readline())
x, y = map(int, sys.stdin.readline().split())
p=[tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

q = [([i],p[i]) for i in range(n)]

answer = [0] * (n+1)

while q:
    comb, loc = q.pop(0)
    if loc == (x, y):
        answer[len(comb)] += 1
    for i in range(comb[-1]+1, n):
        q.append((comb + [i], (loc[0] + p[i][0], loc[1] + p[i][1])))
    
for i in answer[1:]:
    print(i)
