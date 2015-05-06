import math

first     = {}
second    = {}
intersect = {}

firstSet   = set(( )) 
secondSet  = set(( ))
diffSet    = set(( ))
resolution = 0
for i in range(1, 21):
    resolution += math.factorial(i)
    first[i] = resolution
    firstSet.add(first[i])

    if i in range(0, 2):
        second[i] = resolution;
        secondSet.add(second[i])
    
    diffSet =  firstSet.intersection(secondSet)

intersect = list(diffSet)
intersect.sort()

print first
print second
print intersect
