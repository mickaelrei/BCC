'''Duas palavras são anagramas se contiverem as mesmas letras, mas em ordens
diferentes. Por exemplo: “amor" e “roma" são anagramas porque cada uma delas contém um
"a", um "o", um "m" e um “r”. Crie uma função Python que recebe duas strings e retorna True
se elas forem anagramas, ou False caso contrário.'''

def is_anagrama(s1, s2):
	if len(s1) != len(s2): return False

	# Caracteres de s1
	chars1 = {}
	for char in s1:
		if not chars1.get(char):
			chars1[char] = 1
		else:
			chars1[char] += 1

	# Caracteres de s2
	chars2 = {}
	for char in s2:
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