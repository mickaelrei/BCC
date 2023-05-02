binario = input("Digite um número binário: ")
if binario.count("0") + binario.count("1") == len(binario):
    decimal = 0
    for i, bit in enumerate(binario):
        expoente = len(binario) - i - 1
        decimal += int(bit) * 2 ** expoente
        
    print(f"Decimal = {decimal}")
else:
    print("Não é número binário!")