meses = {
    "janeiro": 31,
    "fevereiro": "28 ou 29",
    "março": 31,
    "abril": 30,
    "maio": 31,
    "junho": 30,
    "julho": 31,
    "agosto": 31,
    "setembro": 30,
    "outubro": 31,
    "novembro": 30,
    "dezembro": 31,
}

mes = input("Digite um mês: ")
if mes.lower() not in meses.keys():
    print(f"{mes} não é um mês válido!")
else:
    print(f"O mês de {mes} possui {meses[mes.lower()]} dias")