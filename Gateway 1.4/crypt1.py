"""

LANG: PYTHON3
TASK: crypt1
"""

fileName = 'crypt1'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:

    fin.readline()
    s = fin.readline().split()
    c = list(map(int, s))

    def chk(allows, number):
        for x in str(number):
            if x not in allows:
                return False
        return True

    answer=0
    for d1 in c:
        for d2 in c:
            for d3 in c:
                for d4 in c:
                    for d5 in c:
                        n1 = d1 * 100 + d2 * 10 + d3
                        n2 = d4 * 10 + d5

                            
                        n3 = n1 * d5
                        if n3>999 or not chk(s, n3):
                            continue
                        n4 = n1 * d4
                        if n4>999 or not chk(s, n4):
                            continue

                        n5 = n4 * 10 + n3
                        if chk(s, n5):
                            answer += 1
                            print (n1, n2, n3, n4, n5)

    #print(c)
    #print(answer)
    
    fout.write('%s\n' % answer)
