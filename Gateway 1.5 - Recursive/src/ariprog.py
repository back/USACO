"""

LANG: PYTHON3
TASK: ariprog
"""
from operator import itemgetter


import time
start = time.time()

fileName = 'ariprog'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())
    m = int(fin.readline().strip())

    sq = set()
    for i in range(m+1):
        for j in range(i,m+1):
            sq.add(i*i + j*j)
    sqset = frozenset(sq)

    result = []
    for a in sqset:
        for step in range(1, a//(n-1)+1):
            checks = n
            b = a - step
            while b in sqset:
                if checks == 2:
                    result.append((b, step))
                    break
                checks -= 1
                b -= step

    if result:
        result.sort(key=itemgetter(1))
        for item in result:
            fout.write('%s %s\n' % (item[0], item[1]))
    else:
        fout.write('NONE\n')

print('time: %s' % (time.time() - start) )
