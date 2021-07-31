fileName="""
LANG: PYTHON3
TASK: friday
""".split()[-1]

fin = open('%s.in' % fileName) 
N = int(fin.readline().strip())

rslt = [0, 0, 0, 0, 0, 0, 0]
days = 13 - 31
for year in range(1900, 1900+N):
    for month in range(12):
        if month in (0,1,3,5,7,8,10):
            days += 31
        elif month in (4,6,9,11):
            days += 30
        else:
            days += 28
            if year % 400 == 0 or year % 4 == 0 and year % 100 > 0:
                days += 1
        rslt[ (days+1) % 7 ] += 1

with open('%s.out' % fileName, 'w') as fout:
    fout.write( '%s\n' % ' '.join(map(str,rslt)) )
