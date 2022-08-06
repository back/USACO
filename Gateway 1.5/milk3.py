"""
LANG: PYTHON3
TASK: milk3
"""

fileName = 'milk3'
with open(fileName + '.in') as fin:
    cap = list(map(int, fin.readline().split()))

vol = [0, 0, cap[2]]
answer = set()
status = set()

def pour(vol, fromIndex, toIndex):
    p = min(vol[fromIndex],  cap[toIndex] - vol[toIndex])
    if p:
        vol[toIndex] += p
        vol[fromIndex] -= p

        if vol[0] == 0:
            answer.add(vol[2])

        x = tuple(vol)
        if x not in status:
            status.add(x)
            print(x)
            otherIndex = 3 - fromIndex - toIndex
            pour(vol, toIndex,    fromIndex)
            pour(vol, toIndex,    otherIndex)
            pour(vol, otherIndex, toIndex)
            pour(vol, otherIndex, fromIndex)
            pour(vol, fromIndex,  otherIndex)

        vol[toIndex] -= p
        vol[fromIndex] += p   

pour(vol, 2, 1)
pour(vol, 2, 0)

with open(fileName + '.out', 'w') as fout:
    fout.write(' '.join(map(str, sorted(answer))) + '\n')

