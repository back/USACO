fileName="""
LANG: PYTHON3
TASK: palsquare
""".split()[-1]

BS="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_base(n, b): 
    return "0" if not n else to_base(n//b, b).lstrip("0") + BS[n%b]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    b = int(fin.readline().strip())
    for i in range(1,301):
        q=to_base(i*i,b)
        if q==q[::-1]:
            fout.write('%s %s\n' % (to_base(i, b), q))
