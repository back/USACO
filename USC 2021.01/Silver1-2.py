n, k = map(int, input().split())

pos = [i for i in range(n+1)]

v = [[0 for i in range(n+1)] for _ in range(n+1)]
for i in range(1,n+1):
    v[i][i] = 1

for _ in range(k):
    a, b = map(int, input().split())
    v[pos[a]][b] = v[pos[b]][a] = 1
    pos[a], pos[b] = pos[b], pos[a]

changed = True
while changed:
    changed = False
    for i in range(1, n+1):
        if pos[i] != i:
            x = [0 if a+b==0 else 1 for a,b in zip(v[i], v[pos[i]])]
            if x!=v[i] or x!= v[pos[i]]:
                v[i] = v[pos[i]] = x
                changed = True

for r in v[1:]:
    print(sum(r))
