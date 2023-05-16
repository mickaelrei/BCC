palavra = input("Digite uma palavra: ")

# Verifica se é palavra
if palavra.isalpha():
    palindromo = True
    for i in range(len(palavra) // 2):
        ch0 = palavra[i].lower()
        ch1 = palavra[-i - 1].lower()
        
        if ch0 != ch1:
            palindromo = False
            break
       
    print(f"\nA palavra {palavra} {'' if palindromo else 'não '}é palíndromo.")
else:
    print("\nNão é palavra.")