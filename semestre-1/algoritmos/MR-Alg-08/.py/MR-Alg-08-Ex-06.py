'''Euclides foi um matemático grego que viveu há
aproximadamente 2.300 anos. Seu algoritmo para calcular o MDC - máximo divisor comum de
dois inteiros positivos, a e b, é eficiente e recursivo. Está descrito abaixo:

MDC(a, b)
	if b == 0 then
		return a
	else
		c = a % b
		return MDC(b,c)
end

Escreva um programa que implemente o algoritmo recursivo de Euclides e o use para
determinar o máximo divisor comum de dois inteiros inseridos pelo usuário.'''

def MDC(a, b):
	if b == 0:
		return a
	else:
		return MDC(b, a % b)

def main():
	n1 = int(input("Digite um número inteiro: "))
	n2 = int(input("Digite um número inteiro: "))

	print(f"O Máximo Divisor Comum (MDC) de {n1} e {n2} é {MDC(n1, n2)}")

if __name__ == "__main__":
	main()
