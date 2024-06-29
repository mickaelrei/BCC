from math import log, floor

# Returns the number of zeros to the right of n!
def numZerosToRightFact(n: int) -> int:
    power = floor(log(n, 5))
    if power <= 0:
        return 0

    c = 0
    offset = 0
    for i in range(power, -1, -1):
        multiples = n // 5 ** i
        c += i * (multiples - offset)
        offset = multiples

    return c

n = 1_000_000_000_000_000_000
print(numZerosToRightFact(n))