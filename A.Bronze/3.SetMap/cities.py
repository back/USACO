from collections import defaultdict

pairs = []
with open('citystate.in') as fin:
    for _ in range(int(fin.readline())):
        city, state = fin.readline().strip().split()
        city = city[:2]  # We only care about the first two letters of the city
        if city != state:
            pairs.append((city, state))

seen = defaultdict(int)
total = 0
for c, s in pairs:
    total += seen[s + c]
    seen[c + s] += 1

print(total, file=open('citystate.out', 'w'))
