#include <stdio.h>
#include <string.h> 

// Definição da estrutura para armazenar informações da cidade
struct Cidade {
    char estado[50];
    char nome[50];
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

void comparar_cidades(struct Cidade c1, struct Cidade c2) {
    printf("\nComparando %s e %s:\n", c1.nome, c2.nome);
    
    // Comparação de Densidade Populacional
    float densidade1 = (float)c1.populacao / c1.area;
    float densidade2 = (float)c2.populacao / c2.area;
    if (densidade1 < densidade2) {
        printf("Densidade Populacional: %s vence (%.2f < %.2f)\n", c2.nome, densidade1, densidade2);
    } else if (densidade1 > densidade2) {
        printf("Densidade Populacional: %s vence (%.2f > %.2f)\n", c1.nome, densidade1, densidade2);
    } else {
        printf("Densidade Populacional: Empate (%.2f = %.2f)\n", densidade1, densidade2);
    }

    // Comparação de PIB
    if (c1.pib > c2.pib) {
        printf("PIB: %s vence (%.2f > %.2f)\n", c1.nome, c1.pib, c2.pib);
    } else if (c1.pib < c2.pib) {
        printf("PIB: %s vence (%.2f < %.2f)\n", c2.nome, c2.pib, c1.pib);
    } else {
        printf("PIB: Empate (%.2f = %.2f)\n", c1.pib, c2.pib);
    }

    // Comparação de Pontos Turísticos
    if (c1.pontos_turisticos > c2.pontos_turisticos) {
        printf("Pontos Turísticos: %s vence (%d > %d)\n", c1.nome, c1.pontos_turisticos, c2.pontos_turisticos);
    } else if (c1.pontos_turisticos < c2.pontos_turisticos) {
        printf("Pontos Turísticos: %s vence (%d < %d)\n", c2.nome, c2.pontos_turisticos, c1.pontos_turisticos);
    } else {
        printf("Pontos Turísticos: Empate (%d = %d)\n", c1.pontos_turisticos, c2.pontos_turisticos);
    }
}

int main() {
    // Criando um array de cidades para armazenar os dados
    struct Cidade cidades[32] = {
        // Acre
        {"Acre", "Rio Branco", "A01", 364756, 9233.0, 10.955675, 64},
        {"Acre", "Cruzeiro do Sul", "A02", 12457, 7924.943, 1.425684780, 10},
        {"Acre", "Mancio Lima", "A03", 17910, 4672.321, 0.088211169, 7},
        {"Acre", "Plácido de Castro", "A04", 19565, 2047.0, 0.601471, 5},
        
        // Bahia
        {"Bahia", "Salvador", "B01", 2910705, 693.442, 114.4, 15},
        {"Bahia", "Feira de Santana", "B02", 616272, 1304.0, 27.69108, 12},
        {"Bahia", "Ilheus", "B03", 178649, 1456.0, 32.756, 15},
        {"Bahia", "Porto Seguro", "B04", 168326, 2285.734, 24.70276, 14},
        
        // Ceará
        {"Ceará", "Fortaleza", "C01", 2429000, 313.8, 83.459, 15},
        {"Ceará", "Sobral", "C02", 242216, 2068.474, 21.67933, 10},
        {"Ceará", "Acaraú", "C03", 68758, 842.884, 0.309490, 5},
        {"Ceará", "Maracanaú", "C04", 234509, 105.071, 6.5, 5},
        
        // Distrito Federal
        {"Distrito Federal", "Brasília", "D01", 2915869, 5801.0, 34.959, 15},
        {"Distrito Federal", "Planaltina", "D02", 93872, 1194.0, 1.5, 5},
        {"Distrito Federal", "Águas Lindas de Goiás", "D03", 225693, 191.817, 11.05296, 5},
        {"Distrito Federal", "Sobradinho", "D04", 91142, 1142.0, 1.5, 5},
        
        // Espírito Santo
        {"Espírito Santo", "Vitória", "E01", 396718, 1103.0, 14.5, 11},
        {"Espírito Santo", "Serra", "E02", 520653, 547.6, 37.27, 8},
        {"Espírito Santo", "Cariacica", "E03", 393946, 279.975, 13.698973, 5},
        {"Espírito Santo", "Guarapari", "E04", 124656, 589.826, 19.74625, 7},
        
        // Goiás
        {"Goiás", "Goiânia", "G01", 1444919, 729.296, 59.0, 20},
        {"Goiás", "Anápolis", "G02", 434111, 933.156, 44.86034, 10},
        {"Goiás", "Aparecida de Goiânia", "G03", 550925, 279.954, 28.21326, 10},
        {"Goiás", "Trindade", "G04", 104111, 712.69, 20.20076, 15},
        
        // Maranhão
        {"Maranhão", "São Luís", "M01", 1011415, 582.974, 12.0, 10},
        {"Maranhão", "Imperatriz", "M02", 250000, 1000.0, 10.0, 5},
        {"Maranhão", "Caxias", "M03", 463501, 1652.0, 1.814096, 9},
        {"Maranhão", "São José de Ribamar", "M04", 244579, 386.282, 12.71988, 15},
        
        // Rio de Janeiro
        {"Rio de Janeiro", "Rio de Janeiro", "R01", 6775561, 1221.040, 73.3, 20},
        {"Rio de Janeiro", "Niterói", "R02", 487327, 138.0, 10.0, 10},
        {"Rio de Janeiro", "Nova Iguaçu", "R03", 1363111, 138.0, 21.55906, 5},
        {"Rio de Janeiro", "Duque de Caxias", "R04", 934914, 118.0, 12.0, 5}
    };
    
    int num_cidades = 32; // Total de cidades
    
    // Exibir menu de cidades organizado por estado
    printf("Lista de cidades disponíveis por estado:\n\n");
    
    char estado_atual[50] = "";
    for (int i = 0; i < num_cidades; i++) {
        if (strcmp(estado_atual, cidades[i].estado) != 0) {
            // Novo estado encontrado
            strcpy(estado_atual, cidades[i].estado);
            printf("\n%s:\n", estado_atual);
        }
        printf("%d - %s\n", i, cidades[i].nome);
    }
    
    // Solicitar escolha do usuário
    int cidade1, cidade2;
    printf("\nEscolha o número da primeira cidade (0 a %d): ", num_cidades - 1);
    scanf("%d", &cidade1);
    printf("Escolha o número da segunda cidade (0 a %d): ", num_cidades - 1);
    scanf("%d", &cidade2);
    
    // Validar escolhas
    if (cidade1 < 0 || cidade1 >= num_cidades || cidade2 < 0 || cidade2 >= num_cidades) {
        printf("Escolha inválida!\n");
        return 1;
    }
    
    // Comparar as cidades escolhidas
    comparar_cidades(cidades[cidade1], cidades[cidade2]);
    
    return 0;
}
