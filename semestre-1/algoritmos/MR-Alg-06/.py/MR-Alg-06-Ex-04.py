'''Crie um programa Python que leia palavras do teclado até que o
usuário forneça uma palavra vazia (somente a tecla enter). Depois disso, seu programa deve
mostrar somente uma vez cada palavra digitada pelo usuário. Ou seja, se o usuário forneceu
mais de uma vez a mesma palavra, ela só poderá ser exibida uma vez. As palavras devem ser
exibidas na mesma ordem em que foram digitadas. Por exemplo, se o usuário digitar:

Primeira
Segunda
Primeira
Terceira
Segunda

Então seu programa deve exibir:

Primeira
Segunda
Terceira'''

def removerRepeticoes(lst):
    new_lst = []
    for item in lst:
        if new_lst.count(item) == 0:
            new_lst.append(item)

    return new_lst

def main():
    palavras = []
    while True:
        palavra = input("Digite uma palavra (Enter para sair): ")
        if palavra == "":
            break

        palavras.append(palavra)

    new_palavras = removerRepeticoes(palavras)

    print("\nNova lista de palavras, sem repetição:")
    for palavra in new_palavras:
        print(palavra)

if __name__ == "__main__":
    main()
    