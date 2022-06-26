"""

LANG: PYTHON3
TASK: sort3
"""

from operator import itemgetter

fileName = 'sort3'
with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())
    x = list(map(int, (i.strip() for i in fin.readlines())))

    # remove the already in-position items
    rst = [ i for i in zip(x,sorted(x)) if i[0]!=i[1] ]

    # zero out the swappable items
    for i in range(len(rst)-1):
        for j in range(i+1, len(rst)):
            if rst[i][0] == rst[j][1] and rst[i][1] == rst[j][0]:
                rst[i], rst[j] = (0,0), (0,0)

    swap_items = rst.count((0,0))
    loop_items = len(rst) - swap_items

    answer = swap_items//2 + loop_items//3*2
    fout.write('%s\n' % answer)
