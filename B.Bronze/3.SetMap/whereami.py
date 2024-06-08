with open('whereami.in') as fin, open('whereami.out','w') as fout:
    n = int(fin.readline().strip())
    m = fin.readline().strip()
    for answer in range(1, n+1):
        s = set()
        for i in range(n-answer+1):
            if m[i:answer+i] in s:
                s.clear()
                break
            s.add(m[i:answer+i])
        if s:
            fout.write('%s\n' % answer)
            break
