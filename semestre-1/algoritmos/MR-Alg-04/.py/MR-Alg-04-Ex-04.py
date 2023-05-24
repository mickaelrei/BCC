from math import sqrt

coordenadas = []
perimetro = 0

while True:
    x = input("\nDigite a coordenada X do vértice (Enter para sair): ")
    if x == "":
        break

    x = float(x)
    y = float(input("Digite a coordenada y do vértice: "))
    coordenadas.append((x, y))

    if len(coordenadas) >= 2:
        c0 = coordenadas[len(coordenadas) - 2]
        c1 = coordenadas[len(coordenadas) - 1]

        perimetro += sqrt((c0[1] - c1[1])**2 + (c0[0] - c1[0])**2)

print(f"Perímetro = {perimetro}")