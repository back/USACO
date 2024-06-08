"""
LANG: PYTHON3
TASK: sprime
"""
from math import sqrt

fileName = 'sprime'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())

    limit = int(10 ** (n/2))
    p = [0] * limit
    for i in range(3, limit):
        if p[i] == 0:
            for j in range(i+i, limit, i):
                p[j] = 1;
    ps = [index for index,value in enumerate(p) if value == 0 and index > 1 and index%2 > 0]

    answer = [2,3,5,7]
    while n>1:
        new_answer = []
        for i in answer:
            for j in [1,3,7,9]:
                a = i*10+j
                limit = int(sqrt(a))
                for factor in ps:
                    if a%factor == 0:
                        break
                    elif factor > limit:
                        new_answer.append(a)
                        break
        n -= 1
        answer = new_answer

    for i in answer:
        fout.write('%s\n' % i)
