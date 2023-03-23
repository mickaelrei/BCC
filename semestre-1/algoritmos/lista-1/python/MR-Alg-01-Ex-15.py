from math import tan, pi

l = float(input("Digite o comprimento do lado do polígono (em cm): "))
n = float(input("Digite o número de lados do polígono: "))

area = (n * l**2) / (4 * tan(pi / n))

print(f"Área do polígono regular de {n} lados = {area:.2f} cm²")