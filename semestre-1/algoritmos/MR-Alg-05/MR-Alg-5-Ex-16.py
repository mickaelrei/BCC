from math import log10, floor

hex_letters = "ABCDEF"

def hex2int(h: str):
    h = str(h).upper()
    if len(h) > 1:
        return 0

    if h.isalpha():
        idx = hex_letters.find(h)
        if idx == -1:
            return 0
        
        return 10 + idx
    else:
        return int(h)
    
def int2hex(n: int):
    if not (0 <= n <= 15):
        return None
    
    if n < 10:
        return str(n)
    else:
        return hex_letters[n - 10]

def subscript_number(n: int):
    subs = "₀₁₂₃₄₅₆₇₈₉"

    result = ""
    for char in str(n):
        result += subs[int(char)]

    return result

def n2int(num: str, base: int):
    if not (2 <= base <= 16):
        return 0    
    
    # Dígitos totais e dígitos antes das casas decimais
    digitos = len(num) - num.count(".")
    digitos_int = len(num.split(".")[0])

    # Retira o ponto
    num = num.replace(".", "")

    num_int = 0
    for i in range(digitos):
        digito = num[i]
        expoente = digitos_int - 1 - i

        num_int += hex2int(digito) * base ** expoente

    return num_int

def int2n(n: float, base: int):
    if not (2 <= base <= 16):
        return 0
    
    num = ""
    q = int(n)
    while q != 0:
        r = int(q) % base
        num = int2hex(r) + num
        q //= base

    if num == "":
        return "0"

    return num

def main():
    n = input("Digite um número: ")
    base = int(input("Digite a base do seu número: "))

    int_num = n2int(n, base)
    n_num = int2n(int_num, base)

    base10 = subscript_number(10)
    base_user = subscript_number(base)

    print("\nConversão para decimal: ")
    print(f"{n}{base_user} = {int_num}{base10}")

    print(f"\nConversão de volta para base {base}:")
    print(f"{int_num}{base10} = {n_num}{base_user}")

if __name__ == "__main__":
    main()