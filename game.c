#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char mapa[N][M];
    int agua = 0, hostil = 0, deserto = 0, vegetacao = 0, solo = 0;
    int total = N * M;

    // Lê o mapa
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &mapa[i][j]); // O espaço antes de %c é para ignorar espaços em branco
            switch (mapa[i][j]) {
                case '~':
                    agua++;
                    break;
                case 'X':
                    hostil++;
                    break;
                case '^':
                    deserto++;
                    break;
                case '*':
                    vegetacao++;
                    break;
                case '.':
                    solo++;
                    break;
            }
        }
    }

    // Calcula as porcentagens
    float pAgua = (float)agua / total * 100;
    float pVegetacao = (float)vegetacao / total * 100;
    float pDeserto = (float)deserto / total * 100;

    // Classificação
    if (hostil > 0) {
        printf("Planeta Hostil\n");
    } else if (pAgua >= 85) {
        printf("Planeta Aquático\n");
    } else if (pDeserto >= 60) {
        printf("Planeta Desértico\n");
    } else if (pVegetacao >= 65) {
        printf("Planeta Selvagem\n");
    } else if (pAgua >= 50 && pVegetacao >= 20) {
        printf("Planeta Classe M\n");
    } else {
        printf("Planeta Inóspito\n");
    }

    return 0;
}
