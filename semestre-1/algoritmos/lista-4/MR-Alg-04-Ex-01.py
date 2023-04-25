soma = 0
quant = 0

while True:
    num = float(input("Digite um número (0 para sair): "))
    if num == 0:
        break

    soma += num
    quant += 1

media = soma / quant
print(f"Média = {media}")