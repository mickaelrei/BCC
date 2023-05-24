def media(a, b):
    return (a + b) / 2

x = float(input("Digite um número: "))

raiz = x / 2
i = 0
while abs(raiz * raiz - x) > 10**-12:
    i += 1
    raiz = media(raiz, x / raiz)
    
print(f"Aproximação de raiz quadrada de {x} = {raiz}\nIterações = {i}")