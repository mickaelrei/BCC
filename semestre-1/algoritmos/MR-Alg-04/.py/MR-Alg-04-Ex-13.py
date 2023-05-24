from math import log10, floor

n = int(input("Digite um número inteiro (maior ou igual a 2): "))

assert n >= 2, "n precisa ser maior ou igual a 2!"

fatores = {}
fator = 2
espacamento = floor(log10(n))
while fator <= n:
    if n % fator == 0:
        # Printa
        n_str = str(n).ljust(espacamento + 1)
        print(f"\n{n_str} | {fator}", end="")
        n = floor(n / fator)
            
        # Adiciona na lista de fatores
        if str(fator) not in fatores.keys():
            fatores[str(fator)] = 1
        else:
            fatores[str(fator)] += 1
    else:
        fator += 1
 
# Mostra o número final (1)       
print("\n" + str(n))

# Função que converte str de número em str de expoente (32 => ³²)
def expoente_str(n):
    expoentes = "⁰¹²³⁴⁵⁶⁷⁸⁹"
    expoente_str = ""
    for i in str(n):
        expoente_str += expoentes[int(i)]
        
    return expoente_str

# Mostra os fatores
fatores_str = ""

for fator, num in fatores.items():
    # Se o expoente for 1, pode ser omitido
    exp = expoente_str(num) if num != 1 else ""
    fatores_str += fator + exp + " . "
    
# Remove os 3 últimos caracteres (" . ")
fatores_str = fatores_str[:-3]

print(f"\nForma fatorada:\n{fatores_str}\n")