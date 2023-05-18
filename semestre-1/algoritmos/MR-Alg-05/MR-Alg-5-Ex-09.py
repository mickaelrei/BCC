def isInteger(string: str):
    for i, char in enumerate(string):
        # Se for um caractere de espaço, ignorar
        if char.isspace(): continue

        # Se não for um dígito ou for um sinal fora da primeira posição, não é inteiro
        if not char.isdigit():
            if char not in "+-" or i > 0:
                return False
        
    return True

print(isInteger("-151023"))