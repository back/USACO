n, q = map(int, input().split())
p = [[0 for _ in range(n+1)] for _ in range(n+1)]

star = ord('*')

for row in range(1,n+1):
    rowSum = 0
    col = 0
    for c in input():
        if ord(c)==star:
            rowSum+=1
        col += 1
        p[row][col]=p[row-1][col]+rowSum
                
for _ in range(q):
    y1, x1, y2, x2 = map(int, input().split())
    
    a = p[y1-1][x1-1]
    b = p[y1-1][x2]
    c = p[y2][x1-1]
    d = p[y2][x2]
    
    print(d-b-c+a)
