valores = [
    4.95,
    9.95,
    14.95,
    19.95,
    24.95
]

desconto = .6

for valor_original in valores:
    valor_desconto = valor_original * desconto
    valor_final = valor_original - valor_desconto

    print(f"Original: R$ {valor_original:.2f}\nDesconto: R$ {valor_desconto:.2f}\nFinal: R$ {valor_final:.2f}\n")