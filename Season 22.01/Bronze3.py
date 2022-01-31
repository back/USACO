import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    p = list(map(int, sys.stdin.readline().split()))
    answer = 0
    for i in range(1, n):
        if p[i] > p[i-1]:
            if i+1<n and p[i+1] >= p[i] - p[i-1]:
                answer += (p[i] - p[i-1])*2
                p[i+1] -= p[i] - p[i-1]
                p[i] = p[i-1]
            else:
                answer = -1
                break
        elif p[i] < p[i-1]:
            if i % 2 == 0:
                answer += (p[i-1] - p[i]) * i
            else:
                answer = -1
                break
    print(answer)
    
    
    
