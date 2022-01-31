import sys
n = int(sys.stdin.readline())
s =  [list(map(int, x.split())) for x in sys.stdin.readlines()]
for a, b in s:
    answer = 0
    while a != b:
        while a > b:
            if a % 2 == 1:
                a += 1
                answer += 1
            else:
                a //= 2
                answer += 1
        while a < b:
            if b-a < 6:
                answer += b-a
                a = b
                break
            if b % 2 == 1:
                b -= 1
                answer += 1
            else:
                b //= 2
                answer += 1
    print(answer)