#include <stdio.h>
#include <stdlib.h>
#include "logica.h"

// Funcoes da lista de dados
struct lista {
    int qtd;
    Processador dados[MAX];
};

Lista* cria_lista () {
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL) {
        li->qtd = 0;
    }
    return li;
}

void libera_lista (Lista* li) {
    free(li);
}

int insere_lista(Lista* li, Processador processador){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)//lista cheia
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].id < processador.id)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = processador;
    li->qtd++;
    return 1;
}

//Funcoes da interface do programa
void FAQ () {
    printf("Q: O que e um processador?\n");
    printf("R: O processador eh o componente responsavel por executar as instrucoes de um computador, atuando como o \"cerebro\" da maquina.\n\n");

    printf("Q: O que significa a frequencia de um processador (GHz)?\n");
    printf("R: Eh a velocidade com que o processador executa as instrucoes, medida em gigahertz (GHz). Quanto maior, mais rapido ele pode processar dados.\n\n");

    printf("Q: O que sao nucleos em um processador?\n");
    printf("R: Nucleos sao unidades de processamento independentes dentro do processador, que permitem realizar varias tarefas simultaneamente.\n\n");

    printf("Q: O que e um thread?\n");
    printf("R: Um thread e uma sequencia de instrucoes que pode ser executada por um nucleo. Alguns processadores oferecem threads extras por nucleo (Hyper-Threading ou SMT).\n\n");

    printf("Q: Qual a diferenca entre processadores Intel e AMD?\n");
    printf("R: Intel foca em eficiencia energetica e desempenho single-core, enquanto AMD costuma oferecer melhor custo-beneficio e maior numero de nucleos por preco.\n\n");

    printf("Q: O que eh arquitetura de processador?\n");
    printf("R: Eh o design fundamental do processador, que define como ele processa dados e interage com outros componentes.\n\n");

    printf("Q: Para que serve o cache do processador?\n");
    printf("R: O cache eh uma memoria rapida no processador que armazena dados frequentemente usados para acelerar o acesso.\n\n");

    printf("Q: Qual a importancia do TDP em um processador?\n");
    printf("R: TDP (Thermal Design Power) indica a quantidade de calor gerado pelo processador que o sistema de resfriamento deve dissipar.\n\n");

    printf("Q: Processadores com mais nucleos sao sempre melhores?\n");
    printf("R: Nao necessariamente. Isso depende da aplicacao. Jogos geralmente usam menos nucleos, enquanto softwares de edicao e renderizacao se beneficiam de mais nucleos.\n\n");

    printf("Q: O que eh overclock?\n");
    printf("R: Eh o processo de aumentar a frequencia do processador acima do especificado pelo fabricante para obter mais desempenho.\n\n");

    printf("Q: Processadores de laptop e desktop sao iguais?\n");
    printf("R: Nao. Processadores de laptops sao projetados para eficiencia energetica, enquanto os de desktops oferecem mais desempenho bruto.\n\n");

    printf("Q: O que e Turbo Boost ou Precision Boost?\n");
    printf("R: Sao tecnologias da Intel e AMD que aumentam automaticamente a frequencia do processador em tarefas que exigem mais desempenho.\n\n");

    printf("Q: Qual a diferenca entre 32 bits e 64 bits?\n");
    printf("R: Processadores de 64 bits podem lidar com mais memoria e realizar calculos mais complexos do que os de 32 bits.\n\n");

    printf("Q: Eh possivel trocar o processador do meu computador?\n");
    printf("R: Sim, mas depende do soquete da placa-mae e da compatibilidade com o processador desejado.\n\n");

    printf("Q: Quais os fatores mais importantes na escolha de um processador?\n");
    printf("R: O tipo de uso (jogos, trabalho, tarefas simples), orcamento e compatibilidade com os demais componentes do computador.\n\n");

}

void menu (int menu_opcao, int menu_escolha) {
    
    system("clear");
    printf("                              __________________ \n");
    printf("                              | ______________  |\n");
    printf("                              | |             | |\n");
    printf("                              | |             | |\n");
    printf("                              | |             | |\n");
    printf("                              | |_____________| |\n");
    printf("                              |_________________|\n");
    printf("                                  _[_______]_    \n");
    printf("                             ____[___________]____\n");
    printf("                             |         [_____] []|\n");
    printf("                             |         [_____] []|\n");
    printf("                             L___________________J\n");
    printf("                             _____________________\n");
    printf("                             |###################|\n\n");   

    printf("                      +-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+\n");
    printf("                      |P|R|O|C|E|S|S|A|D|O|R| |I|D|E|A|L|\n");
    printf("                      +-+-+-+-+ +-+-+ +-+-+-+-+-+-+-+-+-+\n\n");

    switch (menu_opcao) {
        case 1:
            if (menu_escolha == 1) {
                printf("Tipo de aplicacao do processador:\n");
                printf("1. Jogos\n2. Iot\n3. Inteligencia Artificial\n4. Edicao de Videos\n5. Modelagem 3D\n\n> ");
            }
            if (menu_escolha == 2) {
                printf("Consumo de energia:\n");
                printf("1. Baixo\n2. Medio\n3. Alto\n\n> ");
            }
            if (menu_escolha == 3) {
                printf("Desempenho necessario:\n");
                printf("1. Baixo\n2. Medio\n3. Alto\n\n> ");
            }
            if (menu_escolha == 4) {
                printf("Custo do processador:\n");
                printf("1. Acessivel\n2. Alto investimento\n\n> ");
            }
            break;
        case 2:
            system("clear");
            FAQ();
            printf("(Precione enter para voltar ao menu principal)");
            break;
        default:
            printf("Selecione uma das opcoes:\n");
            printf("1. Iniciar escolha\n2. FAQ\n3. Fechar\n\n> ");
    }

}

int escolhe_processador (Lista* li, Processador* processador, int aplicacao, int consumo, int desempenho, int custo) {
    if(li == NULL){
        return 0;
    }
    int posicao_tipo = 18 * (aplicacao - 1);
    int posicao_consumo =  6 * (consumo - 1);
    int posicao_desempenho = 2 * (desempenho - 1);
    int posicao_custo = custo - 1;

    int posicao = posicao_tipo + posicao_consumo + posicao_desempenho + posicao_custo;

    *processador = li->dados[posicao];
    return 1;
}

void imprime_processador (Processador processador) {
    system("clear");
    printf("   =====================================\n"); 
    printf("***** Este é o seu processador ideal: *****\n"); 
    printf("   =====================================\n\n");
    printf("Nome: %s\n", processador.nome);
    printf("Arquitetura: %s\n", processador.arquitetura);
    printf("Cache: %s\n", processador.cache);
    printf("Frequencia: %.1f GHz\n", processador.frequencia);
    printf("Valor: R$ %.2f\n", processador.valor);
    printf("Justificativa: %s\n\n", processador.justificativa);

    printf("(Precione enter para voltar ao menu principal)");
}