fin = open('lostcow.in')
x, y = map(int, fin.readline().split())

distance = 1
travelled = 0
move_right = True

while True:
    if move_right:
        if x > y or x + distance < y:
            travelled += distance * 2
            distance += distance
            move_right = False
        else:
            travelled += y - x
            break
    else:
        if x < y or x - distance > y:
            travelled += distance * 2
            distance += distance
            move_right = True
        else:
            travelled += x - y
            break
        
with open('lostcow.out', 'w') as fout:
    print(travelled, file=fout)
