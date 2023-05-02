frase = input("Digite uma frase: ")

# Remove caracteres irrelevantes
caracteres_ignorar = " \t.-[](){}"
nova_frase = frase
for char in caracteres_ignorar:
    nova_frase = nova_frase.replace(char, "")
    
# Verifica se é palíndromo
palindromo = True
for i in range(len(nova_frase) // 2):
    ch0 = nova_frase[i].lower()
    ch1 = nova_frase[-i - 1].lower()
        
    if ch0 != ch1:
        palindromo = False
        break
    
print(f"\nA frase \"{frase}\" {'' if palindromo else 'não '}é palíndromo.")