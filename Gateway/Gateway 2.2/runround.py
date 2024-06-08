"""

LANG: PYTHON3
TASK: runround
"""

fileName = 'runround'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())

    while True:
        n+=1

        s = list(map(int,list(str(n))))
        w = len(s)

        if 0 in s or w > len(set(s)):
            continue

        i = 0
        while s[i]:
            k = (s[i] + i) % w
            s[i] = 0
            i = k

        if k==0 and not any(s):
            fout.write('%s\n' % n)
            break
