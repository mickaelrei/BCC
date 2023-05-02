'''Inicialize result como uma string vazia
Seja q o número decimal a ser convertido
Repita
r recebe o resto da divisão de q por 2
converta r para uma string e adicione no início de result
faça a divisão inteira de q por 2 (descartando o resto) e guarde o resultado em q
Até que q seja igual a zero'''

decimal = int(input("Digite um número decimal: "))

binario = ""
q = decimal
while q != 0:
    r = q % 2
    binario = str(r) + binario
    
    q //= 2
    
print(f"Binário = {binario}")