poligonos = {
    "3": "triângulo",
    "4": "quadrado",
    "5": "pentágono",
    "6": "hexágono",
    "7": "heptágono",
    "8": "octógono",
    "9": "eneágono",
    "10": "decágono"
}

lados = int(input("Digite o número de lados do polígono regular (entre 3 e 10): "))

if not (3 <= lados <= 10):
    print("Digite um número entre 3 e 10!")
else:
    print(f"Um polígono regular de {lados} lados se chama {poligonos[str(lados)]}")