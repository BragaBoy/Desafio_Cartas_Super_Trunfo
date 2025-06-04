#include <stdio.h>

// Estrutura da carta
typedef struct {
    char estado[30];
    char codigo[3];
    char cidade[30];
    long populacao;
    double pib; // em bilhões
    double area; // em km²
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
} Pais;

// Função para cadastrar uma carta
Pais cadastrarPais() {
    Pais p;

    printf("Estado: ");
    scanf(" %[^\n]", p.estado);

    printf("Código do país (ex: BR): ");
    scanf(" %s", p.codigo);

    printf("Cidade: ");
    scanf(" %[^\n]", p.cidade);

    printf("População (habitantes): ");
    scanf("%ld", &p.populacao);

    printf("PIB (em bilhões): ");
    scanf("%lf", &p.pib);

    printf("Área (km²): ");
    scanf("%lf", &p.area);

    printf("Número de pontos turísticos: ");
    scanf("%d", &p.pontos_turisticos);

    // Cálculo das propriedades derivadas
    p.densidade = p.area > 0 ? (double)p.populacao / p.area : 0;
    p.pib_per_capita = p.populacao > 0 ? (p.pib * 1e9) / p.populacao : 0;

    return p;
}

// Função para exibir os dados cadastrados
void mostrarPais(Pais p) {
    printf("\n----- Dados da Carta -----\n");
    printf("Cidade: %s (%s - %s)\n", p.cidade, p.estado, p.codigo);
    printf("População: %ld\n", p.populacao);
    printf("PIB: %.2f bilhões\n", p.pib);
    printf("Área: %.2f km²\n", p.area);
    printf("Pontos Turísticos: %d\n", p.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", p.densidade);
    printf("PIB per capita: R$ %.2f\n", p.pib_per_capita);
}

// Função principal apenas para cadastro
int main() {
    Pais pais1, pais2;

    printf("=== Cadastro da Carta do Jogador 1 ===\n");
    pais1 = cadastrarPais();
    mostrarPais(pais1);

    printf("\n=== Cadastro da Carta do Jogador 2 ===\n");
    pais2 = cadastrarPais();
    mostrarPais(pais2);

    return 0;
}
