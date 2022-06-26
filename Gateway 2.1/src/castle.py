"""

LANG: PYTHON3
TASK: castle
"""
import time
start = time.time()

fileName = 'castle'
with open(fileName + '.in') as fin:
    w,h = list(map(int, fin.readline().split()))
    room_walls = [list(map(int,line.split())) for line in fin.readlines()]

room_codes = [list(range(i*w, i*w+w)) for i in range(h)]

def check_code(i, j):
    wall = room_walls[i][j]
    code = room_codes[i][j]
    if wall < 8: # open to the south
        if code < room_codes[i+1][j]:
            room_codes[i+1][j] = code
            check_code(i+1, j)
    else:
        wall -= 8
    if wall < 4: # open to the east
        if code<room_codes[i][j+1]:
            room_codes[i][j+1] = code
            check_code(i, j+1)
    else:
        wall -= 4
    if wall < 2: # open to the north
        if code<room_codes[i-1][j]:
            room_codes[i-1][j] = code
            check_code(i-1, j)
    else:
        wall-=2
    if wall < 1: # open to the west
        if code<room_codes[i][j-1]:
            room_codes[i][j-1] = code
            check_code(i, j-1)

for i in range(h):
    for j in range(w):
        check_code(i, j)

room_sizes={}
for i in range(h):
    for j in range(w):
        code = room_codes[i][j]
        if code in room_sizes:
            room_sizes[code] += 1
        else:
            room_sizes[code] = 1

min_i = 0
min_j = 0
max_size = 0
max_direction = ''
for j in range(w):
    for i in range(h-1, -1, -1):
        wall = room_walls[i][j]
        merged_east = 0
        merged_north = 0
        if wall >= 8:
            wall -= 8
        if wall >= 4 and j < w-1:
            if room_codes[i][j] != room_codes[i][j+1]:
                merged_east = room_sizes[room_codes[i][j]] + room_sizes[room_codes[i][j+1]]
            wall -= 4
        if wall >= 2 and i > 0:
            if room_codes[i][j] != room_codes[i-1][j]:
                merged_north = room_sizes[room_codes[i][j]] + room_sizes[room_codes[i-1][j]]
        if merged_north > max_size:
            min_i = i
            min_j = j
            max_size = merged_north
            max_direction = 'N'
        if merged_east > max_size:
            min_i = i
            min_j = j
            max_size = merged_east
            max_direction = 'E'

#print(room_walls)
#print(room_codes)
#print(room_sizes)

with open(fileName + '.out', 'w') as fout:
    fout.write('%s\n' % len(room_sizes))
    fout.write('%s\n' % max(room_sizes.values()))
    fout.write('%s\n' % max_size)
    fout.write('%s %s %s\n' % (min_i+1, min_j+1, max_direction))

print('Elapsed seconds: %s' % (time.time() - start) )
