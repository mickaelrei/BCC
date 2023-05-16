print("Informe as medidas dos lados de um triângulo:")
l1 = float(input("Comprimento do primeiro lado: "))
l2 = float(input("Comprimento do segundo lado: "))
l3 = float(input("Comprimento do terceiro lado: "))

if l1 == l2 == l3:
    print("O triângulo é equilátero.")
elif l1 == l2 or l1 == l3 or l2 == l3:
    print("O triângulo é isósceles.")
else:
    print("O triângulo é escaleno.")