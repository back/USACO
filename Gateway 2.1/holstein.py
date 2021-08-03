"""

LANG: PYTHON3
TASK: holstein
"""

fileName = 'holstein'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    v = int(fin.readline().strip())
    req = list(map(int, fin.readline().split()))
    g = int(fin.readline().strip())
    feeds = [list(map(int, i.split())) for i in fin.readlines()]
    pool = [[i] for i in range(g)]
    while pool:
        for p in pool:
            scoops = list(map(sum, zip(*[feeds[i] for i in p])))
            if all(i[0]<=i[1] for i in zip(req,scoops)):
                fout.write('%s %s\n' % (len(p),' '.join(list(str(i+1) for i in p))))
                pool = None
                break
        if pool:
            pool = [p+[i] for p in pool for i in range(p[-1]+1, g)]

 