from sys import stdin as sin
n, q = map(int, sin.readline().split())

path = [(0,0)]
link = [[] for _ in range(n+1)]
live = [1] * (n+1)
answer = [0] * (n+1)

for step in range(1, q+1):
    x = sin.readline().split()
    if x[0] == 'A':
        a , b = int(x[1]), int(x[2])
        path.append((a, b))
        link[a].append(b)
        link[b].append(a)
    elif x[0] == 'D':
        live[int(x[1])] = 0
    elif x[0] == 'R':
        z = int(x[1])
        a, b = path[z]
        link[b].remove(a)
        link[a].remove(b)
        path[z] = (0, 0)
        
    for i in range(1, n+1):
        if live[i] > 0:
            answer[i] = step

    changed = True
    while changed:
        changed = False
        for a, b in path[1:]:
            if answer[a] == step and answer[b] < step:
                answer[b] = step
                changed = True
            if answer[a] < step and answer[b] == step:
                answer[a] = step
                changed = True

for i in answer[1:]:
    print(i)