from math import sqrt, log10, floor
import random

def gen_identity(i, j): return 1 if (i == j) else 0

def gen_zero(i, j): return 0

def mat(rows, cols, gen = gen_identity):
    return [[gen(i, j) for j in range(cols)] for i in range(rows)]

def mat_mul(a, b):
    rowsA = len(a)
    colsA = len(a[0])
    colsB = len(b[0])

    result = mat(rowsA, colsB, gen_zero)
    for i in range(rowsA):
        for j in range(colsB):
            for k in range(colsA):
                result[i][j] += a[i][k] * b[k][j]
    return result

def mat_transpose(m):
    return mat(len(m[0]), len(m), lambda i, j: m[j][i])

def print_mat(m, precision=2):
    maxValue = max(max(row) for row in m)
    maxDigits = floor(log10(max(abs(maxValue), 1))) + 1
    hasNegatives = any(any(x < 0 for x in row) for row in m)
    hasFloats = any(any(str(x) != str(int(x)) for x in row) for row in m)
    maxChars = maxDigits + (1 + precision if hasFloats else 0) + (1 if hasNegatives else 0)

    for row in m:
        print("[ " + " ".join([str(round(x, precision)).rjust(maxChars, " ") for x in row]) + " ]")

def cholesky(a):
    rows = len(a)

    r = mat(rows, rows, gen_zero)

    for row in range(rows):
        for col in range(row + 1):
            # sum for current cell
            c = 0
            for i in range(col):
                c += r[row][i] * r[col][i]

            if row == col:
                # main diagonal
                r[row][row] = sqrt(a[row][row] - c)
            else:
                # rest of matrix
                r[row][col] = (a[row][col] - c) / r[col][col]

    return r, mat_transpose(r)

d = 20
m = mat(d, d, lambda i, j: random.randint(-10, 10))
a = mat_mul(mat_transpose(m), m)

# lower * upper = a
lower, upper = cholesky(a)
a1 = mat_mul(lower, upper)

print("original A:")
print_mat(a)
print("\nlower:")
print_mat(lower)
print("\nupper:")
print_mat(upper)
print("\nlower * upper (same as A):")
print_mat(a1)

# diff matrix
diff = mat(d, d, lambda i, j: a[i][j] - a1[i][j])
print("\ndiff (should be all zeros):")
print_mat(diff)