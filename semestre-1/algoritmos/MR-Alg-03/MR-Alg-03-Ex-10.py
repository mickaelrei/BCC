posicao = input("Digite uma posição no tabuleiro de xadrez: ")

coluna = posicao[0]
linha = int(posicao[1])

if coluna in "aceg":
    cor = "preto"
else:
    cor = "branco"

# Se a linha for um número par, inverte a cor
if linha % 2 == 0:
    if cor == "preto":
        cor = "branco"
    else:
        cor = "preto"

print(f"Cor da posição {posicao}: {cor}")