fileName="""
LANG: PYTHON2
TASK: inflate
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    m, n = map(int, fin.readline().split())
    w = [0]*(m+1)

    d = {}
    for line in fin.readlines():
        point, mins = map(int, line.split())
        x = [d[k] for k in d.keys() if k <= mins]
        if not x or point > max(x):
            d[mins]=point

    for mins, points in d.items():
        for i in range(mins, m+1):
            w[i] = max( w[i-mins]+points, w[i] )

    #print(w[m])
    fout.write('%s\n' % w[m])
