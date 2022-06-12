"""

LANG: PYTHON3
TASK: sprime
"""
from math import sqrt

fileName = 'sprime'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())

    limit = int(sqrt(int('9' * n)))

    p = [3,5,7]
    check = 11
    while check < limit:
        fac_limit = int(sqrt(check))
        for i in p:
            if check % i == 0:
                break
            elif i > fac_limit:
                p.append(check)
                break
        check += 2
    
    print(p)

    answer = [2,3,5,7]
    while n>1:
        new_answer = []
        for i in answer:
            for j in [1,3,7,9]:
                a = i*10+j
                limit = int(sqrt(a))
                for factor in p:
                    if a%factor == 0:
                        break
                    elif factor > limit:
                        new_answer.append(a)
                        break
        n -= 1
        answer = new_answer
        print(answer)

    for i in answer:
        fout.write('%s\n' % i)
