from random import randrange

def binary_search(l: list, element: int|float) -> int:
    listSize = len(l)
    currentSearchIdx = listSize // 2
    currentIndexStep = listSize // 4

    steps = 0
    while 0 <= currentSearchIdx < listSize:
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

    # Item não existe
    return None

l = [randrange(0, 100) for _ in range(100)]
l.sort()

idx = binary_search(l, -2)