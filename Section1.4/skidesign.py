fileName="""
LANG: PYTHON3
TASK: skidesign
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    fin.readline()
    h = [int(i.strip()) for i in fin.readlines()]
    
    fix = lambda x, x_min: (x-x_min)*(x-x_min) if x < x_min else (x_min+17-x) * (x_min+17-x) if x > x_min+17 else 0
    answer = min ( sum( fix(x, i) for x in h ) for i in range(min(h), max(h)-17) ) if min(h) < max(h)-17 else 0
    
    fout.write('%s\n' % answer)
