'''Escreva um programa que leia os valores numéricos do usuário
até que uma linha em branco seja inserida. Exiba a soma total de valores inseridos pelo
usuário (ou 0,0 se o primeiro valor inserido for uma linha em branco). Conclua esta tarefa
usando recursão. Seu programa não pode usar nenhum laço de repetição.

Dica: o corpo da sua função recursiva precisará ler um valor do usuário e, em seguida,
determinar se deve ou não fazer uma chamada recursiva. Sua função não precisa de
nenhum parâmetro, mas precisará retornar um resultado numérico.'''

def totalValores():
	inp = input("Digite um número (enter para sair): ")
	if inp == "":
		return 0
	else:
		return float(inp) + totalValores()

def main():
	total = totalValores()

	print(f"Total = {total}")

if __name__ == "__main__":
	main()
