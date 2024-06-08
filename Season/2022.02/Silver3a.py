import sys

t=int(sys.stdin.readline())
for x in range(t):
    m, n, k = map(int, sys.stdin.readline().split())
    f=list(map(int, sys.stdin.readline().split()))
    
    f_min = 1
    f_max = k
    skip  = 0

    while f:
        #print(f, skip, f_min, f_max)
        filed = False
        for i in range(skip, min(skip+k, len(f))):
            if f[i] >= f_min and f[i] <= f_max:
                f.pop(i)
                filed = True
                break
        if filed:
            if skip + k > len(f) and skip > 0:
                skip -= 1
        elif f_min not in f and f_max < m:
            f_min += 1
            f_max += 1
        elif skip + k < len(f):
            skip += 1
        else:
            break
    print('NO' if f else 'YES')
    