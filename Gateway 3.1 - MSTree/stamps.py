fileName="""
LANG: PYTHON2
TASK: stamps
""".split()[-1]

fin=open(fileName + '.in')
k, n = map(int, fin.readline().split())
stamps = [int(i) for line in fin.readlines() for i in line.split()]

p = [201] * (k*max(stamps)+2)
p[0] = 0

for v in stamps:
    for i in range(v, len(p)):
        if p[i-v] < k:
            p[i]=min(p[i], p[i-v]+1)

for i in range(len(p)):
    if p[i]>k:
        break

fout = open(fileName + '.out', 'w')
fout.write('%s\n' % (i-1))
fout.close()
