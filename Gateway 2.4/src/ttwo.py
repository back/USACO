fileName="""

LANG: PYTHON3
TASK: ttwo
""".split()[-1]

def move(m, p):
    p0, p1, p2 = p
    if p0 == 1: # move up
        if p1 == 0 or m[ p1 - 1 ][ p2 ] == '*':
            p0 = 2
        else:
            p1 -= 1
    elif p0 == 2: # move right
        if p2 == 9 or m[ p1 ][ p2 + 1 ] == '*':
            p0 = 3
        else:
            p2 += 1
    elif p0 == 3: # move down
        if p1 == 9 or m[ p1 + 1 ][ p2 ] == '*':
            p0 = 4
        else:
            p1 += 1
    elif p0 == 4: # move left
        if p2 == 0 or m[ p1 ][ p2 - 1 ] == '*':
            p0 = 1
        else:
            p2 -= 1
    return (p0, p1, p2)

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    m = [list(line.strip()) for line in fin.readlines()]

    for row in range(10):
        for col in range(10):
            if m[row][col]=='F':
                f = (1,row,col)
                m[row][col] = '.'
            if m[row][col]=='C':
                c = (1,row,col)
                m[row][col] = '.'

    state=[]
    i = 0
    met = False
    while (f,c) not in state:
        state.append((f,c))
        if f[1]==c[1] and f[2] == c[2]:
            met = True
            break
        f=move(m,f)
        c=move(m,c)
        i+=1

    fout.write('%s\n' % (i if met else 0))
