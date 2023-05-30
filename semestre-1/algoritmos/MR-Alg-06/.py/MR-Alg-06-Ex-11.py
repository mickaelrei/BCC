'''Para ganhar o prêmio da mega-sena, é necessário acertar todos os 6 números
em seu bilhete com os 6 números entre 1 e 60 sorteados pelo organizador da loteria. Escreva
um programa que gere uma seleção aleatória de 6 números para um bilhete de mega-sena.
Certifique-se de que não haja números repetidos entre os sorteados. Exiba os números em
ordem crescente.'''

from random import randint

def bubbleSort(lst):
    for i in range(len(lst) - 1):
        for j in range(len(lst) - i - 1):
            if lst[j] > lst[j+1]:
                lst[j], lst[j+1] = lst[j+1], lst[j]

def sequenciaMegasena():
	lst = []
	while len(lst) < 6:
		rand = randint(1, 60)
		if lst.count(rand) > 0:
			continue

		lst.append(rand)

	bubbleSort(lst)
	return lst


def main():
	print("Bilhete aleatório de mega-sena:")
	print(sequenciaMegasena())

if __name__ == "__main__":
	main()