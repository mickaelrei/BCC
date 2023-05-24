while True:
    bit_grupo = input("Digite o grupo de 8 bits: ")
    if bit_grupo == "":
        break
    
    # Verifica se é válido
    if len(bit_grupo) != 8 or (bit_grupo.count("0") + bit_grupo.count("1") != 8):
        print("Grupo inválido!")
        continue
    
    # Calcula bit de paridade
    bit_paridade = 0
    if bit_grupo.count("1") % 2 != 0:
        # Número ímpar de 1s, bit de paridade é 1
        bit_paridade = 1
        
    print(f"O bit de paridade do grupo {bit_grupo} é {bit_paridade}")