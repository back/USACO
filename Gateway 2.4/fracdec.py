fileName="""
LANG: PYTHON3
TASK: fracdec
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n, d = map(int, fin.readline().split())

    remainders = [0] * d
    answer = str(n//d) + '.'

    n -= n//d * d    # the first remainder
    remainders[n]=len(answer)
    if n:
        while n:
            n *= 10
            m = n//d
            answer += str(m)
            n -= m * d  # new remainder
            #print (n, answer, [(i, r) for i, r in zip(range(d), remainders) if r > 0])
            if n:
                if remainders[n]:
                    answer = answer[:remainders[n]] + '(' + answer[remainders[n]:] + ')'
                    break
                remainders[n]=len(answer)
            else:
                break
    else:
        answer += '0'

    length = 76
    for i in range(0, len(answer), length):
        fout.write(answer[0+i:length+i] + '\n')
