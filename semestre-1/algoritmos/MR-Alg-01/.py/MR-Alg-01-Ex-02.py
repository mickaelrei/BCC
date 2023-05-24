nome = input("Qual seu nome? ")
while nome == "":
    print("Digite seu nome!")
    nome = input("> ")

print("Olá, " + nome + "!")