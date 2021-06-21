fileName="""
LANG: PYTHON3
TASK: agrinet
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())
    m = []
    for line in fin.readlines():
        m.extend(int(i) for i in line.split())
    m = [m[i*n:i*n+n] for i in range(n)]

    # Prim algorithm

    connected = set([0])
    shortPath = 0
    while len(connected) < n:
        minRow = 0
        minCol = 0
        minPath = 0
        for row in connected:
            for col in range(n):
                if m[row][col] == 0 or row in connected and col in connected:
                    continue
                elif minPath == 0 or m[row][col] < minPath:
                    minPath = m[row][col]
                    minRow = row
                    minCol = col
        connected.add(minRow)
        connected.add(minCol)
        shortPath += minPath
        #print('%s, %s, %s' % (minRow, minCol, shortPath))
        m[minRow][minCol] = m[minCol][minRow] = 0

    fout.write('%s\n' % shortPath)
