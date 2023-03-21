print("Programa para calcular a área de um triângulo, baseado no comprimento dos lados")
l1 = float(input("Lado 1 (em cm): "))
l2 = float(input("Lado 2 (em cm): "))
l3 = float(input("Lado 3 (em cm): "))

l = (l1 + l2 + l3)/2

area = (l * (l - l1) * (l - l2) * (l - l3))**.5

print(f"Área do triângulo: {area} cm²")