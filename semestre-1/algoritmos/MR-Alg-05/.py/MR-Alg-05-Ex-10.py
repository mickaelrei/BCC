def is_prime(n):
    if n <= 1:
        return False
    
    for i in range(2, n//2+1):
        if n % i == 0:
            return False
        
    return True

def main():
    n = int(input("Digite um número inteiro: "))

    print(f"O número {n} {'não ' if not is_prime(n) else ''}é primo.")

if __name__ == "__main__":
    main()