'''Escreva uma função Python para verificar se uma string possui
caracteres únicos. Por exemplo, a string “azul" não repete letras, mas a string
“ferramenta"possui letras repetidas. A função deve receber uma string e retornar True no
primeiro caso (letras únicas) ou False caso contrário (letras repetidas). Você deve usar
conjuntos para implementar a função.'''

def chars_unicos(s):
	chars = set()
	for char in s:
		if char not in chars:
			chars.add(char)
		else:
			return False
		
	return True

def main():
	text = input("Digite uma mensagem: ")
	if chars_unicos(text):
		print("O texto inserido contém apenas caracteres únicos.")
	else:
		print("O texto inserido não contém apenas caracteres únicos.")

if __name__ == "__main__":
	main()