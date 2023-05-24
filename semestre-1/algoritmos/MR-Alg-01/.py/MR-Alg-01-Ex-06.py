suco = float(input("Digite o valor do suco: "))
prato_principal = float(input("Digite o valor do prato principal: "))
sobremesa = float(input("Digite o valor da sobremesa: "))

total = (suco + prato_principal + sobremesa) * 1.1

print(f"O valor total da refeição, junto com a taxa de serviço é de R$ {total:.2f}")