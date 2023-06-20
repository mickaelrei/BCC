'''Uma cartela de bingo é formada por 5 linhas e 5 colunas. As colunas são
rotuladas com as letras B, I, N, G e O. Existem 15 números diferentes que podem aparecer
abaixo de cada letra. Abaixo do B podem aparecer os números de 1 a 15; abaixo do I os
números de 16 a 30, abaixo do N os números de 31 a 45 e assim por diante. Escreva uma
função que cria uma cartela de bingo e a armazena em um dicionário. As chaves do dicionário
são as letras B, I, N, G e O. Os valores devem ser listas de 5 números cada, que aparecem
abaixo de cada letra na cartela. A função deve retornar o dicionário. Escreva uma segunda
função que recebe o dicionário e exibe a cartela de bingo com as colunas rotuladas
apropriadamente. Escreva um programa main que gere e exiba uma cartela de bingo usando
suas funções.'''

from random import sample

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

def main():
	cartela = gera_cartela_bingo()

	print("Cartela:\n")
	mostra_cartela(cartela)

if __name__ == "__main__":
	main()