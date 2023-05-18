def correcao_maiusculas(string: str):
    proximo_maiusculo = True
    nova_string = ""

    for char in string:
        if char.isalpha() and proximo_maiusculo:
            nova_string += char.upper()
            proximo_maiusculo = False
        else:
            nova_string += char

        if char in (".", "!", "?"):
            proximo_maiusculo = True
     
    return nova_string

def main():
    s = input("Digite uma mensagem: ")

    print("\nSua mensagem, com letras maiúsculas corretas:")
    print(correcao_maiusculas(s))

if __name__ == "__main__":
    main()