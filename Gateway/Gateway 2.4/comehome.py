fileName="""
LANG: PYTHON3
TASK: comehome
""".split()[-1]

def enc(c):
    x = ord(c)
    return x-65+26 if x < 97 else x-97

with open(fileName + '.in') as fin, open(fileName + '.out', 'w') as fout:
    p = int(fin.readline().strip())
    n = 52

    dis = [[-1]*n for _ in range(n)]
    for i in range(n):
        dis[i][i]=0    # make farms zero distant to itself! (may have inputs for roads)

    for line in fin.readlines():
        a,b,c = line.split()
        prev = dis[enc(a)][enc(b)]
        # different farms could have multiple connections
        # need to choose the shortest one:
        if prev < 0 or prev > int(c):
            dis[enc(a)][enc(b)] = dis[enc(b)][enc(a)] = int(c)
    
    for k in range(n):
        for i in range(n-1):
            for j in range(i+1,n):
                if dis[i][k] >= 0 and dis[k][j] >= 0:
                    x = dis[i][k] + dis[k][j]
                    if dis[i][j] < 0 or dis[i][j] > x: # -1 means infinite
                        dis[i][j] = dis[j][i] = x

    fout.write('{1} {0}\n'.format(*min((a,b) for a,b in zip(dis[-1][26:-1],'ABCDEFGHIJKLMNOPQRSTUVWXY') if a>0)))
