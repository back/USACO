fileName="""
LANG: PYTHON3
TASK: namenum
""".split()[-1]

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:

    k = 'ABCDEFGHIJKLMNOPRSTUVWXYQZ'
    v = '222333444555666777888999##'
    mapping = dict(zip(k, v))

    found=False

    serial = fin.readline().strip()
    with open('dict.txt') as dtxt:
        for name in dtxt.readlines():
            if serial == ''.join(mapping[i] for i in name.strip()):
                fout.write(name)
                found=True
            
    if not found:
        fout.write('NONE\n')
