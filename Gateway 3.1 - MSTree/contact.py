fileName="""
LANG: PYTHON2
TASK: contact
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    a, b, n = map(int, fin.readline().split())
    p = [int(i) for line in fin.readlines() for i in line.strip()]
    
    r = [{} for _ in range(b+1)]

    for w in range(a, b+1):
        k = 0
        mask = 2**w-1
        for i in range(len(p)):
            k = (k<<1 | p[i]) & mask
            if i >= w-1:
                if k in r[w]:
                    r[w][k]+=1
                else:
                    r[w][k]=1
    
    answer = []
    for w in range(b+1):
        f='0%sb' % w
        for k,v in r[w].items():
            answer.append((-v, w, format(k, f)))
    answer.sort()

    fout.write('%s\n%s' % (-answer[0][0], answer[0][2]))
    group = 1
    inner = 1
    for i in range(1, len(answer)):
        x = answer[i-1]
        y = answer[i]
        if x[0] != y[0]:
            if group == n:
                break # we are done here
            else:
                group += 1
                inner = 1
                fout.write('\n%s\n%s' % (-y[0], y[2])) # new group
        else:
            if inner == 6:
                fout.write('\n%s' % y[2])
                inner = 1
            else:
                fout.write(' %s' % y[2])
                inner += 1
    fout.write('\n')
