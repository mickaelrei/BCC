idade = int(input("Digite sua idade: "))

if idade < 0:
    print("Erro: não é possível calcular idade negativa!")
else:
    idade_canina = 5.25 * min(idade, 2)
    if idade > 2:
        idade_canina += 4 * (idade - 2)

    print(f"Sua idade canina é de {idade_canina} anos.")