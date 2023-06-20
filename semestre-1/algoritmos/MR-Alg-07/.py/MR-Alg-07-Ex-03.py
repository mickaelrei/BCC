'''Escreva uma função chamada buscaReversa, que encontra todas as chaves
de um dicionário que estão mapeadas para um determinado valor. A função deve receber
como parâmetros um dicionário e um valor para ser buscado no dicionário. A função deve
retornar uma lista (possivelmente vazia) com as chaves encontradas. Escreva uma função
main para demonstrar sua função. Note que a função deve funcionar independentemente de
ela retornar múltiplas chaves, uma única chave, ou nenhuma chave.'''

def buscaReversa(dic, valor):
	chaves = []

	for k, v in dic.items():
		if v == valor:
			chaves.append(k)

	return chaves

def main():
	d1 = {
		"idade": 18,
		"peso": 18,
		"valorA": 14,
		"valorB": 18,
		"valorC": -15,
	}

	print("d1 = ")
	print(d1)

	print("\nChaves com valor 18 em d1:")
	print(buscaReversa(d1, 18))

	print("\nChaves com valor 14 em d1:")
	print(buscaReversa(d1, 14))

	print("\nChaves com valor 25 em d1:")
	print(buscaReversa(d1, 25))

if __name__ == "__main__":
	main()