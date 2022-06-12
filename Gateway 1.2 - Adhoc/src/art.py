MAX_COLOR = 9

"""
Bounding boxes of each of the colors.
The first element won't be used (colors go from 1-9)
"""
left = [0] * (MAX_COLOR + 1)
right = [0] * (MAX_COLOR + 1)
down = [0] * (MAX_COLOR + 1)
up = [0] * (MAX_COLOR + 1)

for c in range(1, MAX_COLOR + 1):
    left[c], up[c] = float('inf'), float('inf')
    right[c], down[c] = -1, -1

valid_start = [False] * MAX_COLOR
with open('art.in') as read:
    n = int(read.readline().strip())
    art = [None] * n
    for r in range(n):
        art[r] = [int(x) for x in read.readline().strip()]
        for c in range(n):
            if art[r][c] != 0:
                curr = art[r][c]
                left[curr] = min(left[curr], c)
                right[curr] = max(right[curr], c)
                down[curr] = max(down[curr], r)
                up[curr] = min(up[curr], r)
                valid_start[curr] = True

for color in range(1, MAX_COLOR + 1):
    if any(p[color] == float('inf') for p in [left, right, down, up]):
        continue

    for c in range(int(up[color]), int(down[color] + 1)):
        for k in range(int(left[color]), int(right[color] + 1)):
            if art[c][k] != color:
                valid_start[art[c][k]] = False

print(sum(valid_start), file=open('art.out', 'w'))