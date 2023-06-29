'''A série de Fibonacci é uma sequencia de Fn números inteiros no
qual um termo é definido pela soma dos dois termos anteriores. Os primeiros termos Fi da
sequencia são 0, 1, 1, 2, 3, 5, 8, 13, etc. Portanto, o enésimo termo da sequencia é definido
por Fn = F(n-1) + F(n-2), sendo F0 = 0 e F1 = 1. Escreva uma função Python recursiva que
recebe como parâmetro um valor inteiro n, e retorna o enésimo termo da sequencia de
Fibonacci.'''

def fibonacci(n):
	if n <= 0: return 0
	if n == 1: return 1

	return fibonacci(n-1) + fibonacci(n-2)

def main():
	print("Sequência Fibonacci.")
	for i in range(15):
		print(f"{i + 1}° termo:", fibonacci(i))

if __name__ == "__main__":
	main()
