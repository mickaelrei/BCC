'''Faça uma função Python recursiva que recebe uma string e retorne um valor
lógico indicando se ela é ou não é um palíndromo. OBS: Um palíndromo é uma palavra ou
frase, que é igual quando lida da esquerda para a direita ou da direita para a esquerda
(Espaços em branco e sinais de pontuação devem ser descartados). Exemplo de palíndromo:
"saudavel leva duas”.'''

def isPalindromo(s):
	if len(s) <= 1: return True
	if len(s) == 2: return s[0] == s[1]

	return s[0] == s[-1] and isPalindromo(s[1:-1])

def main():
	palavras = [
		"osso",
		"arara",
		"onibus",
		"gabriel",
		"kayak",
		"ossos"
	]

	for palavra in palavras:
		print(f"A palavra \"{palavra}\" {'não ' if not isPalindromo(palavra) else ''}é palíndromo.")

if __name__ == "__main__":
	main()
