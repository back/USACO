"""
Do You Know Your ABCs? (Python 3.6.9)
Roy One (royone)
Submitted: Sat, Dec 19, 2020 14:12:29 EST
Contest: USACO 2020 December Contest, Bronze
"""

inputs = list(map(int, input().split()))

a = min(inputs)
abc = max(inputs)

inputs.remove(a)
inputs.remove(abc)
inputs.remove(abc - a)

b  = min(inputs)
c  = abc - a - b
print(a, b, c)