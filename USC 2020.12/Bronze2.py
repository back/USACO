"""
Daisy Chains (Python 3.6.9)
Roy One (royone)
Submitted: Sat, Dec 19, 2020 15:27:36 EST
Contest: USACO 2020 December Contest, Bronze
"""

n = int(input())
p = list(map(int, input().split()))

count = n

for i in range(n-1):
    total = p[i]
    items = 1
    
    present = [False] * 1001
    present [p[i]] = True
    
    for j in range(i+1, n):    # O(N^2)
        total += p[j]
        items += 1
        present [p[j]] = True
        if total % items == 0:
            if present[ int(total // items)  ]:
                count += 1

print(count)