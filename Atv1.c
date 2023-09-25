#include <stdio.h>

int main() {
    int capacidade = 100;
    int quantidade_otimo = 0;
    int quantidade_bom = 0;
    int quantidade_regular = 0;
    int quantidade_ruim = 0;
    int quantidade_pessimo = 0;
    int idade_ruim_total = 0;
    int maior_idade_pessimo = 0;
    int maior_idade_otimo = 0;
    int maior_idade_ruim = 0;

    for (int i = 0; i < capacidade; i++) {
        char nota;
        int idade;

        printf("Informe a nota (A/B/C/D/E) do espectador %d: ", i + 1);
        scanf(" %c", &nota);

        printf("Informe a idade do espectador %d: ", i + 1);
        scanf("%d", &idade);

        if (nota == 'A') {
            quantidade_otimo++;
            if (idade > maior_idade_otimo) {
                maior_idade_otimo = idade;
            }
        } else if (nota == 'B') {
            quantidade_bom++;
        } else if (nota == 'C') {
            quantidade_regular++;
        } else if (nota == 'D') {
            quantidade_ruim++;
            idade_ruim_total += idade;
            if (idade > maior_idade_ruim) {
                maior_idade_ruim = idade;
            }
        } else if (nota == 'E') {
            quantidade_pessimo++;
            if (idade > maior_idade_pessimo) {
                maior_idade_pessimo = idade;
            }
        }
    }

    printf("Quantidade de respostas Ótimo: %d\n", quantidade_otimo);

    if (quantidade_bom > 0 && quantidade_regular > 0) {
        float diferenca_percentual = ((float)quantidade_bom - quantidade_regular) / capacidade * 100;
        printf("Diferença percentual entre respostas Bom e Regular: %.2f%%\n", diferenca_percentual);
    } else {
        printf("Não houve respostas Bom ou Regular suficientes para calcular a diferença percentual.\n");
    }

    if (quantidade_ruim > 0) {
        float media_idade_ruim = (float)idade_ruim_total / quantidade_ruim;
        printf("Média de idade das pessoas que responderam Ruim: %.2f\n", media_idade_ruim);
    } else {
        printf("Não houve respostas Ruim para calcular a média de idade.\n");
    }

    if (quantidade_pessimo > 0) {
        float percentagem_pessimo = (float)quantidade_pessimo / capacidade * 100;
        printf("Percentagem de respostas Péssimo: %.2f%%\n", percentagem_pessimo);
        printf("Maior idade que utilizou a opção Péssimo: %d\n", maior_idade_pessimo);
    } else {
        printf("Não houve respostas Péssimo para calcular a percentagem ou a maior idade.\n");
    }

    int diferenca_idade_maxima = maior_idade_otimo - maior_idade_ruim;
    printf("Diferença de idade entre a maior idade que respondeu Ótimo e a maior idade que respondeu Ruim: %d\n", diferenca_idade_maxima);

    return 0;
}