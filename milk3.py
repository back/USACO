"""

LANG: PYTHON3
TASK: milk3
"""

fileName = 'milk3'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    cap = list(map(int, fin.readline().split()))
    vol = [0, 0, cap[2]]

    result = set()
    result.add(','.join(map(str,vol)))

    answer = set()

    def pour(vol, fromIndex, toIndex):
        p = min(vol[fromIndex],  cap[toIndex] - vol[toIndex])
        if p:
            newVol = [i for i in vol]
            newVol[toIndex] += p
            newVol[fromIndex] -= p
            if newVol[0] == 0:
                answer.add(newVol[2])
            tag = ','.join(map(str,newVol))
            if tag not in result:
                result.add(tag)
                byIndex = 3 - fromIndex - toIndex
                pour(newVol, toIndex, byIndex)
                pour(newVol, byIndex, toIndex)
                pour(newVol, fromIndex, byIndex)
                pour(newVol, byIndex, fromIndex)

    pour(vol, 2, 1)
    pour(vol, 2, 0)

    print (result)
    print (answer)
    fout.write(' '.join(map(str, sorted(answer))))
    fout.write('\n')

