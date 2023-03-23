from random import randrange

def binary_search(l: list, element: int|float) -> int:
    listSize = len(l)
    currentSearchIdx = listSize // 2
    currentIndexStep = listSize // 4

    steps = 0
    while True:

        val = l[currentSearchIdx]
        if val == element:
            return currentSearchIdx
        else:
            if val > element:
                currentSearchIdx -= currentIndexStep
            else:
                currentSearchIdx += currentIndexStep
            currentIndexStep = max(currentIndexStep // 2, 1)
        
        steps += 1

l = [randrange(0, 1_000) for x in range(1000000)]
l.sort()

for i in range(len(l)):
    if i % (len(l) / 100) == 0:
        print(f"{i / len(l) * 100:.3f}%")
    rand_idx = randrange(0, len(l))
    element = l[rand_idx]
    search_idx = binary_search(l, element)
    if l[search_idx] != element:
        print(f"Error!\nElement: {element}\nReal index\n{rand_idx}\nGiven index: {search_idx}")