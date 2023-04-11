'''Número de matrícula. Suponha que uma escola utilize, como código de matrícula, um
número inteiro no formato AASDDD, onde:
• os dois primeiros dígitos, representados pela letra A, são os dois últimos algarismos do ano
da matrícula;
• o terceiro dígitos, representado pela letra S, vale 1 ou 2, conforme o aluno tenha se
matriculado no 1o ou 2o semestre;
• os três últimos dígitos, representados pela letra D, correspondem à ordem da matrícula do
aluno, no semestre e no ano em questão.
Crie um programa Python que leia o número de matrícula de um aluno e imprima o ano e o
semestre em que ele foi matriculado. Por exemplo, um número de matrícula 182034 deve
resultar ano 18 e semestre 2.'''

matricula = int(input("Digite o número de matrícula: "))
while not (matricula <= 10**6 - 1):
    print("O número não pode passar de 6 dígitos!")
    matricula = int(input("Digite o número de matrícula: "))

ano = matricula // 10000
semestre = matricula % 10000 // 1000

# Converte ano pra string (adiciona zero à direita se preciso)
ano = str(ano).rjust(2, "0")

print(f"Ano {ano}, semestre {semestre}")