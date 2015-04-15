import math
X1 = set(())
X2 = set(())
result = 0

for i in range(0,21):
    result += math.factorial(i)
    X1.add(result)
    if i in range(0,19):
        X2.add(result)
print X1 ^ X2
