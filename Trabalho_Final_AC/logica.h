#define MAX 90

typedef struct lista Lista;

typedef struct {
    int id;
    char nome[30];
    char arquitetura[5];
    char cache[20];
    float frequencia;
    float valor;
    char justificativa[100];
    char aplicacao[25];
    char consumo[6];
    char desempenho[6];
    char custo[18];
} Processador;

Lista *cria_lista();
void libera_lista(Lista* li);
int insere_lista(Lista* li, Processador processador);

void FAQ();
void menu(int menu_opcao, int menu_escolha);
int escolhe_processador(Lista* li, Processador *processador, int aplicacao, int consumo, int desempenho, int custo);
void imprime_processador(Processador processador);