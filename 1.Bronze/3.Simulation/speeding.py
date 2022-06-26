with open('speeding.in') as fin:
    n, m = map(int, fin.readline().split())
    
    travel = [0] * 100

    pos = 0
    for _ in range(n):
        seg, spd = map(int, fin.readline().split())
        seg_end = pos + seg
        while pos < seg_end:
            travel[pos] = spd
            pos += 1

    pos = 0
    ans = 0
    for _ in range(m):
        seg, spd = map(int, fin.readline().split())
        seg_end = pos + seg
        while pos < seg_end:
            if spd - travel[pos] > ans:
                ans = spd - travel[pos]
            pos += 1

with open('speeding.out', 'w') as fout:
    print(ans, file=fout)
