n = int(input("Digite uma data no formato dia, mês e ano, sem divisória como barra, traço ou dois pontos: "))
while not n <= 10**6 - 1:
    print(f"Para ser uma data válida, são necessários 6 dígitos, ou seja, um valor entre 000001 e 999999.")
    n = int(input("Digite uma data no formato dia, mês e ano, sem divisória como barra, traço ou dois pontos: "))

# Valor numérico
ano = n % 100
mes = n % 10000 // 100
dia = n // 10000

# Converte para string
ano = str(ano).rjust(2, "0")
mes = str(mes).rjust(2, "0")
dia = str(dia).rjust(2, "0")

# Mostra ao contrário
print(f"Data ao contrário: {ano + mes + dia}")