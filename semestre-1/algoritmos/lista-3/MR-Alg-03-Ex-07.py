lista_barulhos = {
    "britadeira": 130,
    "cortador de grama": 106,
    "despertador": 70,
    "sala silenciosa": 40
}

volume = float(input("Digite um nível de volume (em decibéis): "))
if volume < min(lista_barulhos.values()) or volume > max(lista_barulhos.values()):
    print("Este nível está fora da lista de barulhos.")
else:
    if volume in lista_barulhos.values():
        barulho = [barulho for barulho, nivel in lista_barulhos.items() if nivel == volume][0]
        print(f"Som correspondente a {volume} decibéis: {barulho}")
    else:
        menorB, menorN = "", 1e15
        maiorB, maiorN = "", -1e15

        for barulho, nivel in lista_barulhos.items():
            if nivel > maiorN and nivel < volume:
                maiorB = barulho
                maiorN = nivel
            if nivel < menorN and nivel > volume:
                menorB = barulho
                menorN = nivel

        print(f"Um barulho de {volume} decibéis está entre os sons de {maiorB} ({maiorN} db) e {menorB} ({menorN} db)")