fileName="""
LANG: PYTHON3
TASK: dualpal
""".split()[-1]

BS="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_base(n, b): 
    return "0" if not n else to_base(n//b, b).lstrip("0") + BS[n%b]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:

    n, s = map(int, fin.readline().split())
    
    while n:
        s+=1
        count=0
        for b in range(2,11):
            q=to_base(s,b)
            if q==q[::-1]:
               count+=1
               if (count>1):
                   fout.write('%s\n' % s)
                   n-=1
                   break
