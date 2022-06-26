file_in = open('cownomics.in')
data = file_in.read().strip().split('\n')

n, m = map(int, data[0].split(' '))

spotty_cows = []
plain_cows = []

spotty_cows = [data[i + 1] for i in range(n)]
plain_cows = [data[i + n + 1] for i in range(n)]

spots = []
plains = []

total = 0

# For every position, check if it can be a potential mutation location
# Check if the spotty and plain cows have any repeated characters at this position
for i in range(m):
    used = False
    for j in range(n):
        for k in range(n):
            if spotty_cows[j][i] == plain_cows[k][i]:
                used = True
                break
    if used == False:
        total += 1

# Add the answer to the output file using python standard file I/O system
file_out = open('cownomics.out', 'w')
file_out.write(str(total))
file_out.close()