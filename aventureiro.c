#include <stdio.h>

typedef struct {
    char estado;                  // Letra do estado de 'A' a 'H'
    char codigoCarta[5];          // Código da carta (ex: A01)
    char nomeCidade[50];          // Nome da cidade
    int populacao;                // Número de habitantes
    float area;                   // Área da cidade em km²
    float pib;                    // PIB da cidade em bilhões
    int pontosTuristicos;        // Número de pontos turísticos
    float densidadePopulacional; // Habitantes por km²
    float pibPerCapita;          // PIB por habitante
} CartaSuperTrunfo;

void lerCarta(CartaSuperTrunfo* carta) {
    printf("Informe os dados da carta:\n");

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigoCarta);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", carta->nomeCidade);

    printf("População da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Área da cidade em km²: ");
    scanf("%f", &carta->area);

    printf("PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo da densidade populacional
    carta->densidadePopulacional = carta->populacao / carta->area;

    // Cálculo do PIB per capita (convertendo PIB para milhões de reais)
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;

    printf("\n");
}

void exibirCarta(CartaSuperTrunfo carta) {
    printf("Carta:\n\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
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
