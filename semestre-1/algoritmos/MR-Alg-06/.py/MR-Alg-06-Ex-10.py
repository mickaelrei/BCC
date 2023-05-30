'''Quando escrevemos uma lista em português, geralmente separamos
os itens por vírgula e colocamos a conjunção “e" entre os dois últimos itens, a não ser que a
lista só tenha um item. Considere as listas abaixo:

maçãs
maçãs e laranjas
maçãs, laranjas e bananas
maçãs, laranjas, bananas e limões

Escreva uma função que receba como parâmetro uma lista de strings e retorne uma única
string contendo todos os itens da lista formatados conforme mostrado acima. Apesar dos
exemplos acima terem no máximo 4 itens, sua função deve se comportar corretamente para
listas de qualquer tamanho. Escreva uma função main demonstrando o funcionamento de sua
função.'''

def formatarLista(lst: list):
	if len(lst) == 0:
		return ""
	elif len(lst) == 1:
		return f"{lst[0]}"
	elif len(lst) == 2:
		return f"{lst[0]} e {lst[1]}"
	else:
		return f"{', '.join(lst[:-1])} e {lst[-1]}"

def main():
	testes = ["maçãs", "laranjas", "bananas", "limões"]
	lst = []
	for item in testes:
		lst.append(item)
		print(formatarLista(lst))

if __name__ == "__main__":
	main()