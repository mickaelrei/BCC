from math import sqrt

print("Programa que calcula raízes de uma função de segundo grau.")

a = int(input("Digite o valor de a: "))
b = int(input("Digite o valor de b: "))
c = int(input("Digite o valor de c: "))

# Escreve a função em texto
funcao_texto = f"{a}x² + {b}x + {c}"

delta = b**2 -4 * a * c
if delta < 0:
    print(f"A função {funcao_texto} não possui raízes reais.")
elif delta == 0:
    x = -b / 2*a
    print(f"A função {funcao_texto} possui uma raiz real: {x}")
else:
    x1 = (-b + sqrt(delta)) / 2*a
    x2 = (-b - sqrt(delta)) / 2*a
    print(f"A função {funcao_texto} possui duas raízes reais: ({x1}, {x2})")