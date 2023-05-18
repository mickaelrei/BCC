hex_letters = "ABCDEF"

def subscript_number(n: int):
    subs = "₀₁₂₃₄₅₆₇₈₉"

    result = ""
    for char in str(n):
        result += subs[int(char)]

    return result

def hex2int(h: str):
    h = str(h).upper()
    if len(h) > 1:
        return None

    if h.isalpha():
        idx = hex_letters.find(h)
        if idx == -1:
            return None
        
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
    
def main():
    sub10 = subscript_number(10)
    sub16 = subscript_number(16)

    print("Conversão de decimal para hexadecimal:")
    for i in range(16):
        print(f"{i}{sub10} = {int2hex(i)}{sub16}")

    print("\nConversão de hexadecimal para decimal: ")
    for i in range(10):
        print(f"{i}{sub16} = {hex2int(i)}{sub10}")

    for i in "ABCDEF":
        print(f"{i}{sub16} = {hex2int(i)}{sub10}")

if __name__ == "__main__":
    main()