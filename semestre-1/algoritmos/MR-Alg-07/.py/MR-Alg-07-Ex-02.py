'''Escreva uma função Python que recebe dois conjuntos de números
inteiros M e N e retorna uma lista com sua diferença simétrica em ordem ascendente. O termo
diferença simétrica denota os valores que existem nos conjuntos M ou N, mas não existem em
ambos os conjuntos simultaneamente. Por exemplo, para os conjuntos M = {2, 4, 5, 9} e N =
{2, 4, 11, 12}, a resposta deveria ser [5, 9, 11, 12].'''

def diferenca_simetrica(M, N):
	diferenca = []
	
	for value in M:
		if value not in diferenca and value not in N:
			diferenca.append(value)

	for value in N:
		if value not in diferenca and value not in M:
			diferenca.append(value)

	diferenca.sort()
	return diferenca

def main():
	M = {2, 4, 5, 9}
	N = {2, 4, 11, 12}

	print(diferenca_simetrica(M, N))

if __name__ == "__main__":
	main()