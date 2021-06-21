fileName="""
LANG: PYTHON3
TASK: milk2
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:

    N = int(fin.readline().strip())
    x = [tuple(map(int, line.split())) for line in fin.readlines()]

    z = []
    for a,b in sorted(x):
        if z and a <= z[-1][1]:
            z[-1] = (min(z[-1][0], a), max(z[-1][1], b))
        else:
            z.append((a,b))

    maxMilking = max(b-a for a,b in z)
    maxNotMilking = max(z[i+1][0]-z[i][1] for i in range(len(z)-1)) if len(z)>1 else 0

    fout.write( '%s %d\n' % (maxMilking, maxNotMilking) )
