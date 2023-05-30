'''A biblioteca padrão de funções do Python possui um método
chamado count, que determina quantas vezes um determinado valor ocorre em uma lista.
Neste exercício você deve criar uma nova função chamada countRange que deve determinar
e retornar a quantidade de elementos em uma lista que são maiores ou iguais a um valor
mínimo e menores que um valor máximo. Sua função deve receber três parâmetros: a lista (de
números), o valor mínimo e o valor máximo. Ela deve retornar um valor inteiro maior ou igual a
zero. Escreva uma função main demonstrando o funcionamento de sua função.'''

def countRange(lst, _min, _max):
	c = 0
	for item in lst:
		if _min <= item < _max:
			c += 1

	return c

def main():
	nums = []
	while True:
		n = input("Digite um número (Enter para sair): ")
		if n == "":
			break

		nums.append(float(n))

	_min = float(input("Digite o valor mínimo: "))
	_max = float(input("Digite o valor máximo: "))

	print(f"Entre os números dados, {countRange(nums, _min, _max)} estao entre {_min} e {_max}")

if __name__ == "__main__":
	main()