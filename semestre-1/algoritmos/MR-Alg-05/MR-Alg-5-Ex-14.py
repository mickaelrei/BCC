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
    
def data_magica(dia, mes, ano):
    return dia * mes == ano % 100

def main():
    print("Datas mágicas do século XX: ")

    for ano in range(1901, 2001):
        for mes in range(1, 13):
            for dia in range(1, dias_mes(mes, ano)+1):
                if data_magica(dia, mes, ano):
                    str_dia = str(dia).rjust(2, '0')
                    str_mes = str(mes).rjust(2, '0')
                    
                    print(f"{str_dia}/{str_mes}/{ano}")

if __name__ == "__main__":
    main()