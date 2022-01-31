import sys

n = int(sys.stdin.readline())
p = list(map(int, sys.stdin.readline().split()))

q = [-1] * n
answer = (n-1)*2

for i in range(1,n):
    q[i] = i-1
    while q[i] > -1 and p[q[i]] < p[i]:
        q[i] = q[q[i]]
        if q[i] > -1:
            answer += i - q[i] + 1
print(answer)