#include <stdio.h>

int main() {
    int numero;

    // Solicita ao usuário que insira um número positivo
    printf("Digite um número positivo: ");
    scanf("%d", &numero);

    // Verifica se o número é positivo
    if (numero <= 0) {
        printf("Por favor, insira um número positivo.\n");
    } else {
        printf("Os divisores do número %d são: ", numero);

        // Itera de 1 até o número (inclusive)
        for (int i = 1; i <= numero; i++) {
            // Verifica se i é um divisor de numero
            if (numero % i == 0) {
                printf("%d, ", i);
            }
        }

        printf("\n");
    }

    return 0;
}