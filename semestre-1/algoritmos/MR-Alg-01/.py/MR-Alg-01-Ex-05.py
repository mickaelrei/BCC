tipo1 = int(input("Vasilhames de 1 litro ou menos: "))
tipo2 = int(input("Vasilhames de mais de 1 litro: "))

credito = tipo1 * .10 + tipo2 * .25
print(f"Crédito referente ao retorno dos vasilhames: R$ {credito:.2f}")