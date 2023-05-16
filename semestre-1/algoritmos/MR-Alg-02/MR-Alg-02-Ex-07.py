quantDigitos = 3
minimo = 10 ** (quantDigitos - 1)
maximo = 10 ** (quantDigitos) - 1

n = int(input(f"Digite um número de {quantDigitos} digitos: "))
while not (minimo <= n <= maximo):
    print(f"O número precisa ter {quantDigitos} digitos!")
    n = int(input(f"Digite um número de {quantDigitos} digitos: "))

centena = n // 100
dezena = n // 10 % 10
unidade = n % 10

print(f"Centena: {centena}")
print(f"Dezena: {dezena}")
print(f"unidade: {unidade}")