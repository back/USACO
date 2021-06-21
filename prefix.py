"""

LANG: PYTHON3
TASK: prefix
"""

fileName = 'prefix'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    s = fin.readlines()
    i = s.index('.\n')
    p = ''.join(s[0:i]).split()
    s = ''.join(x.strip() for x in s[i+1:])

    mark = [0] * (len(s)+1)
    mark[0] = 1

    max = 0
    for i in range(len(mark)):
        if mark[i]==0:
            continue
        
        max = i

        for n in p:
            nextPos = i + len(n)
            if s[i:nextPos]==n:
                mark[nextPos] = 1

    fout.write('%s\n' % max)
