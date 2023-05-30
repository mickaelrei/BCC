'''Um número inteiro positivo n é chamado de número perfeito se a soma
de todos os divisores de n é igual a n. Por exemplo, 28 é um número perfeito porque seus
divisores são 1, 2, 4, 7 e 14; e 1+2+4+7+14=28. Escreva uma função para verificar se um
número é perfeito. A função deve receber somente um número inteiro positivo e retornar True
se ele for perfeito ou False caso contrário. Escreva uma função main para identificar e imprimir
todos os números perfeitos de 1 a 10.000. Obs.: você pode usar o código do exercício anterior
para lhe ajudar nesta tarefa.'''

def divisores(n):
	lst = [1]
	for i in range(2, n // 2 + 1):
		if n % i == 0:
			lst.append(i)

	return lst

def isPerfect(n):
	return sum(divisores(n)) == n

def main():
	for i in range(1, 10001):
		if isPerfect(i):
			print(f"{i} é um número perfeito.")

if __name__ == "__main__":
	main()