fileName="""
LANG: PYTHON3
TASK: combo
""".split()[-1]

def norm(loopSize,i):
    while i<1:
        i+=loopSize
    while i>loopSize:
        i-=loopSize
    return i

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:

    n=int(fin.readline().strip())
    p1 = list(map(int, fin.readline().split()))
    p2 = list(map(int, fin.readline().split()))

    k=set()
    for r1 in range(-2, +3):
        for r2 in range(-2, +3):
            for r3 in range(-2, +3):
                k.add((norm(n, p1[0] + r1), norm(n, p1[1] + r2), norm(n, p1[2] + r3 )))
                k.add((norm(n, p2[0] + r1), norm(n, p2[1] + r2), norm(n, p2[2] + r3 )))

    fout.write('%s\n' % len(k))
    
