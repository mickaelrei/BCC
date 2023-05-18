from math import log10, floor

# A função ordinal() se baseia nos valores adicionados nesta lista, onde cada posição na lista equivale
# aos números ordinais da casa de unidade, dezena, centena, etc. Atualmente, só aceita até centena (1-999),
# mas pode ser facilmente expandida se inserir os próximos nomes (1000, 2000, 3000, ..., 9000)
ordinais = [
        [       # De 1 a 9
            "", # Ignora posição zero
            "primeiro",
            "segundo",
            "terceiro",
            "quarto",
            "quinto",
            "sexto",
            "sétimo",
            "oitavo",
            "nono",
        ],
        [       # De 10 a 90
            "", # Ignora posição zero
            "décimo",
            "vigésimo",
            "trigésimo",
            "quadrigésimo",
            "quinquagésimo",
            "sexagésimo",
            "septagésimo",
            "octagésimo",
            "nonagésimo",
        ],  
        [       # De 100 a 900
            "", # Ignora posição zero
            "centésimo",
            "ducentésimo",
            "tricentésimo",
            "quadringentésimo",
            "quingentésimo",
            "sexcentésimo",
            "septingentésimo",
            "octingentésimo",
            "noningentésimo"
        ]
    ]

def ordinal(n):
    # Quantidade de digitos no número
    digitos = floor(log10(n)) + 1

    # Verifica se está implementada a conversão de cardinal para decimal para o tanto
    # de dígitos do número dado (ou se é um número negativo)
    if len(ordinais) < digitos or n <= 0:
        return ""
    
    # Inicialize numero ordinal
    ord_nomes = []

    for i in range(1, digitos + 1):
        # Pega o dígito dessa casa
        digito = n // 10 ** (digitos - i) % 10

        # Se for zero, ignora
        if digito == 0: continue

        # Adiciona o nome em ordinal do dígito atual
        ord_nomes.append(ordinais[digitos - i][digito])

    # Separa os nomes com espaço
    return " ".join(ord_nomes)

def main():
    for i in range(1, 13):
        print(f"{i}° = '{ordinal(i)}'")

    final = 10**len(ordinais)
    if input(f"\nDeseja mostrar os ordinais de 13 a {final-1}? (S/N): ").lower() == "s":
        for i in range(13, final):
            print(f"{i}° = '{ordinal(i)}'")

if __name__ == "__main__":
    main()