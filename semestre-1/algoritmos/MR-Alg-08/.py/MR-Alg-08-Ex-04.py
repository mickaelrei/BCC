'''Escreva uma nova versão da sua função
recursiva do exercício 2 (Fibonacci) utilizando a técnica de memorização de resultado para
melhorar desempenho e consumo de memória.'''

fibTerms = [0, 1]

def fibonacci(n):
	memorized = n < len(fibTerms)
	if memorized: return fibTerms[n]

	result = fibonacci(n-1) + fibonacci(n-2)
	if not memorized:
		fibTerms.append(result)
	return result

def main():
	print("Sequência de Fibonacci (melhorado).")
	for i in range(500):
		print(f"{i+1}° termo: {fibonacci(i)}")

if __name__ == "__main__":
	main()
