fileName="""
LANG: PYTHON3
TASK: gift1
""".split()[-1]

with open(fileName + '.in') as fin:
    NP = int(fin.readline().strip())
    names = [fin.readline().strip() for _ in range(NP)]
    money = dict((n,0) for n in names)

    for i in range(NP):
        fromWho = fin.readline().strip()
        cash, count = map(int, fin.readline().split())
        if count:
            gift = int(cash/count)
            for j in range(count):
                toWhom = fin.readline().strip()
                money[fromWho] -= gift   # -66
                money[toWhom] += gift    # +66

with open(fileName + '.out', 'w') as fout:
    for i in range(NP):
        fout.write( '%s %d\n' % (names[i], money[names[i]]) )
        print ('%s %d' % (names[i], money[names[i]]))
