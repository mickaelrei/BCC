preco_total = 0

while True:
    idade = input("Digite a idade da pessoa (Enter para sair): ")
    if idade == "":
        break

    idade = int(idade)

    if 3 <= idade <= 12:
        preco_total += 14
    elif 13 <= idade <= 64:
        preco_total += 23
    elif idade >= 65:
        preco_total += 18

print(f"Preço total: R$ {preco_total:.2f}")