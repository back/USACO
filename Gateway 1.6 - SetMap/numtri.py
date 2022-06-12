"""

LANG: PYTHON3
TASK: numtri
"""

fileName = 'numtri'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())
    tree = [list(map(int, l.split())) for l in fin.readlines()]

    for row in range(len(tree)-1, 0, -1):
        p = tree[row-1]
        r = tree[row]
        for col in range(len(p)):
            p[col] += max(r[col], r[col+1])
    
    fout.write('%s\n' % tree[0][0])
