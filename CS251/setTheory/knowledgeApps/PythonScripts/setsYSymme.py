import math
Y1 = set(())
Y2 = set(())
result = 1

for i in range(0,21):
    result *= math.factorial(i)
    Y1.add(result)
    if i in range(0,19):
        Y2.add(result)
print Y1 ^ Y2
