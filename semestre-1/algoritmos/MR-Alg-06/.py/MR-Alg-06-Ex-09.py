'''Escreva um programa que leia números do usuário até que uma
linha em branco seja inserida. Seu programa deve exibir a média de todos os valores inseridos
pelo usuário. Em seguida, o programa deve exibir todos os valores abaixo da média, seguidos
por todos os valores médios (se houver), seguidos por todos os valores acima da média. Uma
mensagem apropriada deve ser exibida antes de cada lista de valores.'''

def main():
	nums = []
	while True:
		n = input("Digite um número (Enter para sair): ")
		if n == "":
			break

		nums.append(float(n))

	# Mostra média
	media = sum(nums) / len(nums)
	print(f"\nMédia dos números: {media}")

	# Mostra valores abaixo, igual e acima da média
	print("\nValores abaixo da média:")
	for n in nums:
		if n < media:
			print(n)

	medios = nums.count(media)
	if medios > 0:
		print("\nValores médios:")
		for i in range(medios):
			print(media)

	print("\nValores acima da média:")
	for n in nums:
		if n > media:
			print(n)

if __name__ == "__main__":
	main()