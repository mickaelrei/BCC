'''No exercício anterior, você escreveu um programa
que usava um laço de repetição para converter um número decimal para sua representação
binária. Neste exercício, você executará a mesma tarefa usando recursividade.
Escreva uma função recursiva que converta um número decimal não negativo em binário.
Trate 0 e 1 como casos básicos que retornam uma string contendo o dígito apropriado. Para
todos os outros inteiros positivos, n, você deve calcular o próximo dígito usando o operador de
resto e, em seguida, fazer uma chamada recursiva para calcular os dígitos de n // 2.
Finalmente, você deve concatenar o resultado da chamada recursiva (que será um string) e o
próximo dígito (que você precisará converter em uma string) e retornar essa string como o
resultado da função.
Escreva um programa principal que use sua função recursiva para converter um inteiro não
negativo inserido pelo usuário de decimal para binário. Seu programa deve exibir uma
mensagem de erro apropriada se o usuário inserir um valor negativo.'''

def decBinRecursivo(n):
	if n <= 1: return str(n)

	return decBinRecursivo(n // 2) + str(n % 2)

def main():
	while True:
		n = int(input("Digite um número inteiro positivo: "))
		if n < 0:
			print("Precisa ser positivo!")
			continue

		print(f"Binário: {decBinRecursivo(n)}")
		break

if __name__ == "__main__":
	main()
