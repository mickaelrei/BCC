from math import sqrt

def gen_identity(i, j): return 1 if (i == j) else 0

def mat(rows, cols, gen = gen_identity):
    return [[gen(i, j) for i in range(cols)] for j in range(rows)]

def mat_mul(a, b, rowsA, colsA, colsB):
    result = mat(rowsA, colsB, lambda i, j: 0)
    for i in range(rowsA):
        for j in range(colsB):
            for k in range(colsA):
                result[i][j] += a[i][k] * b[k][j]
    return result

def print_mat(m):
    for row in m:
        print("[" + " ".join([str(x).zfill(2) for x in row]) + "]")

def cholesky(a, rows, cols):
    r = mat(rows, cols, lambda i, j: 0)

    for row in range(rows):
        # breakpoint()
        for col in range(cols):
            # main diagonal
            if row == col:
                c = a[row][row]
                for i in range(row):
                    c -= r[row][i] * r[i][row]

                if (c < 0): raise ValueError("Invalid matrix")
                r[row][row] = sqrt(c)
                continue
            
            # rest of matrix
            if (r[min(row, col)][min(row, col)] != 0):
                c = a[row][col]
                for i in range(row):
                    c -= r[row][i]*r[i][col]
                r[row][col] = c / r[min(row, col)][min(row, col)]

    lower = mat(rows, cols, lambda i, j: r[i][j] if (i <= j) else 0)
    upper = mat(rows, cols, lambda i, j: r[i][j] if (i >= j) else 0)
    return lower, upper

# [  2 0 0 ]
# [  6 1 0 ]
# [ -8 5 3 ]

a = mat(3, 3)
a[0][0] = 4
a[0][1] = 12
a[0][2] = -16
a[1][0] = 12
a[1][1] = 37
a[1][2] = -43
a[2][0] = -16
a[2][1] = -43
a[2][2] = 98

# lower * upper = a
lower, upper = cholesky(a, 3, 3)
a1 = mat_mul(lower, upper, 3, 3, 3)

print_mat(lower)
print()
print_mat(upper)
print()
print_mat(a1)