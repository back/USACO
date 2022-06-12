fileName="""
LANG: PYTHON2
TASK: humble
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    c, n = map(int, fin.readline().split())
    p = list(map(int, fin.readline().split()))

    #(nextCandidate, currrentPos, selfIndex)
    nexts = [(p[i], 0, i) for i in range(c)]

    m = [0] * (n+1)
    m_idx = 0
    while m_idx < n:
        nextNum, currPos, i = min(nexts)
        if nextNum > m[m_idx]:
            m_idx += 1
            m[m_idx] = nextNum
        currPos += 1
        nexts[i] = (m[currPos] * p[i], currPos, i)

    print(m[n])
    fout.write('%s\n' % m[n])
