#include <stdio.h>

typedef struct {
    char estado;                  // Letra do estado de 'A' a 'H'
    char codigoCarta[5];          // Código da carta no formato "A01", "B03", etc.
    char nomeCidade[50];         // Nome da cidade
    int populacao;                // Número de habitantes da cidade
    float area;                   // Área da cidade em km²
    float pib;                    // Produto Interno Bruto da cidade
    int pontosTuristicos;         // Número de pontos turísticos
} CartaSuperTrunfo;

void lerCarta(CartaSuperTrunfo* carta) {
    printf("Informe os dados da carta:\n");

    // Leitura do estado
    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    // Leitura do código da carta
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta->codigoCarta);

    // Leitura do nome da cidade
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta->nomeCidade);

    // Leitura da população
    printf("População da cidade: ");
    scanf("%d", &carta->populacao);

    // Leitura da área
    printf("Área da cidade em km²: ");
    scanf("%f", &carta->area);

    // Leitura do PIB
    printf("PIB da cidade: ");
    scanf("%f", &carta->pib);

    // Leitura do número de pontos turísticos
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    printf("\n");
}

void exibirCarta(CartaSuperTrunfo carta) {
    printf("Dados da Carta:\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: km² %f\n", carta.area);
    printf("PIB: R$ %f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("\n");
}

int main() {
    CartaSuperTrunfo carta1, carta2;

    printf("Informe os dados para a primeira carta:\n");
    lerCarta(&carta1);

    printf("Informe os dados para a segunda carta:\n");
    lerCarta(&carta2);

    printf("Exibindo dados das cartas:\n\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    return 0;
}    