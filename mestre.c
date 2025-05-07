#include <stdio.h>

typedef struct {
    char estado;                       // Letra do estado
    char codigoCarta[5];              // Código da carta
    char nomeCidade[50];              // Nome da cidade
    unsigned long int populacao;      // População como unsigned long int
    float area;                        // Área da cidade em km²
    float pib;                         // PIB da cidade em bilhões
    int pontosTuristicos;             // Número de pontos turísticos
    float densidadePopulacional;      // Habitantes por km²
    float pibPerCapita;               // PIB por habitante
    float superPoder;                 // Super Poder da carta
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
    scanf("%lu", &carta->populacao);

    printf("Área da cidade em km²: ");
    scanf("%f", &carta->area);

    printf("PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000.0f) / carta->populacao;

    // Super Poder: soma dos atributos (pontosTuristicos + área + pib + pibPerCapita + populacao - densidade como inverso)
    carta->superPoder = (float)carta->populacao 
                      + carta->area 
                      + (carta->pib * 1000000000.0f) 
                      + (float)carta->pontosTuristicos 
                      + carta->pibPerCapita 
                      + (1.0f / carta->densidadePopulacional);

    printf("\n");
}

void exibirCarta(CartaSuperTrunfo carta) {
    printf("Carta:\n\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
    printf("\n");
}

void compararCartas(CartaSuperTrunfo c1, CartaSuperTrunfo c2) {
    printf("Comparação de Cartas:\n\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontosTuristicos > c2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidadePopulacional < c2.densidadePopulacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pibPerCapita > c2.pibPerCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.superPoder > c2.superPoder);
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

    compararCartas(carta1, carta2);

    return 0;
}
