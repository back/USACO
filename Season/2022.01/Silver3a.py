import sys

n, m = map(int, sys.stdin.readline().split())
p = [list(map(int, lin.split())) for lin in sys.stdin.readlines()]

s = [-1] * (m+1)
v = list(range(n))
answer=0
for i in range(n):
    a, b = p[i]
    if s[a] < 0:
        s[a] = i
    elif s[b] < 0:
        s[b] = i
    else:
        _, alt = p[s[a]]
        if s[alt] < 0:
            s[alt] = s[a]
            s[a] = i
            v[s[alt]], v[s[a]] = v[s[a]], v[s[alt]]
        else:
            _, alt = p[s[b]]
            if s[alt] < 0:
                s[alt] = s[b]
                s[b] = i
                v[s[alt]], v[s[b]] = v[s[b]], v[s[alt]]
            else:
                answer+=1
print(answer)
for i in v:
    print(i+1)