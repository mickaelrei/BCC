from math import floor, ceil

def center_string(string: str, width: int, fill_char: str=" "):
    chars = (width - len(string)) / 2
    len_left = ceil(chars)
    len_right = floor(chars)

    return fill_char * len_left + string + fill_char * len_right

def main():
    string = "teste"

    centralizado = center_string(string, 15)

    print(f"Realizando {centralizado} básico")

if __name__ == "__main__":
    main()