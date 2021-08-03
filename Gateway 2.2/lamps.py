"""

LANG: PYTHON3
TASK: lamps
"""

fileName = 'lamps'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())
    c = int(fin.readline().strip())
    on = list(map(int, fin.readline().split()))
    off = list(map(int, fin.readline().split()))

    on.pop()
    off.pop()

    answer=[]

    for sw1 in (0, 1):
        for sw2 in (0, 1):
            for sw3 in (0, 1):
                for sw4 in (0, 1):
                    flip = sw1 + sw2 + sw3 + sw4
                    if flip <= c and (c - flip)%2 == 0:
                        lamp = [1] * (n+1)
                        for i in range(1,n+1):
                            if sw1==1:
                                lamp[i] = 1-lamp[i]
                            if sw2==1 and i%2 == 1:
                                lamp[i] = 1-lamp[i]
                            if sw3==1 and i%2 == 0:
                                lamp[i] = 1-lamp[i]
                            if sw4==1 and i%3 == 1:
                                lamp[i] = 1-lamp[i]

                        if all(lamp[x] for x in on):
                            if not any(lamp[x] for x in off):
                                lamp.pop(0)
                                answer.append(''.join(map(str, lamp)))

    if answer:
        answer.sort()
        for s in answer:
            fout.write(s+'\n')
    else:
        fout.write('IMPOSSIBLE\n')