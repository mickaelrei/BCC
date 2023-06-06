'''As expressões matemáticas são frequentemente escritas na forma de infixo,
onde os operadores aparecem entre os operandos sobre os quais atuam. Embora seja uma
forma comum, também é possível expressar expressões matemáticas na forma pós-fixada, em
que o operador aparece depois de ambos os operandos. Por exemplo, a expressão infixa
3 + 4 é escrita como 3 4 + na forma pós-fixada. Pode-se converter uma expressão infixada
em uma forma pós-fixada usando o seguinte algoritmo:

Use a solução do exercício anterior para tokenizar uma expressão matemática. Em seguida,
use o algoritmo acima para transformar a expressão da forma infixo para a forma pós-fixada.
Seu código que implementa o algoritmo acima deve residir em uma função que recebe uma
lista de tokens que representam uma expressão infixa como seu único parâmetro. Ele deve
retornar uma lista de tokens que representam a expressão pós-fixada equivalente como seu
único resultado. Inclua um programa principal que demonstra sua função infixo para pós-fixada
lendo uma expressão do usuário na forma infixo e exibindo-a na forma pós-fixada.
A finalidade da conversão da forma infixo para a forma pós-fixada ficará evidente quando você
fizer o próximo exercício. Os exercícios 9 da lista 5 e 14 da lista atual podem ser úteis para
concluir este problema.

Observação: os algoritmos implementados nos exercícios 16 e 17 não realizam nenhuma
verificação de erro. Como resultado, você pode travar seu programa ou receber resultados
incorretos se fornecer dados inválidos. Esses algoritmos podem ser estendidos para
detectar entrada inválida e responder a ela de maneira apropriada. Isto fica como um
exercício de estudo independente para o aluno interessado em aprimorar ainda mais suas
habilidades de programação.'''

VALID_OPERATORS = "+-*/^"

def precedencia(operador: str) -> int:
	if operador in "+-":
		return 1
	elif operador in "*/":
		return 2
	elif operador == "^":
		return 3
	
	return -1

def infix2postfix(tokens: list[str]) -> list[str]:
	operadores = []
	postfix = []

	for token in tokens:
		if token.isdigit():
			postfix.append(token)

		elif token in VALID_OPERATORS:
			while len(operadores) > 0 and operadores[-1] != "(" and precedencia(token) < precedencia(operadores[-1]):
				operador = operadores.pop()
				postfix.append(operador)

			operadores.append(token)

		elif token == "(":
			operadores.append(token)

		elif token == ")":
			while operadores[-1] != "(":
				operador = operadores.pop()
				postfix.append(operador)

			operadores.remove("(")

	while len(operadores) > 0:
		operador = operadores.pop()
		postfix.append(operador)

	return postfix


def tokenizar(expressao: str) -> list[str]:
	tokens = []

	last = None
	lastNumStartIdx = -1
	for i, char in enumerate(expressao):
		if char.isspace(): continue

		# Verifica se o último caractere era um dígito e o atual não é (ou seja, fim de número)
		if last and last.isdigit() and not char.isdigit():
			tokens.append(expressao[lastNumStartIdx:i].strip())
			lastNumStartIdx = -1

		# Verifica se é um operador
		if char in VALID_OPERATORS:
			tokens.append(char)

		# Verifica se é um parênteses
		elif char in "()":
			tokens.append(char)

		# Verifica se é um número
		elif char.isdigit() and lastNumStartIdx == -1:
			lastNumStartIdx = i

		last = char

	# Ao final, verifica se havia algum número
	if lastNumStartIdx != -1:
		tokens.append(expressao[lastNumStartIdx:])

	return tokens

def main():
	expressao = input("Digite uma expressão matemática válida na forma infixa: ")

	tokens = tokenizar(expressao)
	posfixa = infix2postfix(tokens)

	print("Pós fixa: ")
	print(" | ".join(posfixa))

if __name__ == "__main__":
	main()