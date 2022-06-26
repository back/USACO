"""

LANG: PYTHON3
TASK: money
"""

fileName = 'money'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    _, n = map(int, fin.readline().split())
    v=[]
    for line in fin.readlines():
        v.extend(map(int, line.split()))

    r = [0] * (n+1)
    r[0] = 1
    for m in v:
        for i in range(1,n+1):
            if i-m >= 0:
                r[i] += r[i-m]

    fout.write('%s\n' % r[n])
