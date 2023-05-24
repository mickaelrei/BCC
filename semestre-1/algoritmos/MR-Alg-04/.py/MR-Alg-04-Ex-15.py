decimal = int(input("Digite um número decimal: "))

binario = ""
q = decimal
while q != 0:
    r = q % 2
    binario = str(r) + binario
    
    q //= 2
    
print(f"Binário = {binario}")