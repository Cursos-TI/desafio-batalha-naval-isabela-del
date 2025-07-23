#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todo o tabuleiro com água (valor 0)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Declaração dos vetores que representam os navios (valores são apenas indicativos)
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais do navio horizontal (linha fixa, colunas consecutivas)
    int linhaH = 2;
    int colunaH = 4;

    // Coordenadas iniciais do navio vertical (coluna fixa, linhas consecutivas)
    int linhaV = 5;
    int colunaV = 6;

    // Validação: garantir que os navios estão dentro dos limites
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        
        // Verificar sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] == NAVIO || tabuleiro[linhaV + i][colunaV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posicionar navio horizontal
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
            }

            // Posicionar navio vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
            }

            // Exibir tabuleiro
            printf("Tabuleiro de Batalha Naval:\n");
            for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
                for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
                    printf("%d ", tabuleiro[linha][coluna]);
                }
                printf("\n");
            }
        } else {
            printf("Erro: os navios se sobrepõem!\n");
        }
    } else {
        printf("Erro: coordenadas fora dos limites do tabuleiro.\n");
    }

    return 0;
}
