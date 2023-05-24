from random import randint

def senha_aleatoria():
    senha = ""
    for i in range(randint(7, 10)):
        senha += chr(randint(33, 126))

    return senha

def main():
    print(f"Senha gerada: {senha_aleatoria()}")

if __name__ == "__main__":
    main()