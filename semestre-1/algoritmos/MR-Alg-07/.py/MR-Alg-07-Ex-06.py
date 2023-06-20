'''A noção de anagramas pode ser estendida para múltiplas palavras.
Por exemplo: "William Shakespeare” e “I am a weakish speller” são anagramas se ignorarmos
se as letras são maiúsculas e também os espaços. Crie uma nova versão da sua função do
exercício anterior para verificar se duas frases são anagramas. Sua função deve
desconsiderar se as letras são maiúsculas ou minúsculas, ignorar espaços e sinais de
pontuação.'''

def is_anagrama(s1, s2):
	# Caracteres de s1
	chars1 = {}
	for char in s1:
		if not char.isalpha(): continue

		char = char.lower()
		if not chars1.get(char):
			chars1[char] = 1
		else:
			chars1[char] += 1

	# Caracteres de s2
	chars2 = {}
	for char in s2:
		if not char.isalpha(): continue

		char = char.lower()
		if not chars2.get(char):
			chars2[char] = 1
		else:
			chars2[char] += 1
	
	# Verifica se são iguais
	for char, count in chars1.items():
		if not (chars2.get(char) and chars2[char] == count):
			return False
		
	return True

def main():
	s1 = input("Texto 1: ")
	s2 = input("Texto 2: ")

	print(f"\"{s1}\" e \"{s2}\" {'' if is_anagrama(s1, s2) else 'não '}são anagramas.")

if __name__ == "__main__":
	main()