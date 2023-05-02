from random import randrange

simulacoes = 10
consecutivos_necessario = 3
total = 0
for i in range(simulacoes):
    ultimo = None
    consecutivos = 0
    
    sorteios = 0
    while consecutivos < consecutivos_necessario - 1:
        sorteios += 1
        lado = randrange(2)
        if lado == 0:
            print("A", end=" ")
        else:
            print("O", end=" ")
            
        if lado == ultimo:
            consecutivos += 1
        else:
            consecutivos = 0
            
        ultimo = lado
        
    print(f"({sorteios} sorteios)")
    total += sorteios
    
media = total / simulacoes

print(f"\nEm {simulacoes} simulações, na média, foram necessários {media} sorteios.")   