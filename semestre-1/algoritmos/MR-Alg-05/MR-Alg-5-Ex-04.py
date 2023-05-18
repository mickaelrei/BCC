def mediana(a, b, c):
    lst = [a, b, c]
    lst.sort()

    return lst[len(lst)//2]

def main():
    a = float(input("Digite o valor de A: "))
    b = float(input("Digite o valor de B: "))
    c = float(input("Digite o valor de C: "))

    med = mediana(a, b, c)
    print(f"Mediana de ({a}, {b}, {c}) = {med}")

if __name__ == "__main__":
    main()