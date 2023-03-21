import math

r = float(input("Digite o raio (em cm): "))

area = math.pi * r**2
volume = 4/3 * math.pi * r**3

print(f"Área de um círculo com raio {r} = {area}cm²")
print(f"Volume de uma esfera com raio {r} = {volume}cm³")