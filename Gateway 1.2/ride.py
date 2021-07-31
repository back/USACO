fileName="""
LANG: PYTHON3
TASK: ride
""".split()[-1]

#from operator import mul
#from functools import reduce
#enc = lambda s: reduce(mul, (ord(c)-64 for c in s.strip())) % 47

def enc(s):
    code = 1
    for c in s:
        code *= ord(c) - 64
    return code % 47



r1, r2 = open('%s.in' % fileName).readlines()

with open('%s.out' % fileName, 'w') as fout:
    fout.write('GO\n' if enc(r1) == enc(r2) else 'STAY\n')
