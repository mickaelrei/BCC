def custo_taxi(distancia):
    return preco_inicial + preco_distancia * distancia / 140

def main():
    global preco_inicial, preco_distancia

    preco_inicial = 4
    preco_distancia = .25

    print("Programa que calcula o custo de um táxi, dada a distância percorrida.")
    distancia = float(input("Distância percorrida: "))

    custo = custo_taxi(distancia)
    print(f"Custo do táxi: R$ {custo:.2f}")

if __name__ == "__main__":
    main()