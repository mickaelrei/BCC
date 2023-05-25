/*Escreva um programa Python que peça para o usuário uma letra do
alfabeto. Se o usuário entrar com as letras a, e, i, o ou u, o programa deve exibir uma
mensagem dizendo que a letra é uma vogal. Caso contrário, o programa deve exibir a
mensagem informando que a letra é uma consoante.*/

#include <stdio.h>
#include <ctype.h>

void main() {
    char letra;
    printf("Digite uma letra: ");
    scanf("%c", &letra);

    switch (tolower(letra)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Vogal");
            break;
        default:
            printf("Consoante");
            break;
    }
}
