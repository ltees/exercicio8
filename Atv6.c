#include <stdio.h>

int main() {
    char continuar;
    
    do {
        int ano, mes, diasNoMes;

        printf("Digite o ano: ");
        scanf("%d", &ano);
        printf("Digite o mês (1-12): ");
        scanf("%d", &mes);

        int bissexto = ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0);

        switch (mes) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                diasNoMes = 31;
                break;
            case 4: case 6: case 9: case 11:
                diasNoMes = 30;
                break;
            case 2:
                if (bissexto) {
                    diasNoMes = 29;
                } else {
                    diasNoMes = 28;
                }
                break;
            default:
                printf("Mês inválido.\n");
                continue; // Retorna ao início do loop

        }

        printf("O mês %d/%d tem %d dias.\n", mes, ano, diasNoMes);

        printf("VOCÊ DESEJA OUTRAS ENTRADAS (S/?)? ");
        scanf(" %c", &continuar); // Espaço antes de %c para consumir o caractere de nova linha anterior

    } while (continuar == 'S' || continuar == 's');

    return 0;
}