def triangulo_valido(a, b, c):
    return a < b + c and b < a + c and c < a + b

def main():
    print("Programa que verifica se é possível construir um triângulo, dado o comprimento de 3 lados.")

    a = float(input("Digite o comprimento do lado 1: "))
    b = float(input("Digite o comprimento do lado 2: "))
    c = float(input("Digite o comprimento do lado 3: "))

    valido = triangulo_valido(a, b, c)
    print(f"Os 3 lados informados {'não ' if not valido else ''}formam um triângulo.")

if __name__ == "__main__":
    main()