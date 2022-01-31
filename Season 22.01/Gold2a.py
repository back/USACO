import sys

n, q = map(int, sys.stdin.readline().split())

path = [(0,0)]
link = [[] for _ in range(n+1)]
live = [1] * (n+1)
answer = [0] * (n+1)

for step in range(1, q+1):
    x = sys.stdin.readline().split()
    if x[0] == 'A':
        a , b = int(x[1]), int(x[2])
        path.append((a, b))
        link[a].append(b)
        link[b].append(a)
    elif x[0] == 'D':
        live[int(x[1])] = 0
    elif x[0] == 'R':
        a, b = path[int(x[1])]
        link[b].remove(a)
        link[a].remove(b)
        
    for i in range(1,n+1):
        if live[i]>0:
            answer[i] = step
            
    q = []
    for i in range(1,n+1):
        if live[i]>0:
            q.extend([j for j in link[i] if answer[j] < step])
    while q:
        i = q.pop(0)
        answer[i] = step
        q.extend([j for j in link[i] if answer[j] < step])

for i in answer[1:]:
    print(i)