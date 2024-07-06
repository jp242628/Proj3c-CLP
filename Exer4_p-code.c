#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTR_SIZE 100

int main() {
    FILE *entrada, *saida;
    char linha[MAX_INSTR_SIZE];
    int valor;

    entrada = fopen("Entrada.txt", "r");
    saida = fopen("Saida.txt", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir arquivo");
        return EXIT_FAILURE;
    }

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        if (strncmp(linha, "PUSH(", 5) == 0) {
            sscanf(linha, "PUSH(%d)", &valor);
            fprintf(saida, "LIT 0 %d\n", valor);
        } else if (strncmp(linha, "y=POP(); x=POP(); PUSH(x ", 23) == 0) {
            if (strstr(linha, "ADD")) {
                fprintf(saida, "OPR 0 2\n");
            } else if (strstr(linha, "SUB")) {
                fprintf(saida, "OPR 0 3\n");
            } else if (strstr(linha, "MUL")) {
                fprintf(saida, "OPR 0 4\n");
            } else if (strstr(linha, "DIV")) {
                fprintf(saida, "OPR 0 5\n");
            }
        }
    }

    fclose(entrada);
    fclose(saida);
    return EXIT_SUCCESS;
}
