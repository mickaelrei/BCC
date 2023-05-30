'''Escreva um programa Python que leia números inteiros até
que uma linha em branco seja fornecida pelo usuário (se ele digitar somente enter). Depois
que todos os inteiros tiverem sido lidos, seu programa deve mostrar todos os números
negativos, seguidos por todos os zeros e depois todos os números positivos. Dentro de cada
grupo os números devem ser exibidos na ordem em que foram fornecidos pelo usuário. Por
exemplo, se o usuário forneceu os valores 3, -4, 1, 0, -1, 0 e -2, então seu programa deve
exibir os valores -4, -1, -2, 0, 0, 3 e 1, cada um em uma linha.'''

def main():
	nums = []
	while True:
		n = input("Digite um número (Enter para sair): ")
		if n == "":
			break

		nums.append(int(n))

	# Mostra os negativos
	print("\nNegativos: ")
	for n in nums:
		if n < 0:
			print(n)

	# Mostra os zeros
	print("\nZeros:")
	for i in range(nums.count(0)):
		print(0)

	# Mostra os positivos
	print("\nPositivos:")
	for n in nums:
		if n > 0:
			print(n)

if __name__ == "__main__":
	main()