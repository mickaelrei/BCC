'''Avaliar uma expressão pós-fixada é mais fácil do que
avaliar uma expressão infixa porque ela não contém nenhum colchete e não há regras de
precedência de operador a serem consideradas. Uma expressão pós-fixada pode ser avaliada
usando o seguinte algoritmo:

Escreva um programa que leia uma expressão matemática em forma de infixo do usuário, a
avalie e exiba seu valor. Usa suas soluções dos exercícios 15 e 16 junto com o algoritmo
mostrado acima para resolver este problema.'''

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
			while len(operadores) > 0 and operadores[-1] != "(" and precedencia(token) <= precedencia(operadores[-1]):
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

def applyOperator(left: int, right: int|None, operator: str) -> int|float:
	if right is None:
		if operator == "+":
			return left
		elif operator == "-":
			return -left
		else:
			raise ValueError(f"Invalid unary operator: \"{operator}\"")

	if operator == "+":
		return left + right
	elif operator == "-":
		return left - right
	elif operator == "*":
		return left * right
	elif operator == "/":
		return left / right
	elif operator == "^":
		return left ** right

	# Invalid
	raise ValueError(f"Invalid binary operator: \"{operator}\"")

def evaluatePostfix(tokens: list[str]) -> int|float:
	valores = []
	for token in tokens:
		if token.isdigit():
			valores.append(int(token))
		else:
			print("Operador")
			print(valores)
			if len(valores) >= 2:
				direita = valores.pop()
				esquerda = valores.pop()

				valor = applyOperator(esquerda, direita, token)
			else:
				esquerda = valores.pop()
				valor = applyOperator(esquerda, None, token)
			valores.append(valor)

	return valores[0]

def main():
	print("Calculadora. Digite sempre expressões válidas na forma infixa (Enter para sair)")
	while True:
		expressao = input("> ")
		if expressao == "":
			break

		tokens = tokenizar(expressao)
		posfixa = infix2postfix(tokens)

		# Pega resultado
		print("Tokens: ")
		print(tokens)
		print("Postfix:")
		print(posfixa)
		resultado = evaluatePostfix(posfixa)

		print(resultado)

if __name__ == "__main__":
	main()