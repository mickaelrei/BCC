aproximacoes = 15
meu_pi = 3

for i in range(aproximacoes-1):
    m = (i + 1) * 2
    termo = 4 / (m * (m + 1) * (m + 2))
    
    if i % 2 == 0:
        meu_pi += termo
    else:
        meu_pi -= termo
        
print(f"Pi após {aproximacoes} aproximações: {meu_pi}")