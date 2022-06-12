"""

LANG: PYTHON3
TASK: pprime
"""
from time import time
from math import sqrt

start = time()

fileName='pprime'
with open (fileName + '.in', 'r') as fin, open(fileName + '.out', 'w') as fout:
    # read input, as sample: a=123456, b=1123456
    a,b = map(int, fin.readline().split())

    ps = [3,5,7]

    check = 11
    squre = 25
    limit = 1

    factorLimit = int(sqrt(b))
    while check < factorLimit:
        if check == squre:
            limit += 1
            squre = ps[limit] * ps[limit]
        else:
            prime = True
            for i in ps[:limit]:
                if check % i == 0:
                    prime = False
                    break
            if prime:
                ps.append(check)
        check += 2

    pp = set()
    for check in [2,5]:
        if check >= a and check <=b:
            pp.add(check)

    for i in range(len(str(a)), len(str(b))+1):
        for half in range( 10 ** ((i-1)//2), 10 ** ((i+1)//2) ):
            if str(half)[0] in '24568':
                continue
            anotherhalf = str(half)[::-1]
            check = int(str(half) + (anotherhalf[1:] if i%2 else anotherhalf))
            if check >= a and check <=b:
                if check in ps:
                    pp.add(check)
                else:
                    prime = True
                    for i in ps:
                        if check % i == 0:
                            prime = False
                            break
                    if prime:
                        pp.add(check)

    for i in sorted(pp):
        fout.write('%s\n' % i)

print ('seconds: ', (time()-start))