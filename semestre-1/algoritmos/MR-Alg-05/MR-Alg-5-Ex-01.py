from math import sqrt

def hip(c0, c1):
    return sqrt(c0 * c0 + c1 * c1)

def main():
    print("Programa que calcula a hipotenusa de um triângulo retângulo, dado o comprimento dos dois catetos.")
    c0 = float(input("Comprimento do cateto 1: "))
    c1 = float(input("Comprimento do cateto 2: "))

    hipo = hip(c0, c1)
    print(f"Hipotenusa = {hipo}")

if __name__ == "__main__":
    main()