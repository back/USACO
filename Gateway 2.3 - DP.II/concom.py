"""

LANG: PYTHON3
TASK: concom
"""

fileName = 'concom'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = fin.readline()

    x=101
    mx = [ [0] * x for _ in range(x) ]

    for line in fin.readlines():
        a,b,c = map(int, line.split())
        mx[a][b]=c

    for comp in range(1,x):

        myShares = [0] * x
        discover = [comp] # first loop to add self owned shares
        checked  = []

        while discover:
            for i in discover:
                myShares=[a+b for a, b in zip(mx[i], myShares)]
            checked.extend(discover)
            discover = [i for i in range(1,x) if myShares[i]>50 and i not in checked]

        for i in range(1,x):
            if myShares[i]>50 and comp != i:
                fout.write('%s %s\n' % (comp, i))
