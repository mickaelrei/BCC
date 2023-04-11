def calcularTroco(centavos: int, tiposMoedas: list[int]) -> tuple[list[int], int]:
    '''
    Retorna a quantidade de cada tipo de moedas, e o restante de centavos caso\
    não for possível chegar ao total de centavos com os tipos de moedas dados
    '''

    # Cria clone da lista para evitar mudança na lista original
    tiposMoedas = tiposMoedas[:]

    # Organiza os tipos de moedas em ordem decrescente para garantir a menor quantidade de moedas
    tiposMoedas.sort(reverse=True)

    # Guarda quantidade de moedas
    quantMoedas = {}

    # Calcula quantas moedas de cada tipo
    for valorMoeda in tiposMoedas:
        # Calcula quantas moedas deste tipo são necessárias
        quant = centavos // valorMoeda
        quantMoedas[str(valorMoeda)] = quant

        # Subtrai do restante
        centavos -= valorMoeda * quant
        
    return quantMoedas, centavos

############################################
#            Início da lógica
############################################

centavos = int(input("Digite a quantidade de centavos para troco: "))
while not (0 <= centavos <= 99):
    print("Digite uma quantidade entre 0 e 99!")
    centavos = int(input("Digite a quantidade de centavos para troco: "))

# Tipos de moedas
# (Exclua ou adicione valores de moedas para simular outros sistemas de moedas)
tiposMoedas = [
    50,
    25,
    10,
    5,
    1
]

# Pega a quantidade de cada tipo de moeda e o restante de centavos
quantMoedas, centavosRestantes = calcularTroco(centavos, tiposMoedas)

# Mostra os valores
for valorMoeda, quant in quantMoedas.items():
    print(f"Moedas de {valorMoeda} centavos: {quant}")

# Mostra o troco que não foi possível retornar (se existir)
if centavosRestantes > 0:
    print(f"\nQuantidade de centavos que não foi possível retornar em moedas: {centavosRestantes}")