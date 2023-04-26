n = int(input("Digite um número de 4 digitos: "))
while not (1000 <= n <= 9999):
    print("O número precisa ter 4 digitos!")
    n = int(input("Digite um número de 4 digitos: "))

# 1°: Converte o número para string para tratar como lista
# 2°: Converte cada caracter da string para int, finalizando com uma lista dos dígitos
# 3°: Utiliza a função sum() para obter a soma da lista de digitos
soma = sum([int(x) for x in str(n)])

print(f"Soma dos dígitos de {n}: {soma}")