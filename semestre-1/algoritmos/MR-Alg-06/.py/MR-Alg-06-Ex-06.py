'''Um divisor de um numero inteiro n é um número inteiro positivo menor
que n, tal que divida n em partes inteiras (divisão exata, sem resto). Escreva uma função
Python que calcula todos os divisores de um número inteiro positivo. A função deve retornar
uma lista contendo todos os divisores. Escreva uma função main para demonstrar o
funcionamento da sua solução, a função main deve ler um número do usuário e imprimir todos
os seus divisores.'''

def divisores(n):
	lst = [1]
	for i in range(2, n // 2 + 1):
		if n % i == 0:
			lst.append(i)

	return lst

def main():
	n = int(input("Digite um número inteiro: "))

	divs = divisores(n)
	print(f"\nDivisores de {n}:")
	for div in divs:
		print(div)

if __name__ == "__main__":
	main()