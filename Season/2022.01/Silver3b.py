import sys

n, m = map(int, sys.stdin.readline().split())
p = [list(map(int, lin.split())) for lin in sys.stdin.readlines()]

s = [-1] * (m+1)  # which cow takes each food

def fill(cow, cereal):
    if s[cereal] < 0:
        s[cereal] = cow
        return True
    else:
        nextcow = s[cereal]
        if nextcow < cow and p[nextcow][0] == cereal:
            if fill(nextcow, p[nextcow][1]):
                s[cereal] = cow
                return True
    return False

head = []
tail = []
answer = 0

for i in range(n):
    a, b = p[i]
    if fill(i, a):
        head.append(i)
    else:
        tail.append(i)
        if s[b] < 0:
            s[b] = i
        else:
            answer+=1
            
        
print(answer)
for i in reversed(head):
    print(i+1)
for i in tail:
    print(i+1)
    