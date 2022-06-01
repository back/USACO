"""
LANG: PYTHON3
TASK: test
"""

with open('test.in') as fin, open('test.out', 'w') as fout:
    fout.write ('%s\n' % sum(map(int, fin.readline().split())))
