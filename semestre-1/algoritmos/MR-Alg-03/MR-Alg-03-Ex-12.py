def bissexto(ano):
    if ano % 400 == 0:
        return True
    elif ano % 100 == 0:
        return False
    elif ano % 4 == 0:
        return True
    
    return False
    
ano = int(input("Digite um ano: "))

print(f"O ano {ano} {'' if bissexto(ano) else 'não '}é bissexto")