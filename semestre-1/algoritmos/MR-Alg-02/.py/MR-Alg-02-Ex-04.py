n1 = int(input("1° número: "))
n2 = int(input("2° número: "))
n3 = int(input("3° número: "))

lst = [n1, n2, n3]

menor = min(lst)
maior = max(lst)
medio = sum(lst) - menor - maior

print(f"Ordem crescente: {menor}, {medio}, {maior}")