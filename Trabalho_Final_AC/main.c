#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "logica.h"

int main(){

    // loop para que o programa so encerre selecionando a opcao 3 no menu
    while(1) {
    int opcao = 0;
    menu(opcao, 0);

    // verifica se a opcao e do tipo int
    if (scanf("%d", &opcao) != 1) { 
        printf("Opcao invalida. Digite novamente.\n"); 
        sleep(1); 
        while (getchar() != '\n'); 
        continue; 
    }
    
    // verifica opcao selecionada no menu (1 para iniciar a esolha, 2 para FAQ e 3 para sair)
    if (opcao == 1) {
        // leitura das caracteristicas do processador desejado pelo usuario, com tratamento de erros caso a opcao esteja fora do intervalo ou nao seja do tipo int
        int aplicacao;
        while (1) {
            menu(opcao, 1);
            if (scanf("%d", &aplicacao) != 1 || aplicacao < 1 || aplicacao > 5) {
                printf("Opcao invalida. Digite novamente.\n");
                sleep(1);
                while (getchar() != '\n');
            } else { 
                break; 
            }
        }

        int consumo;
        while (1) {
            menu(opcao, 2);
            if (scanf("%d", &consumo) != 1 || consumo < 1 || consumo > 3) {
                printf("Opcao invalida. Digite novamente.\n");
                sleep(1);
                while (getchar() != '\n');
            } else { 
                break; 
            }
        }
        
        int desempenho;
        while (1) {
            menu(opcao, 3);
            if (scanf("%d", &desempenho) != 1 || desempenho < 1 || desempenho > 3) {
                printf("Opcao invalida. Digite novamente.\n");
                sleep(1);
                while (getchar() != '\n');
            } else { 
                break; 
            }
        }

        int custo;
        while (1) {
            menu(opcao, 4);
            if (scanf("%d", &custo) != 1 || custo < 1 || custo > 2) {
                printf("Opcao invalida. Digite novamente.\n");
                sleep(1);
                while (getchar() != '\n');
            } else { 
                break; 
            }
        }

        // leitura dos processadores em processadores.txt linha por linha
        Lista *lista = cria_lista();
        FILE *file = fopen("processadores.txt", "r");
        if (file == NULL) { 
            fprintf(stderr, "Erro ao abrir o arquivo.\n"); 
            return 1;
        }

        char linha[256];
        while (fgets(linha, sizeof(linha), file)) {
            Processador processador;
            sscanf(linha, "%d,%29[^,],%4[^,],%19[^,],%f,%f,%99[^,],%24[^,],%5[^,],%5[^,],%17[^\n]",
                                    &processador.id,
                                    processador.nome,
                                    processador.arquitetura,
                                    processador.cache,
                                    &processador.frequencia,
                                    &processador.valor,
                                    processador.justificativa,
                                    processador.aplicacao,
                                    processador.consumo,
                                    processador.desempenho,
                                    processador.custo);
            // insere o processador na lista estatica                        
            insere_lista(lista, processador);
        }

        getchar();
        Processador processador_ideal;
        // o processador_ideal vai receber o processador de acordo com as opcoes do usuario
        escolhe_processador(lista, &processador_ideal, aplicacao, consumo, desempenho, custo);
        imprime_processador(processador_ideal);

        getchar();
        libera_lista(lista);
    } 
    // FAQ
    else if (opcao == 2) {
        getchar(); 
        menu(opcao, 0);
        getchar(); 
    }
    // fecha o programa
    else if (opcao == 3) {
        break;
    } 
    // caso a entrada seja do tipo int, mas nao enteja no intervalor [1,3], volta para o inicio do loop
    else {
        printf("Opcao invalida. Digite novamente.\n");
        sleep(1);
        while (getchar() != '\n');
    }
}


    return 0;
}