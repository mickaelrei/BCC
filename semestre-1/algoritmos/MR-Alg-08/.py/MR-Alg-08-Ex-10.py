'''A codificação run-length é uma técnica simples de compressão de
dados que pode ser eficaz quando valores repetidos ocorrem em posições adjacentes dentro
de uma lista. Compressão é obtida substituindo grupos de valores repetidos por uma cópia do
valor, seguido pelo número de vezes que o valor deve ser repetido. Por exemplo, a lista ["A",
"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "B", "B", "B", "B",
"A", "A", "A", "A", "A", "A", "B"] seria comprimida como ["A", 12, "B", 4, "A",
6, "B", 1]. A descompressão é realizada replicando cada valor da lista o número de vezes
indicado.
Escreva uma função recursiva que descompacte uma lista codificada run-lenght. Sua função
recursiva deve ter uma lista compactada em run-lenght como seu único parâmetro. Ela deve
retornar a lista descompactada como seu único resultado. Crie um programa principal que
exibe uma lista codificada em run-lenght e o resultado da decodificação.'''

def descompactarRunLength(lst):
	if len(lst) == 0: return []
	# Lista com número ímpar de valores é inválida
	if len(lst) % 2 == 1: raise ValueError("Invalid Run-Length compressed list")

	return [lst[0]] * lst[1] + descompactarRunLength(lst[2:])

def main():
	l = ["A", 3, "B", 4, "C", 6, "D", 1]
	print(descompactarRunLength(l))

if __name__ == "__main__":
	main()
