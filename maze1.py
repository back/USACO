fileName="""

LANG: PYTHON3
TASK: maze1
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    w,h = map(int, fin.readline().split())
    m = fin.readlines()

    depth = {}

    # for a given cell: (row,col)
    # the 4 walls can be found at:
    #                   m[row*2  ][col*2+1]
    #  m[row*2+1][col*2]                   m[row*2+1][col*2+2]
    #                   m[row*2+2][col*2+1]

    # find exit cells
    for col in range(w):
        if m[0][col*2+1]==' ':
            depth[(0,col)]=1
        if m[h*2][col*2+1]==' ':
            depth[(h-1,col)]=1
    for row in range(h):
        if m[row*2+1][0]==' ':
            depth[(row,0)]=1
        if m[row*2+1][w*2]==' ':
            depth[(row,w-1)]=1

    i = 1
    while len(depth) < w*h:
        progress = [p for p in depth if depth[p] == i]
        if progress:
            i+=1
            print(i, progress)
            for row, col in progress:
                if row > 0   and m[row*2  ][col*2+1] == ' ' and (row-1, col) not in depth:
                    depth[(row-1, col)] = i
                if row < h-1 and m[row*2+2][col*2+1] == ' ' and (row+1, col) not in depth:
                    depth[(row+1, col)] = i
                if col > 0   and m[row*2+1][col*2  ] == ' ' and (row, col-1) not in depth:
                    depth[(row, col-1)] = i
                if col < w-1 and m[row*2+1][col*2+2] == ' ' and (row, col+1) not in depth:
                    depth[(row, col+1)] = i

    fout.write('%s\n' % i)
