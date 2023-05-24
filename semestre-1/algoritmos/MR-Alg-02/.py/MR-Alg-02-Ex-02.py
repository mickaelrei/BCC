total_segundos = int(input("Digite o total de segundos: "))

# Valores numéricos
segundos = total_segundos % 60
minutos = total_segundos // 60 % 60
horas = total_segundos // (60 * 60) % 24
dias = total_segundos // (60 * 60 * 24)

# Transforma em texto
segundos = str(segundos).rjust(2, "0")
minutos = str(minutos).rjust(2, "0")
horas = str(horas).rjust(2, "0")
dias = str(dias)

# Mostra o horário
print(f"Horário formatado: {dias}:{horas}:{minutos}:{segundos}")