n, q = map(int, input().split())
s = input()

def check(x):
    chs = sorted(set(x))
    s = '-' + x + '-'
    t = 0
    while chs:
        c = chs.pop()
        sp = [i for i in s.split(c) if i]
        t += len(sp) - 1
        if chs:
            s = s.replace(c, '')
    return t


for _ in range(q):
    a, b = map(int, input().split())
    print(check(s[:a-1]) + check(s[b:]))
