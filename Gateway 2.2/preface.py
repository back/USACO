"""

LANG: PYTHON3
TASK: preface
"""

fileName = 'preface'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())

    chunk = [1000,900,500, 400,100, 90, 50,  40,  10,  9,  5,   4,  1]
    roman = ['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
    answer = {'I':0,'V':0,'X':0,'L':0,'C':0,'D':0,'M':0}

    for i in range(1,n+1):
        num = i
        for c,r in zip(chunk, roman):
            while num >= c:
                num -= c
                for key in r:
                    answer[key] += 1

    for char, count in answer.items():
        if count:
            fout.write('%s %s\n' % (char, count))
