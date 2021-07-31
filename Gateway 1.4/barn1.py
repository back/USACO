fileName="""
LANG: PYTHON3
TASK: barn1
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:

    m, s, c = map(int, fin.readline().split())
    cows = sorted(int(fin.readline().strip()) for i in range(c))

    gaps = [cows[i] - cows[i-1] - 1 for i in range(1,c)]
    gaps = [i for i in gaps if i]
    gaps.sort()

    skip = min(m-1, len(gaps))
    skip = sum(gaps[-skip:]) if skip else 0

    full = cows[-1] - cows[0] + 1

    print (gaps)
    print (skip)
    print (full)

    fout.write('%s\n' % (full-skip))
