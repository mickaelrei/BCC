from math import log10, floor

# Números na tabela
inicio = 1
final = 10

assert inicio <= final, "inicio precisa ser menor que final!"

# Calcula espaçamento entre colunas
produto_maximo = final * final
espacamento = floor(log10(produto_maximo)) + 1

# Linha inicial (das colunas)
print(" " * (espacamento + 1), end=" ")
for i in range(inicio, final + 1):
    n = str(i).rjust(espacamento + 1)
    
    # Se for o primeiro, adiciona um | para separar
    if i == inicio:
        n = "| " + n[1:]
    print(n, end="")
    
# Linha nova (separação entre primeira linha e linhas da tabuada)
print("\n" + "-" * (espacamento + 2) + "+" + "-" * ((espacamento + 1) * (final - inicio + 1)))

# Mostra os valores da tabuada
for linha in range(inicio, final + 1):
    # Linha
    print(str(linha).rjust(espacamento + 1), end=" ")
    
    # Produtos
    for coluna in range(inicio, final + 1):
        produto = str(linha * coluna).rjust(espacamento + 1)
        
        # Se for a primeira coluna, adiciona um | para separar
        if coluna == inicio:
            produto = "| " + produto[1:]        
            
        print(produto, end="")
        
    print()