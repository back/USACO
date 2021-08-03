"""

LANG: PYTHON3
TASK: zerosum
"""

fileName = 'zerosum'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())

    p = (' ', '+', '-')
    ops = ['']
    while len(ops[0]) < n-1:
        x = ops.pop(0)
        ops.extend(x+i for i in p)

    for op in ops:
        res = [0, 1]
        for i in range(1,n):
            # 1234, +-+
            if op[i-1] == ' ':
                res[1] *= 10
                if res[1] > 0:
                    res[1] += i+1
                else:
                    res[1] -= i+1
            else:
                res[0] += res[1]
                if op[i-1] == '+':
                    res[1] = i+1
                if op[i-1] == '-':
                    res[1] = -i-1
        if res[0]+res[1] == 0:
            s = '1'
            for i in range(1,n):
                s += str(op[i-1]) + str(i+1)
            fout.write(s + '\n')
