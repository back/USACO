fileName="""
LANG: PYTHON3
TASK: wormhole
""".split()[-1]

def all_pairs(lst):
    if len(lst) < 2:
        yield []
    else:
        a = lst[0]
        for i in range(1,len(lst)):
            pair = (a,lst[i])
            for rest in all_pairs(lst[1:i]+lst[i+1:]):
                yield [pair] + rest

def check_p_loop(i, xy_pair, xy_next, passed, isTeleporting):
    np = xy_pair[i] if isTeleporting else xy_next[i]
    if np < 0:
        return False
    if len(passed) > len(xy_pair) * 2:
        print('passed: ', passed)
        return True
    passed.append(np)
    return check_p_loop(np, xy_pair, xy_next, passed, not isTeleporting)

def check_loop(i, xy_pair, xy_next):
    if check_p_loop(i, xy_pair, xy_next, [], True):
        return True
    if check_p_loop(i, xy_pair, xy_next, [], False):
        return True
    return False

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    n = int(fin.readline().strip())
    xy = [[int(i) for i in line.split()] for line in fin.readlines()]
    print('xy:', xy)

    xy_next = [-1] * n
    for i in range(n):
        x, y = xy[i]
        for j in range(n):
            a, b = xy[j]
            if b==y and a>x:
                if xy_next[i]<0:
                    xy_next[i] = j
                else:
                    c, d = xy[ xy_next[i] ]
                    if a<c:
                        xy_next[i] = j
    print('xy_next:', xy_next)

    count = 0
    for p in all_pairs(list(range(n))):
        print ('=============================', count)
        xy_pair = [-1] * n
        for p1, p2 in p:
            xy_pair[p1] = p2
            xy_pair[p2] = p1
        print('xy_pair:', list(range(n)))
        print('xy_pair:', xy_pair)
        for i in range(n):
            if check_loop(i, xy_pair, xy_next):
                print ('check_loop: True')
                count +=1
                break

    print (count)

    fout.write('%s\n' % count)
