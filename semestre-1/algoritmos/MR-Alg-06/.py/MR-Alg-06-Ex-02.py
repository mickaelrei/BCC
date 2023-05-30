'''Escreva um programa Python que leia números inteiros (do usuário) e
os armazena em uma lista. Seu programa deve continuar lendo inteiros até que o usuário
entre com o valor 0 (zero). Então, o programa deve exibir em ordem decrescente todos os
números digitados pelo usuário sem incluir o valor 0, com um valor em cada linha impressa.'''

def bubbleSort(lst, reverse=False):
    for i in range(len(lst) - 1):
        for j in range(len(lst) - i - 1):
            if reverse:
                if lst[j] < lst[j+1]:
                    lst[j], lst[j+1] = lst[j+1], lst[j]
            else:
                if lst[j] > lst[j+1]:
                    lst[j], lst[j+1] = lst[j+1], lst[j]

def main():
    lst = []
    while True:
        n = int(input("Digite um número (zero para sair): "))
        if n == 0:
            break

        lst.append(n)

    if len(lst) == 0:
        print("Não há itens na lista.")
    else:
        bubbleSort(lst, reverse=True)

        print("\nNúmeros em ordem decrescente:")
        for n in lst:
            print(n)

if __name__ == "__main__":
    main()