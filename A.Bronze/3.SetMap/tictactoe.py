with open('tttt.in') as fin:
    grid = [r.strip() for r in fin.readlines()]

answers = set()

for row in range(3):
    answers.add(tuple(set(grid[row])))

for col in range(3):
    answers.add(tuple(set(row[col] for row in grid)))
        
answers.add(tuple(set(grid[i][i] for i in range(3))))
answers.add(tuple(set(grid[i][2-i] for i in range(3))))

with open('tttt.out', 'w') as f:
    f.write('%s\n' % len(list(x for x in answers if len(x) == 1)))
    f.write('%s\n' % len(list(x for x in answers if len(x) == 2)))
    