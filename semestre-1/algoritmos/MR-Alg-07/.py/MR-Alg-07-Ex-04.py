'''O código morse é um esquema de codificação de letras e números utilizando
pontos e traços. Neste exercício você deve escrever um programa que usa um dicionário para
armazenar o mapeamento de letras e números para código Morse. Voce deve representar os
pontos com símbolo de ponto “.” e traços com sinal de subtração “-“. A tabela abaixo mostra o
mapeamento de letras e números para código Morse. Seu programa deve ler uma mensagem
do usuário e então deve traduzir cada letra e número para código Morse, deixando um espaço
em branco entra cada caractere traduzido. O programa deve ignorar qualquer caracter que
não seja letra ou número. Por exemplo, a mensagem Hello, World! Deve ser exibida da
seguinte forma: .... . .-.. .-.. --- .-- --- .-. .-.. -..'''

TO_MORSE = {
    'A': '.-',
	'B': '-...',
	'C': '-.-.',
	'D': '-..',
	'E': '.',
	'F': '..-.',
	'G': '--.',
	'H': '....',
	'I': '..',
	'J': '.---',
    'K': '-.-',
	'L': '.-..',
	'M': '--',
	'N': '-.',
	'O': '---',
	'P': '.--.',
	'Q': '--.-',
	'R': '.-.',
	'S': '...',
	'T': '-',
    'U': '..-',
	'V': '...-',
	'W': '.--',
	'X': '-..-',
	'Y': '-.--',
	'Z': '--..',
    '0': '-----',
	'1': '.----',
	'2': '..---',
	'3': '...--',
	'4': '....-',
	'5': '.....',
	'6': '-....',
	'7': '--...',
	'8': '---..',
	'9': '----.'
}

def text_to_morse(text: str):
	morse_text = []
	for char in text:
		if char.isalpha():
			morse_text.append(TO_MORSE[char.upper()])
		elif char.isdigit():
			morse_text.append(TO_MORSE[char])

	return " ".join(morse_text)

def main():
	text = input("Digite um texto: ")

	print("\nTexto em morse:")
	print(text_to_morse(text))

if __name__ == "__main__":
	main()