'''Escreva uma função que determina se uma lista de valores está ou
não em ordem de classificação (crescente ou decrescente). A função deve receber a lista
como parâmetro e retornar True se a lista já estiver classificada. Caso contrário, ele deve
retornar False. Escreva um programa principal que leia uma lista de números do usuário e use
sua função para relatar se a lista é classificada.

Observação: certifique-se de considerar estas questões ao concluir este exercício:
Uma lista vazia está em ordem? E uma lista contendo somente um elemento?'''

def isSorted(lst):
	if len(lst) == 0:
		return False
	elif len(lst) == 1:
		return True
	else:
		# Testar para ambos crescente e decrescente
		crescente = decrescente = True
		for i in range(len(lst) - 1):
			if lst[i] > lst[i+1]:
				crescente = False
				break

		for i in range(len(lst) -1):
			if lst[i] < lst[i+1]:
				decrescente = False
				break

		return crescente or decrescente

def main():
	nums = []
	while True:
		n = input("Digite um número (Enter para sair): ")
		if n == "":
			break

		nums.append(float(n))

	if isSorted(nums):
		print("A lista de números está classificada.")
	else:
		print("A lista de números não está classificada.")

if __name__ == "__main__":
	main()