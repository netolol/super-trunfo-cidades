#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];           // Código do estado (ex: SP, RJ)
    char codigo[4];           // Código da carta (ex: A01, B02)
    char nome_cidade[50];     // Nome da cidade
    int populacao;            // População da cidade
    double pib;               // PIB em bilhões
    double area;              // Área em km²
    int pontos_turisticos;    // Número de pontos turísticos
    double densidade_pop;     // Densidade populacional (calculada)
    double pib_per_capita;    // PIB per capita (calculado)
} Carta;

// Função para limpar a entrada
void limpar_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar uma carta
void cadastrar_carta(Carta *carta) {
    printf("\n=== CADASTRO DE CARTA ===\n");
    
    printf("Estado (2 letras, ex: SP): ");
    scanf("%2s", carta->estado);
    
    printf("Código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);
    
    limpar_entrada(); // Limpa antes de ler string com espaços
    
    printf("Nome da cidade: ");
    fgets(carta->nome_cidade, sizeof(carta->nome_cidade), stdin);
    // Remove quebra de linha do fgets
    carta->nome_cidade[strcspn(carta->nome_cidade, "\n")] = 0;
    
    printf("População: ");
    scanf("%d", &carta->populacao);
    
    printf("PIB (em bilhões): ");
    scanf("%lf", &carta->pib);
    
    printf("Área (em km²): ");
    scanf("%lf", &carta->area);
    
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Cálculos das propriedades derivadas
    if (carta->area > 0) {
        carta->densidade_pop = (double)carta->populacao / carta->area;
    } else {
        carta->densidade_pop = 0;
    }
    
    if (carta->populacao > 0) {
        carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao; // PIB em reais
    } else {
        carta->pib_per_capita = 0;
    }
    
    printf("\n✓ Carta cadastrada com sucesso!\n");
}

// Função para exibir uma carta
void exibir_carta(const Carta *carta) {
    printf("\n=== CARTA: %s ===\n", carta->codigo);
    printf("Estado: %s\n", carta->estado);
    printf("Cidade: %s\n", carta->nome_cidade);
    printf("População: %d habitantes\n", carta->populacao);
    printf("PIB: %.2f bilhões\n", carta->pib);
    printf("Área: %.2f km²\n", carta->area);
    printf("Pontos Turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_pop);
    printf("PIB per Capita: R$ %.2f\n", carta->pib_per_capita);
    printf("========================\n");
}

// Função para comparar cartas
void comparar_cartas(const Carta *carta1, const Carta *carta2) {
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    printf("Carta 1: %s (%s)\n", carta1->nome_cidade, carta1->codigo);
    printf("Carta 2: %s (%s)\n", carta2->nome_cidade, carta2->codigo);
    printf("============================\n");
    
    // Comparação População
    printf("POPULAÇÃO:\n");
    printf("  %s: %d\n", carta1->nome_cidade, carta1->populacao);
    printf("  %s: %d\n", carta2->nome_cidade, carta2->populacao);
    if (carta1->populacao > carta2->populacao) {
        printf("  🏆 Vencedor: %s\n", carta1->nome_cidade);
    } else if (carta2->populacao > carta1->populacao) {
        printf("  🏆 Vencedor: %s\n", carta2->nome_cidade);
    } else {
        printf("  🤝 Empate!\n");
    }
    
    // Comparação PIB
    printf("\nPIB:\n");
    printf("  %s: %.2f bilhões\n", carta1->nome_cidade, carta1->pib);
    printf("  %s: %.2f bilhões\n", carta2->nome_cidade, carta2->pib);
    if (carta1->pib > carta2->pib) {
        printf("  🏆 Vencedor: %s\n", carta1->nome_cidade);
    } else if (carta2->pib > carta1->pib) {
        printf("  🏆 Vencedor: %s\n", carta2->nome_cidade);
    } else {
        printf("  🤝 Empate!\n");
    }
    
    // Comparação Área
    printf("\nÁREA:\n");
    printf("  %s: %.2f km²\n", carta1->nome_cidade, carta1->area);
    printf("  %s: %.2f km²\n", carta2->nome_cidade, carta2->area);
    if (carta1->area > carta2->area) {
        printf("  🏆 Vencedor: %s\n", carta1->nome_cidade);
    } else if (carta2->area > carta1->area) {
        printf("  🏆 Vencedor: %s\n", carta2->nome_cidade);
    } else {
        printf("  🤝 Empate!\n");
    }
    
    // Comparação Pontos Turísticos
    printf("\nPONTOS TURÍSTICOS:\n");
    printf("  %s: %d\n", carta1->nome_cidade, carta1->pontos_turisticos);
    printf("  %s: %d\n", carta2->nome_cidade, carta2->pontos_turisticos);
    if (carta1->pontos_turisticos > carta2->pontos_turisticos) {
        printf("  🏆 Vencedor: %s\n", carta1->nome_cidade);
    } else if (carta2->pontos_turisticos > carta1->pontos_turisticos) {
        printf("  🏆 Vencedor: %s\n", carta2->nome_cidade);
    } else {
        printf("  🤝 Empate!\n");
    }
    
    // Comparação Densidade Populacional
    printf("\nDENSIDADE POPULACIONAL:\n");
    printf("  %s: %.2f hab/km²\n", carta1->nome_cidade, carta1->densidade_pop);
    printf("  %s: %.2f hab/km²\n", carta2->nome_cidade, carta2->densidade_pop);
    if (carta1->densidade_pop > carta2->densidade_pop) {
        printf("  🏆 Vencedor: %s\n", carta1->nome_cidade);
    } else if (carta2->densidade_pop > carta1->densidade_pop) {
        printf("  🏆 Vencedor: %s\n", carta2->nome_cidade);
    } else {
        printf("  🤝 Empate!\n");
    }
    
    // Comparação PIB per Capita
    printf("\nPIB PER CAPITA:\n");
    printf("  %s: R$ %.2f\n", carta1->nome_cidade, carta1->pib_per_capita);
    printf("  %s: R$ %.2f\n", carta2->nome_cidade, carta2->pib_per_capita);
    if (carta1->pib_per_capita > carta2->pib_per_capita) {
        printf("  🏆 Vencedor: %s\n", carta1->nome_cidade);
    } else if (carta2->pib_per_capita > carta1->pib_per_capita) {
        printf("  🏆 Vencedor: %s\n", carta2->nome_cidade);
    } else {
        printf("  🤝 Empate!\n");
    }
}

// Função principal
int main() {
    Carta cartas[100]; // Array para armazenar até 100 cartas
    int num_cartas = 0;
    int opcao;
    
    printf("🃏 SUPER TRUNFO - PAÍSES 🃏\n");
    printf("Sistema de Cadastro de Cartas - TechNova\n");
    printf("======================================\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Cadastrar nova carta\n");
        printf("2. Exibir carta específica\n");
        printf("3. Listar todas as cartas\n");
        printf("4. Comparar duas cartas\n");
        printf("5. Estatísticas das cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                if (num_cartas < 100) {
                    cadastrar_carta(&cartas[num_cartas]);
                    num_cartas++;
                } else {
                    printf("❌ Limite máximo de cartas atingido!\n");
                }
                break;
            }
            
            case 2: {
                if (num_cartas == 0) {
                    printf("❌ Nenhuma carta cadastrada!\n");
                    break;
                }
                printf("Digite o número da carta (1-%d): ", num_cartas);
                int indice;
                scanf("%d", &indice);
                if (indice >= 1 && indice <= num_cartas) {
                    exibir_carta(&cartas[indice-1]);
                } else {
                    printf("❌ Carta não encontrada!\n");
                }
                break;
            }
            
            case 3: {
                if (num_cartas == 0) {
                    printf("❌ Nenhuma carta cadastrada!\n");
                    break;
                }
                printf("\n=== TODAS AS CARTAS ===\n");
                for (int i = 0; i < num_cartas; i++) {
                    printf("%d. %s - %s (%s)\n", i+1, cartas[i].codigo, 
                           cartas[i].nome_cidade, cartas[i].estado);
                }
                printf("\nTotal de cartas: %d\n", num_cartas);
                break;
            }
            
            case 4: {
                if (num_cartas < 2) {
                    printf("❌ É necessário ter pelo menos 2 cartas para comparar!\n");
                    break;
                }
                printf("Digite o número da primeira carta (1-%d): ", num_cartas);
                int carta1;
                scanf("%d", &carta1);
                printf("Digite o número da segunda carta (1-%d): ", num_cartas);
                int carta2;
                scanf("%d", &carta2);
                
                if (carta1 >= 1 && carta1 <= num_cartas && 
                    carta2 >= 1 && carta2 <= num_cartas && carta1 != carta2) {
                    comparar_cartas(&cartas[carta1-1], &cartas[carta2-1]);
                } else {
                    printf("❌ Cartas inválidas ou iguais!\n");
                }
                break;
            }
            
            case 5: {
                if (num_cartas == 0) {
                    printf("❌ Nenhuma carta cadastrada!\n");
                    break;
                }
                
                // Calcular estatísticas
                int pop_total = 0;
                double pib_total = 0, area_total = 0;
                int turisticos_total = 0;
                double densidade_media = 0, pib_pc_medio = 0;
                
                for (int i = 0; i < num_cartas; i++) {
                    pop_total += cartas[i].populacao;
                    pib_total += cartas[i].pib;
                    area_total += cartas[i].area;
                    turisticos_total += cartas[i].pontos_turisticos;
                    densidade_media += cartas[i].densidade_pop;
                    pib_pc_medio += cartas[i].pib_per_capita;
                }
                
                printf("\n=== ESTATÍSTICAS GERAIS ===\n");
                printf("Número total de cartas: %d\n", num_cartas);
                printf("População total: %d habitantes\n", pop_total);
                printf("PIB total: %.2f bilhões\n", pib_total);
                printf("Área total: %.2f km²\n", area_total);
                printf("Pontos turísticos totais: %d\n", turisticos_total);
                printf("Densidade populacional média: %.2f hab/km²\n", densidade_media/num_cartas);
                printf("PIB per capita médio: R$ %.2f\n", pib_pc_medio/num_cartas);
                break;
            }
            
            case 0:
                printf("👋 Obrigado por usar o Sistema Super Trunfo!\n");
                printf("Desenvolvido pela TechNova 🚀\n");
                break;
                
            default:
                printf("❌ Opção inválida! Tente novamente.\n");
        }
        
    } while(opcao != 0);
    
    return 0;
}