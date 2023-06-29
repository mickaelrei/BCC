'''Escreva uma função que converte um número
decimal (base 10) em binário (base 2). A função deve receber como parâmetro o número
inteiro decimal (q) e, em seguida, deve realizar a conversão usando o algoritmo de divisão
mostrado abaixo. Quando o algoritmo for concluído, o resultado contém a representação
binária do número, que deve ser retornada pela função como uma string.'''

def decBinIterativo(q):
	if q < 0: return ""
	if q == 0: return "0"

	result = ""
	while q != 0:
		r = q % 2
		result = str(r) + result
		q //= 2

	return result

def main():
	for i in range(15):
		print(f"Decimal: {i}, binário: {decBinIterativo(i)}")

if __name__ == "__main__":
	main()
