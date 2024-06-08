"""

LANG: PYTHON3
TASK: subset
"""

fileName = 'subset'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    N = int(fin.readline().strip())
    total = N*(N+1)//2
    lst = [1] + [0]*(total//2)
    if total % 2 != 0:
        #it should add up to total and for that to have two equal sums,
        #it should be total/2, but that should be an integer
        fout.write('0\n')
    else:#recursive approach
        total //= 2
        for i in range(1, N + 1):
            for j in range(total, i-1, -1):
                lst[j] += lst[j - i]#amount of ways to assemble without i

        fout.write('%s\n' % (lst[total]//2))#Order doesn't matter, so sets can be switched, so /2.