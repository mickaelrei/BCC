def custo_envio(itens):
    if itens <= 0:
        return 0
    elif itens == 1:
        return preco_primeiro
    else:
        return preco_primeiro + preco_resto * (itens - 1)
    
def main():
    global preco_primeiro, preco_resto

    preco_primeiro = 10.95
    preco_resto = 2.95

    itens = int(input("Digite a quantidade de itens: "))

    custo = custo_envio(itens)
    print(f"Custo do envio: R$ {custo:.2f}")

if __name__ == "__main__":
    main()