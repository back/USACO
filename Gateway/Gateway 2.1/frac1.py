"""

LANG: PYTHON3
TASK: frac1
"""

from operator import itemgetter

fileName = 'frac1'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())

    x=[(nom, denom, nom/denom) for denom in range(1,n+1) for nom in range(1,denom)]
    x.sort(key=itemgetter(2))

    fout.write('0/1\n')
    prevA, prevB = 0, 1
    for a,b,c in x:
        if prevA*b < prevB*a: 
            fout.write('%s/%s\n' % (a,b))
            prevA, prevB = a, b
    fout.write('1/1\n')
