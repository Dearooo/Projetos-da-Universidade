#include <stdio.h>
#include <stdlib.h>

//Vantagens da Lista encadeada = Ilimitada, Melhor desempenho na inserção e retirada de elementos,

//Desvantagens da Lista encadeada =

// Lista duplamente encadeada é quando alem de um ponteiro que aponta para o proximo "no", tambem nesse mesmo no um ponteiro que aponta para o anterior; 


//Criamos a estrutura do no que sera utilizado para armazenar os valor e se inteligar;
typedef struct no{
    int valor;
    struct no *proximo_no;
}No;

//Criamos a lista que sera responsavel por juntar os nós, lembrando que ela só serve para salvar a ponta, ous seja ela é a ponta que recebe os nos, e não a lista;
typedef struct List{
    No *inicio; 
    int tam;
}Lista;

//inserindo no inico da lista

void Remover(){

}

void insereInicio(Lista *lista, int valor){
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor; //Tratamento de Ponteiro, igual a "(*novo).valor"
    novo->proximo_no = lista->inicio; //RESPONSAVEL POR GUARDA O PONTEIRO, PARA SER COLOCADO NO PROXIMO NO A SER COLOCADO;
    lista->inicio = novo; //PODEMOS DIZER QUE AQUI É ONDE ELA JA PREPARA O TERRENO, PARA O PROCIMO NO QUE SERA INSERIDO, ENQUANTO NA LINHA ANTERIOR ELA JUNTA OS NOS SLAVADOS NO NO AINDA ANTECESSOR A ESTE.
    lista->tam++;

}

int BuscaLista(Lista *lista, int valor){
    No *novo = (No *)malloc(sizeof(No));
    novo = lista->inicio;
    if (lista->inicio == NULL)
    {
        return 2;
    }
    while (novo != NULL)
    {   
        if (novo->valor == valor)
        {
            return 1;
        }
        novo = novo->proximo_no;
    }
    return 0;
}

void inserefinal(Lista *lista, int valor){
    No *no_1, *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo_no = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->tam++;
    }
    else{
        no_1 = lista->inicio;
        while (no_1->proximo_no != NULL)
        {
            no_1 = no_1->proximo_no;
        }
        no_1->proximo_no = novo; 
    }
    
}

void imprimir(Lista *lista){
    No *inicio = lista->inicio; //AQUI ELA CRIA UM NÓ FLASO QUE PERCORRERA A LISTA, TRAZENDO COMO PONTEIRO O NO QUE ELA PERCORRE;
    while(inicio != NULL)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo_no; //AQUI É ONDE ELA ASSUME O PROXIMO NO QUE ESTAVA INTERLIGADO AO PRIMEIRO E ASSIM POR DIANTE;
    } //COM ISSO FAZER UM SISTEMA DE BUSCA É SIMPLES, BASTA TROCAR A LOGICA DO WHILE;
    printf("\n\n");
    
}

int main(void)
{
    Lista lista;

    lista.inicio = NULL;
    lista.tam = 0;

    int op, valor, retorno;

    do
    {
        printf("1-iNSERIR NO INICIO \n2-IMPRIMIR \n3-INSERIR NO FINAL\n4-BUSCAR NUMERO\n5-SAIR\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Valor a ser inserido: ");
            scanf("%d", &valor);
            insereInicio(&lista, valor);
            break;
        case 2:
            imprimir(&lista);
            break;
        case 3:
            printf("Valor a ser inserido: ");
            scanf("%d", &valor);
            inserefinal(&lista, valor);
            break;
        case 4:
            printf("Valor a ser buscado: ");
            scanf("%d", &valor);
            retorno = BuscaLista(&lista, valor);
            if (retorno == 1)
            {
                printf("BOAAA SEU ARROMBADO, O NUMERO ESTA PRESENTE KKKKKK");
            }
            else if (retorno == 2)
            {
                printf("A Lista ta vazia VIADOOOOO!!!!");
            }
            else
                printf("NAO ESTA PRESENTEEE!!!!");
            
            break;
        case 5:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao Invalida!\n");
        }
    } while (op != 5);
    
    printf("BOOOAAAAAAAAAAAAAAAAAAAAAAAAA KARAIOOOOO!!");

    return 0;
}