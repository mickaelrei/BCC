def senha_valida(senha: str):
    # A senha deve ter pelo menos 8 caracteres
    if len(senha) < 8:
        return False
    
    contem_minuscula = False
    contem_maiuscula = False
    contem_digito = False
    for char in senha:
        if char.isalpha():
            if char.isupper():
                contem_maiuscula = True
            elif char.islower():
                contem_minuscula = True
        elif char.isdigit():
            contem_digito = True

    return contem_maiuscula and contem_minuscula and contem_digito

def main():
    print("Programa que verifica se uma senha é válida.")
    senha = input("Digite uma senha: ")

    print(f"A senha dada {'não ' if not senha_valida(senha) else ''}é válida.")

if __name__ == "__main__":
    main()