'''Ao analisar os dados coletados como parte de um experimento
científico, pode ser desejável remover os valores mais extremos antes de realizar outros
cálculos. Escreva uma função que tenha uma lista de valores e um número inteiro não
negativo, n, como seus parâmetros. A função deve criar uma nova cópia da lista com os n
maiores elementos e os n menores elementos removidos. Em seguida, ele deve retornar a
nova cópia da lista como o único resultado da função. A ordem dos elementos na lista
retornada não precisa coincidir com a ordem dos elementos na lista original.
Escreva um programa principal que demonstre sua função. Sua função main deve ler uma lista
de números do usuário e remover os dois maiores e os dois menores valores dela. Exiba a
lista com os extremos removidos, seguido pela lista original. Seu programa deve gerar uma
mensagem de erro apropriada se o usuário inserir menos de 4 valores.'''

def removerExtremos(lst, n):
    new_lst = lst.copy()

    for i in range(n):
        new_lst.remove(max(new_lst))
        new_lst.remove(min(new_lst))

    return new_lst

def main():
    lst = []
    while True:
        n = int(input("Digite um número (zero para sair): "))
        if n == 0:
            break

        lst.append(n)

    if len(lst) < 4:
        print("Não há itens suficientes na lista: Insira ao menos 4.")
    else:
        new_lst = removerExtremos(lst, 2)

        print("\nNova lista, removidos os dois maiores e os dois menores:")
        for n in new_lst:
            print(n)

if __name__ == "__main__":
    main()
