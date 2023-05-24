def bissexto(ano):
    if ano % 400 == 0:
        return True
    elif ano % 100 == 0:
        return False
    elif ano % 4 == 0:
        return True
    
    return False

def dias_mes(mes, ano):
    if mes == 2:
        return 29 if bissexto(ano) else 28
    elif mes in (4, 6, 9, 11):
        return 30
    else:
        return 31
    
def main():
    mes = int(input("Digite o número de um mês (janeiro = 1, fevereiro = 2, ...): "))
    ano = int(input("Digite um ano: "))

    print(f"O mês {mes} no ano {ano} possui {dias_mes(mes, ano)} dias.")

if __name__ == "__main__":
    main()