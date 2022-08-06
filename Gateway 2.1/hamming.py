"""

LANG: PYTHON3
TASK: hamming
"""

fileName = 'hamming'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n, b, d = map(int, fin.readline().split())

    answer = [0]
    check = 0
    while (len(answer) < n):
        check += 1
        found = True
        for i in answer:
            if bin(check ^ i).count('1') < d:
                found = False
                break
        if found:
            answer.append(check)
    
    line_count = 0
    for i in answer[:-1]:
        fout.write(str(i))
        line_count += 1
        fout.write(' ' if line_count % 10 > 0 else '\n')
    fout.write(str(answer[-1]))
    fout.write('\n')
