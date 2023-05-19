#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <string.h>

char* ordinal(int n) {
    const char* ordinais[][10] = {
        {
            "",
            "primeiro",
            "segundo",
            "terceiro",
            "quarto",
            "quinto",
            "sexto",
            "setimo",
            "oitavo",
            "nono",
        },
        {
            "",
            "decimo",
            "vigesimo",
            "trigesimo",
            "quadrigesimo",
            "quinquagesimo",
            "sexagesimo",
            "septagesimo",
            "octagesimo",
            "nonagesimo",
        },
        {
            "",
            "centesimo",
            "ducentesimo",
            "tricentesimo",
            "quadringentesimo",
            "quingentesimo",
            "sexcentesimo",
            "septingentesimo",
            "octingentesimo",
            "noningentesimo"
        }
    };
    size_t size = sizeof(ordinais) / sizeof(ordinais[0]);
    int digitos = floor(log10((double) n)) + 1;

    if (digitos > size || n < 0) {
        return "Not implemented";
    }
    
    char* str = malloc(sizeof(char) * 41);
    str[0] = '\0';

    for (int i = 1; i <= digitos; i++) {
        int digito = (int)floor(n / pow(10, digitos -i)) % 10;

        if (digito == 0) continue;

        if (i != 1) {
            strcat(str, " ");
            strcat(str, ordinais[digitos - i][digito]);
        } else {
            strcat(str, ordinais[digitos - i][digito]);
        }
    }

    return str;
}

void main() {
    for (int i = 1; i <= 12; i++) {
        const char* ord = ordinal(i);
        printf("%d = %s\n", i, ord);
    }

    char ans[2];
    printf("Show ordinals from 13 to 999 ? (Y/N): ");
    scanf("%c", &ans);

    if (strcmp(ans, "y") == 0 || strcmp(ans, "Y") == 0) {
        for (int i = 13; i <= 999; i++) {
            const char* ord = ordinal(i);
            printf("%d = %s\n", i, ord);
        }
    }
}