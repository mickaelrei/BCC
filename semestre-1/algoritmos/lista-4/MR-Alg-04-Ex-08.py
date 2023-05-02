mensagem = input("Digite uma mensagem: ")
offset = int(input("Digite o deslocamento: "))

alfabeto = "abcdefghijklmnopqrstuvwxyz"

nova_mensagem = ""
for char in mensagem:
    idx = alfabeto.find(char.lower())
    if idx == -1:
        # Não é letra, apenas adiciona na nova mensagem 
        nova_mensagem += char
        continue
    
    novo_idx = (idx + offset) % len(alfabeto)
    novo_char = alfabeto[novo_idx]
    nova_mensagem += novo_char.upper() if char.isupper() else novo_char
    
print(f"Texto criptografado:\n{nova_mensagem}")