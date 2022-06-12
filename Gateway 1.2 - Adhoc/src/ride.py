fileName="""
LANG: PYTHON3
TASK: ride
""".split()[-1]


def enc(s):
    code = 1
    for c in s:
        code *= ord(c) - 64
    return code % 47


r1, r2 = open('%s.in' % fileName).readlines()

with open('%s.out' % fileName, 'w') as fout:
    fout.write('GO\n' if enc(r1) == enc(r2) else 'STAY\n')
    
    ## return  a ? b : c;
    ## return  b if a else c 

    
# fout = open('%s.out' % fileName, 'w')
# fout.write(...)
# fout.close()