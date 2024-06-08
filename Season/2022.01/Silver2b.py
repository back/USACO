import sys

n = int(sys.stdin.readline())
p = list(map(int, sys.stdin.readline().split()))

q = [-1] * n
answer = (n-1)*2

for i in range(1,n):
    tracer = i-1
    while tracer > -1 and p[tracer] < p[i]:
        tracer = q[tracer]
        if tracer > -1:
            answer += i - tracer + 1
    q[i] = tracer
print(answer)