'''Escreva uma função chamada precedencia que retorna um
inteiro representando a precedência de um operador matemático. Uma string contendo o
operador será passada para a função como seu único parâmetro. Sua função deve retornar 1
para + e -, 2 para * e / e 3 para ^. Se a string passada para a função não for um desses
operadores, a função deve retornar -1. Inclua um programa principal que lê um operador do
usuário e exibe a precedência do operador ou uma mensagem de erro indicando que a
entrada não era um operador.

Observação: Neste exercício, junto com outros que aparecem posteriormente nesta lista,
usaremos ^ para representar a exponenciação. Usar ^ ao invés do operador ** do Python
tornará esses exercícios mais fáceis porque um operador sempre será um único caractere.'''

def precedencia(operador: str) -> int:
	if operador in "+-":
		return 1
	elif operador in "*/":
		return 2
	elif operador == "^":
		return 3
	
	return -1

def main():
	operador = input("Digite um operador matemático: ")
	prec = precedencia(operador)
	if prec != -1:
		print(f"Precedência: {prec}")
	else:
		print("Operador inválido.")

if __name__ == "__main__":
	main()