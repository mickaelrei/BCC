'''A tokenização é o processo de conversão de uma string em uma
lista de substrings, conhecidas como tokens. Em muitas circunstâncias, uma lista de tokens é
muito mais fácil de trabalhar do que a string original porque a string original pode ter
espaçamento irregular. Em alguns casos, um trabalho substancial também é necessário para
determinar onde termina um token e onde começo o próximo.
Em uma expressão matemática, os tokens são itens como operadores, números e parênteses.
Alguns tokens, como *, /, ^, ( e ) são fáceis de identificar porque o token é um único caractere
e nunca faz parte de outro token. Os símbolos + e - são um pouco mais desafiadores de tratar
porque podem representar o operador de adição ou subtração ou podem ser parte de um
token de número.
Dica: Um sinal de + ou de - é um operador se o caractere (diferente de espaço em branco)
imediatamente anterior fizer parte de um número ou se o caractere (diferente de espaço em
branco) imediatamente antes for um parêntese fechado. Caso contrário, faz parte de um
número.

Escreva uma função que pegue uma string contendo uma expressão matemática como seu
único parâmetro e a divida em uma lista de tokens. Cada token deve ser um parêntese, um
operador ou um número com um sinal opcional de + ou - (para simplificar, trabalharemos
apenas com inteiros neste problema). Retorne a lista de tokens como o resultado da função.
Você pode presumir que a string passada para sua função sempre contém uma expressão
matemática válida consistindo de parênteses, operadores e inteiros. Entretanto, sua função
deve lidar com quantidades variáveis de espaços em branco entre esses elementos. Inclua um
programa principal que demonstra sua função de tokenização lendo uma expressão do
usuário e imprimindo a lista de tokens.'''

def tokenizar(expressao: str) -> list[str]:
	VALID_OPERATORS = "+-*/^"
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
	expressao = input("Digite uma expressão matemática válida: ")

	print("\nTokens: ")
	print(tokenizar(expressao))

if __name__ == "__main__":
	main()