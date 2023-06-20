'''Uma cartela de bingo vencedora deve conter
uma linha (ou coluna ou diagonal) com 5 números que foram sorteados. Normalmente, nas
cartelas de papel, os jogadores fazem um X sobre o número sorteado. Na sua implementação
(no seu dicionário representando a cartela), vamos substituir por 0 o número que foi sorteado.
Escreva uma função que receba como único parâmetro um dicionário representando uma
cartela. Se a cartela contiver uma linha, coluna ou diagonal preenchida com zeros, a função
deve retornar True. Caso contrário deve retornar False. Crie um programa que demonstre o
funcionamento da sua solução criando e exibindo várias cartelas de bingo e indicando se cada
uma é ou não é vencedora. Você deve mostrar pelo menos uma cartela com linha horizontal,
uma com linha v ertical, uma com diagonal e por fim uma com alguns zeros cruzados, mas
que não é vencedora. Você pode usar sua solução do problema anterior como ponto de
partida para este exercício. Dica: como a cartela não tem números negativos, encontrar uma
sequencia de 5 zeros é análogo a descobrir se a soma de uma sequencia de 5 números é
igual a zero. Talvez você ache mais fácil fazer desse jeito.'''

from random import sample, randint

def gera_cartela_bingo():
	return {
		"B": sorted(sample(range(1, 16), 5)),
		"I": sorted(sample(range(16, 31), 5)),
		"N": sorted(sample(range(31, 46), 5)),
		"G": sorted(sample(range(46, 61), 5)),
		"O": sorted(sample(range(61, 76), 5)),
	}

def mostra_cartela(cartela):
	print("-------------------------------------")
	print("| B\tI\tN\tG\tO   |")
	print("-------------------------------------")
	
	for i in range(5):
		print(f"| {cartela['B'][i]}\t{cartela['I'][i]}\t{cartela['N'][i]}\t{cartela['G'][i]}\t{str(cartela['O'][i]).ljust(3, ' ')} |")

	print("-------------------------------------")

def is_cartela_vencedora(cartela):
	# Vertical
	for key in cartela.keys():
		if sum(cartela[key]) == 0:
			print("Vencedora vertical")
			return True
		
	# Horizontal
	for i in range(5):
		total = 0
		for key in cartela.keys():
			total += cartela[key][i]

		if total == 0:
			print("Vencedora horizontal")
			return True

	# Diagonal principal
	if cartela['B'][4] + cartela['I'][3] + cartela['N'][2] + cartela['G'][1] + cartela['O'][0] == 0:
		print("Vencedora diagonal principal")
		return True
	
	# Diagonal secundária
	if cartela['B'][0] + cartela['I'][1] + cartela['N'][2] + cartela['G'][3] + cartela['O'][4] == 0:
		print("Vencedora diagonal secundária")
		return True
	
	# Nenhuma válida, não é vencedora
	return False

def main():
	cartela_horizontal = {
		"B": [1, 0, 3, 5, 9],
		"I": [17, 0, 19, 23, 27],
		"N": [32, 0, 35, 39, 42],
		"G": [49, 0, 52, 54, 57],
		"O": [65, 0, 68, 69, 72]
	}
	print("Cartela horizontal:")
	mostra_cartela(cartela_horizontal)
	print("Vencedora:", is_cartela_vencedora(cartela_horizontal))

	cartela_vertical = {
		"B": [2, 4, 5, 9, 14],
		"I": [18, 19, 21, 23, 29],
		"N": [33, 34, 37, 40, 43],
		"G": [0, 0, 0, 0, 0],
		"O": [62, 67, 69, 71, 74]
	}
	print("\nCartela vertical:")
	mostra_cartela(cartela_vertical)
	print("Vencedora:", is_cartela_vencedora(cartela_vertical))

	cartela_diagonal1 = {
		"B": [1, 3, 6, 8, 0],
		"I": [17, 21, 25, 0, 28],
		"N": [31, 37, 0, 41, 42],
		"G": [46, 0, 52, 57, 59],
		"O": [0, 64, 68, 72, 75]
	}
	print("\nCartela diagonal 1:")
	mostra_cartela(cartela_diagonal1)
	print("Vencedora:", is_cartela_vencedora(cartela_diagonal1))

	cartela_diagonal2 = {
		"B": [0, 3, 6, 8, 12],
		"I": [17, 0, 25, 27, 28],
		"N": [31, 37, 0, 41, 42],
		"G": [46, 78, 52, 0, 59],
		"O": [62, 64, 68, 72, 0]
	}
	print("\nCartela diagonal 2:")
	mostra_cartela(cartela_diagonal2)
	print("Vencedora:", is_cartela_vencedora(cartela_diagonal2))

	cartela_quase = {
		"B": [0, 3, 6, 0, 8],
		"I": [17, 0, 0, 25, 28],
		"N": [31, 0, 0, 41, 42],
		"G": [0, 46, 52, 57, 59],
		"O": [0, 64, 68, 72, 0]
	}
	print("\nCartela quase vencedora:")
	mostra_cartela(cartela_quase)
	print("Vencedora:", is_cartela_vencedora(cartela_quase))

if __name__ == "__main__":
	main()