frequencias = {
    "c": 261.63,
    "d": 293.66,
    "e": 329.63,
    "f": 349.23,
    "g": 392.00,
    "a": 440.00,
    "b": 493.88
}
oitava_referencia = 4

nome_nota = input("Digite uma nota musical: ")

# Verifica se há exatamente 2 caracteres na string
if len(nome_nota) != 2:
    print("Digite uma nota válida!")
else:
    nota = nome_nota[0].lower()
    oitava = nome_nota[1]
    
    # Verifica se o primeiro caractere é uma letra e se o segundo é um dígito
    if not (nota.isalpha() and oitava.isdigit()):
        print("Digite uma nota válida!")

    # Verifica se a nota é válida (de A a G) e se o dígito é válido (de 0 a 8)
    elif nota not in "abcdefg" or int(oitava) < 0 or int(oitava) > 8:
        print("Digite uma nota válida!")

    # Nota válida, calcular frequência
    else:
        oitava = int(oitava)
        frequencia = frequencias[nota] / 2 ** (oitava_referencia - oitava)

        print(f"Frequência da nota {nome_nota} = {frequencia}")