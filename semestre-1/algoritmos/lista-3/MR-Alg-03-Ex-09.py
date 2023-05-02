feriados = {
    "contraternização universal": (1, "janeiro"),
    "tiradentes": (21, "abril"),
    "dia do trabalho": (1, "maio"),
    "independência do brasil": (7, "setembro"),
    "nossa senhora aparecida": (12, "outubro"),
    "finados": (2, "novembro"),
    "proclamação da república": (15, "novembro"),
    "natal": (25, "dezembro")
}

meses = (
    "janeiro",
    "fevereiro",
    "março",
    "abril",
    "maio",
    "junho",
    "julho",
    "agosto",
    "setembro",
    "outubro",
    "novembro",
    "dezembro"
)

mes = input("Digite um mês: ")
dia = int(input("Digite um dia do mês: "))

# Verifica mes e dia válidos
if mes.lower() not in meses or dia < 1 or dia > 31:
    print("Mês ou dia inválidos!")
else:
    for feriado_nome, (feriado_dia, feriado_mes) in feriados.items():
        if feriado_dia == dia and feriado_mes.lower() == mes.lower():
            print(f"{dia} de {mes} é um feriado nacional: {feriado_nome.title()}")