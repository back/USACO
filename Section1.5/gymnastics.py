fin = open('gymnastics.in')

k, n = map(int, fin.readline().split())
better=[[0]*(n+1) for _ in range(n+1)]

for _ in range(k):
    x = list(map(int, fin.readline().split()))
    for i in range(n-1):
        for j in range(i+1, n):
            better[x[i]][x[j]] = 1

answer = 0
for i in range(1, n):
    for j in range(i+1, n+1):
        if better[i][j] != better[j][i]:
            answer += 1
            
with open('gymnastics.out', 'w') as fout:
    fout.write('%s\n' % answer)
