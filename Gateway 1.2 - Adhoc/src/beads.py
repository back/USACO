fileName="""
LANG: PYTHON3
TASK: beads
""".split()[-1]

with open(fileName + '.in') as fin:
    length = int(fin.readline().strip())
    beads  = fin.readline().strip() * 2
    
answer = 0
for i in range(length):
    collected = red = blue = 0
    for c in beads[i:i+length]:
        if c=='w':
            collected += 1
            continue
        if c=='r':
            red = blue + 1
        if c=='b':
            blue = red + 1
        if red > 2 or blue > 2:
            break
        collected += 1
    if collected > answer:
        answer = collected

with open(fileName + '.out', 'w') as fout:
    fout.write( '%d\n' % answer )
