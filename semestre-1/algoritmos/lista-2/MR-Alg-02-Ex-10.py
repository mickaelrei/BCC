matricula = int(input("Digite o número de matrícula: "))
while not (matricula <= 10**6 - 1):
    print("O número não pode passar de 6 dígitos!")
    matricula = int(input("Digite o número de matrícula: "))

ano = matricula // 10000
semestre = matricula % 10000 // 1000

# Converte ano pra string (adiciona zero à direita se preciso)
ano = str(ano).rjust(2, "0")

print(f"Ano {ano}, semestre {semestre}")