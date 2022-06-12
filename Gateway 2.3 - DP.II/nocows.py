"""

LANG: PYTHON3
TASK: nocows
"""

import functools

@functools.lru_cache(maxsize=None)
def rec(n, k):
    # n: node, k: height
    if k == 1:
        return 1 if n == 1 else 0
    if k == 2:
        return 1 if n == 3 else 0

    sum = 0
    for leftNodes in range(1, n-1, 2):
        left = rec(leftNodes, k-1) # must have height K-1
        if left > 0:
            for rightLevel in range(k-1, 0, -1):
                right = rec(n-leftNodes-1, rightLevel)
                if right > 0:
                    comb = left * right
                    if k-1 > rightLevel:
                        comb += comb
                    sum += comb
    return sum


fileName = 'nocows'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n, k = map(int, fin.readline().split())
    fout.write('%s\n' % (rec(n, k) % 9901))
