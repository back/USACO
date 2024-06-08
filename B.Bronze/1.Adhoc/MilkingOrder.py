fin=open('milkorder.in')

n, m, k   = map(int, fin.readline().split())
hierarchy = list(map(int, fin.readline().split()))
fixed     = [list(map(int, fin.readline().split())) for _ in range(k)]
cows = [0] * n

for cow, fix in fixed:
    cows[fix-1] = cow    # be careful about the 0 based index!
    
if 1 in cows:
    # Case 1
    ans = cows.index(1) + 1
    
elif 1 in hierarchy:
    # Case 2
    i = 0
    pointer = 0
    while pointer <= m - 1:
        if hierarchy[pointer] in cows:
            i = cows.index(hierarchy[pointer]) + 1
            pointer += 1
        else:
            if cows[i] == 0:
                cows[i] = hierarchy[pointer]
                i += 1
                pointer += 1
            else:
                i += 1
    for i in range(n):
        if cows[i] == 1:
            ans = i + 1
            break

else:
    # Case 3
    i = n - 1
    pointer = m - 1
    while pointer >= 0:
        if hierarchy[pointer] in cows:
            i = cows.index(hierarchy[pointer]) - 1
            pointer -= 1
        else:
            if cows[i] == 0:
                cows[i] = hierarchy[pointer]
                i -= 1
                pointer -= 1
            else:
                i -= 1

    for i in range(n):
        if cows[i] == 0:
            ans = i + 1
            break

with open('milkorder.out', 'w') as fout:
    print(ans, file=fout)
