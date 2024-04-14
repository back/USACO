fileName="""
LANG: PYTHON3
TASK: milk
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:

    unitNeed, m = map(int, fin.readline().split())

    farmers=[]
    for i in range(m):
        farmers.append (list(map(int, fin.readline().split())))

    farmers.sort()

    cost = 0
    for (price, unit) in farmers:
        print( '%s,%s,%s,%s\n'%(price, unit, unitNeed, cost))
        if unit >= unitNeed:
            cost += unitNeed * price
            break
        else:
            cost += unit * price
            unitNeed -= unit

    fout.write('%s\n' % cost)
    print(cost)
