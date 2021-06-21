fileName="""
LANG: PYTHON3
TASK: transform
""".split()[-1]

def transform(mtx, method):
    n = len(mtx)
    tgt = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if method == 1:
                tgt[i][j] = mtx[n-j-1][i]
            elif method == 2:
                tgt[i][j] = mtx[n-i-1][n-j-1]
            elif method == 3:
                tgt[i][j] = mtx[j][n-i-1]
            elif method == 4:
                tgt[i][j] = mtx[i][n-j-1]
    return tgt

def match(mtx1, mtx2):
    return all(x==y for a, b in zip(mtx1, mtx2) for x,y in zip(a, b))

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    N   = int(fin.readline().strip())
    mtx = [tuple(c for c in fin.readline().strip()) for _ in range(N)]
    tgt = [tuple(c for c in fin.readline().strip()) for _ in range(N)]

    answer = 7 # default to no solutions

    if match(transform(mtx, 1), tgt):
        answer = 1
    elif match(transform(mtx, 2), tgt):
        answer = 2
    elif match(transform(mtx, 3), tgt):
        answer = 3
    else:
        ref = transform(mtx, 4)
        if match(ref, tgt):
            answer = 4
        elif match(transform(ref,1), tgt) \
          or match(transform(ref,2), tgt) \
          or match(transform(ref,3), tgt):
            answer = 5
        elif match(mtx, tgt):
            answer = 6

    print(answer)
    fout.write( '%d\n' % answer )
