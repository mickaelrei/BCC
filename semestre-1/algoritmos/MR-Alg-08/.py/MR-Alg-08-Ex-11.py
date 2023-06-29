'''Escreva uma função recursiva que implemente a técnica de
compressão run-lenght descrita no exercício anterior. Sua função deve receber uma lista ou
uma string como seu único parâmetro. Ela deve retornar a lista compactada em run-lenght
como seu único resultado. Inclua um programa principal que leia uma string do usuário, a
compacte e exiba o resultado codificado em run-lenght.'''

def compactarRunLength(lst):
	# Check list length
	if len(lst) == 0: return []
	if len(lst) == 1: return [lst[0], 1]

	# Starting count of new string
	if type(lst[0]) == str and type(lst[1]) == str:
		return compactarRunLength([lst[0]] + [1] + lst[1:])

	# Testing for continuing count
	if type(lst[0]) == str and type(lst[1]) == int:
		# End of list
		if len(lst) == 2:
			return [lst[0]] + [lst[1]]
		# Check if next string is the same
		elif lst[2] == lst[0]:
			return compactarRunLength([lst[0]] + [lst[1] + 1] + lst[3:])
		else:
			# Next string is different
			return [lst[0]] + [lst[1]] + compactarRunLength(lst[2:])

def main():
	l = [
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
      	"A", "B", "B", "B", "B", "A", "A", "A", "A", "A", "A", "B"
	]
	print(compactarRunLength(l))

if __name__ == "__main__":
	main()
