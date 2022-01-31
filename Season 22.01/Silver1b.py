import sys

n = int(sys.stdin.readline())
p =  [list(map(int, lin.split())) for lin in sys.stdin.readlines()]


for a, b in p:
    step = 0
    while a != b:
        while a > b:
            if a % 2 == 1:
                a += 1
                step += 1
            else:
                a //= 2
                step += 1
        while a < b:
            if b-a < 4:
                step += b-a
                a = b
                break
            if b % 2 == 1:
                b -= 1
                step += 1
            else:
                b //= 2
                step += 1
    print(step)