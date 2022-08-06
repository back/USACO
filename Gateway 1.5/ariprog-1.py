import time

N = 21
M = 250

answer = []
max = M * M * 2
bisquare = [0] * (max + 1)
for i in range(M + 1):
    for j in range(i, M + 1):
        bisquare[i * i + j * j] = 1

loop_count = 0
t0 = time.time()
for i in range(max + 1 - N + 1):
    if bisquare[i] == 0:
        continue
    for j in range(1, (max - i) // (N - 1) + 1):
        count = 1
        b = i + j
        while bisquare[b]:
            loop_count += 1
            if count == N - 1:
                answer.append((i, j))
                break
            count += 1
            b += j

t1 = time.time()
print(f"{t1 - t0}, {loop_count}")
loop_count = 0
result = []
for i in range(max + 1):
    if bisquare[i] == 0:
        continue
    for step in range(1, i // (N - 1) + 1):
        checks = N
        b = i - step
        while bisquare[b]:
            loop_count += 1
            if checks == 2:
                result.append((b, step))
                break
            checks -= 1
            b -= step

t2 = time.time()
print(f"{t2 - t1}, {loop_count}")