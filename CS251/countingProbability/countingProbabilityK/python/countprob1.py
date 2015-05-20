from itertools import chain, combinations
players = ['a','b']

def all_subsets(ss):
    return chain(*map(lambda x: combinations(ss, x), range(0, len(ss)+1)))

for subset in all_subsets(players):
    print(subset)
