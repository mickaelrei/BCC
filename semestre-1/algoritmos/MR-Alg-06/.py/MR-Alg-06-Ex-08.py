'''Neste exercício você deve criar uma função em Python que recebe um
texto em uma string e retorna uma lista somente com as palavras, sem espaços ou símbolos
de pontuação. Por exemplo, se a string for: “Beleza! Este é um ótimo exemplo, você
não acha?”, sua função deveria retornar a seguinte lista: [ “Beleza", “Este", “é",
“um", “ótimo", "exemplo", “você", “não", “acha”]. Escreva uma função main
que demonstre o funcionamento da sua solução.'''

def getPalavras(text: str):
	palavras = []
	lastLetterIdx = None

	for i in range(len(text)):
		char = text[i]
		if char.isalpha() and lastLetterIdx == None:
			lastLetterIdx = i
		elif not char.isalpha() and lastLetterIdx != None:
			palavras.append(text[lastLetterIdx:i])
			lastLetterIdx = None

	return palavras


def main():
	s = "Beleza! Este é um ótimo exemplo, você não acha?"

	print(f"Frase:\n{s}\n\nLista de palavras:\n{getPalavras(s)}")

if __name__ == "__main__":
	main()