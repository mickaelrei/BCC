'''Neste exercício você vai simular o jogo de Bingo para apenas uma cartela.
Começa gerando uma lista de todas as chamadas válidas de bingo (B1 até O75). Depois que
a lista estiver pronta, você pode embaralhar seus elementos chamando a função shuffle do
módulo random do Python. Então seu programa deve ir utilizando os valores da lista para
anunciar os números sorteados e zerar os números correspondentes na cartela até que ela
contenha uma linha, coluna ou diagonal zerada. No seu programa principal, faça uma
simulação de 1.000 partidas (sempre com uma nova cartela) e mostre o número mínimo, o
máximo e a média de chamadas até que se tenha uma cartela vencedora. Utilize seu código
dos dois exercícios anteriores e não se esqueça de criar novas funções sempre que você
identificar algum procedimento que pode ser melhor organizado dentro de uma função.'''

from random import sample, shuffle

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
		print("| ", end="")
		print(cartela['B'][i] or '\033[91mX\033[0m', end="\t")
		print(cartela['I'][i] or '\033[91mX\033[0m', end="\t")
		print(cartela['N'][i] or '\033[91mX\033[0m', end="\t")
		print(cartela['G'][i] or '\033[91mX\033[0m', end="\t")
		O = cartela['O'][i]
		if O == 0:
			print('\033[91mX\033[0m  ', end='')
		else:
			print(str(O).ljust(3, ' '), end='')
		print(" |")

	print("-------------------------------------")

def is_cartela_vencedora(cartela):
	# Vertical
	for key in cartela.keys():
		if sum(cartela[key]) == 0:
			return True
		
	# Horizontal
	for i in range(5):
		total = 0
		for key in cartela.keys():
			total += cartela[key][i]

		if total == 0:
			return True

	# Diagonal principal
	if cartela['B'][4] + cartela['I'][3] + cartela['N'][2] + cartela['G'][1] + cartela['O'][0] == 0:
		return True
	
	# Diagonal secundária
	if cartela['B'][0] + cartela['I'][1] + cartela['N'][2] + cartela['G'][3] + cartela['O'][4] == 0:
		return True
	
	# Nenhuma válida, não é vencedora
	return False

def sorteia(jogadas):
	return jogadas.pop()

def marca_cartela(cartela, n):
	for key in cartela.keys():
		for i in range(5):
			if cartela[key][i] == n:
				cartela[key][i] = 0

def lista_jogadas():
	jogadas = list(range(1, 76))
	shuffle(jogadas)
	return jogadas

def simula_bingo():
	jogadas = lista_jogadas()
	cartela = gera_cartela_bingo()
	n = 0
	while not is_cartela_vencedora(cartela) and len(jogadas) > 0:
		n += 1
		marca_cartela(cartela, sorteia(jogadas))

	return n

def main():
	_min = 100
	_max = -1
	total = 0
	simulacoes = 1000

	for i in range(simulacoes):
		num_sorteios = simula_bingo()
		if num_sorteios < _min:
			_min = num_sorteios
		if num_sorteios > _max:
			_max = num_sorteios

		total += num_sorteios
	media = total / simulacoes

	print(f"\nApós {simulacoes} simulações:")
	print(f"Minimo: {_min}")
	print(f"Máximo: {_max}")
	print(f"Média: {media}")

	if input("\nQuer jogar bingo? (y/n): ").lower() == "y":
		jogo_bingo()

def jogo_bingo():
	cartela = gera_cartela_bingo()
	jogadas = lista_jogadas()
	mostra_cartela(cartela)

	n = 0
	while not is_cartela_vencedora(cartela):
		n += 1
		input(">")
		s = sorteia(jogadas)
		print(f"Número sorteado: {s}\n")
		marca_cartela(cartela, s)
		mostra_cartela(cartela)

	print("Vencedor! Levou", n, "jogadas")

if __name__ == "__main__":
	main()