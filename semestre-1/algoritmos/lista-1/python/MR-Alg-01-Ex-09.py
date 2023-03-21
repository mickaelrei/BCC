inicial = float(input("Digite o valor inicial do investimento: "))

taxa = .12
anos = 3
for i in range(1, anos+1):
    valor = inicial * (1 + taxa)**i
    print(f"Valor do investimento após {i} anos: R$ {valor:.2f}")