alfabeto = "abcdefghijklmnopqrstuvwxyz"

letra = input("Digite uma letra: ").lower()
if len(letra) != 1:
    print("Digite exatamente 1 caracter!")
elif letra not in alfabeto:
    print("DIgite uma letra válida!")
elif letra in "aeiou":
    print(f"{letra} é uma vogal")
else:
    print(f"{letra} é uma consoante")