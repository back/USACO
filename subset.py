"""

LANG: PYTHON3
TASK: subset
"""

fileName = 'subset'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())

    sum = int((1+n)*n/2)
    if sum % 2 == 0:
        sum = int(sum / 2)

        work = [0]*(sum+1)
        work[0] = 1
        for i in range(1,n+1):
            for j in range(sum,i-1,-1):
                work[j] += work[j-i]
    
        fout.write('%d\n' % (work[sum]/2))
    else:
        fout.write('0\n')

