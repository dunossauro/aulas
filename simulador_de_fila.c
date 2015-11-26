#include <stdlib.h>
#include <stdio.h>

/*

simulador de fila de processos

Trabalho sugerido pro José Luis ZEM
Para a disciplina de Sistemas operacionais
ministradas na Fatec Americana
para o auxilio de alunos na monitoria de programação II
nov/2015

obs: A fila não emplementa o ponteiro back, por esse fato uma gambiarra
     foi inserida com com a variável _while

Código por z4r4tu5tr4

*/


void creditos(){

  system("clear");
  printf("Eduardo Ferreira Mendes\n\n\n\n");
  printf("Aperte enter para continuar");
  system("read x");
  menu();

}

typedef struct no
{
    int pid;
    int proc;
    struct no *next;
} no;

struct no *inicio, *auxiliar, *fim;

int cont = 0, pid = 100, _while = 0;

void enterdata()
{
    printf("Digite a quantidade de vezes em que o elemento deve ser processado: ");
    scanf("%i", &auxiliar->proc);
    _while = _while + auxiliar->proc +1;
    auxiliar->pid = pid;
    pid++;
}

void enqueue(no **Lista)
{
    if (inicio == NULL)
    {
        auxiliar = (no*)malloc(sizeof(no));
        auxiliar->next = NULL;
        fim = auxiliar;
        inicio = auxiliar;
        cont++;
        enterdata();
    }
    else
    {
        if (cont >= 10)
        {
            printf("Queue overflow...");
            printf("Aperte enter para continuar");

        }
        else
        {
            auxiliar = (no*)malloc(sizeof(no));
            fim->next = auxiliar;
            auxiliar->next = NULL;
            fim = auxiliar;
            cont++;
            enterdata();
        }
    }
}

void dequeue(no **Lista)
{
    if (inicio == NULL)
    {
        printf("Queue underflow...");
        printf("Aperte enter para continuar");
        system("read x");

    }
    else
    {
        cont--;
        auxiliar = inicio;
        inicio = inicio->next;
        auxiliar->next = NULL;
        free(auxiliar);
        printf("Removido com sucesso...\n\n\n");
        printf("Aperte enter para continuar");
        system("read x");
        menu();
    }
}

void menu()
{
    int opt = 0;

    do
{
        system("clear");
        printf("=== MENU ====");
        printf("\n\n");
        printf("1. Inserir\n");
        printf("2. Imprimir\n");
        printf("3. Pesquisar\n");
        printf("4. Remover\n");
        printf("5. Esta lindu de morrer!!!\n");
        printf("6. Creditos\n");
        printf("7. Sair\n");
        printf("\n\n");
        printf("Opcao: ");

        scanf("%i", &opt);

        system("clear");

        switch(opt)
        {
        case 1:
            enqueue(&inicio);
            break;
        case 2:
            exibir(&inicio);
            break;
        case 3:
            pesquisar(&inicio);
            break;
        case 4:
            dequeue(&inicio);
            break;
        case 5:
            executar(&inicio);
        case 6:
            creditos();
            break;
        default:
            exit(0);
            break;
        }
    }
    while(opt < 6);
}

void exibir(no **Lista)
{
    if (fim == NULL)
    {
        printf("Lista vazia\n\n");
    }
    else
    {
        auxiliar = inicio;

        printf("==== Resultados ====\n\n");

        while(auxiliar != NULL)
        {
            printf("PID: %i\n", auxiliar->pid);
            printf("proc: %i\n\n",auxiliar->proc);

            auxiliar = auxiliar->next;
        }
    }

    printf("Aperte enter para continuar");
    system("read x");
    menu();
}

void pesquisar(no **Lista)
{
    if (fim == NULL)
    {
        printf("Lista vazia\n\n");
    }
    else
    {
        int cod = 0, res = 0;

        auxiliar = inicio;

        printf("==== Pesquisa ====\n\n");

        printf("Digite o PID desejado: ");
        scanf("%i", &cod);

        while(auxiliar != NULL && res == 0)
        {
            if (auxiliar->pid == cod)
            {
                res = 1;
            }
            else
            {
                auxiliar = auxiliar->next;
            }
        }

        if (res)
        {
            printf("proc: %i\n\n", auxiliar->proc);
        }
        else
        {
            printf("Nada encontrado!\n\n");
        }
    }

    printf("Aperte enter para continuar");
    system("read x");

    menu();
}

void executar(no **Lista)
{
    if (inicio == NULL){
      printf("Lista de execução vazia\n");
    }else{
      _while = _while*2;
      auxiliar = inicio;
      while (_while != 0) {

          _while--;
          if(auxiliar->proc > 0){
                  printf("OÍA LÁ... Meu proc é: %d\tEmeu PID é: %d\n", auxiliar->proc, auxiliar->pid );
                  auxiliar->proc--;
                  fim->next = inicio;
                  auxiliar = auxiliar->next;
                  sleep(1);

          }else if(auxiliar->proc == -1){
            auxiliar = auxiliar->next;
            //printf("Pulei\n");
          }

          else if (auxiliar->proc == 0){
            printf("JEIZUIS, o processo: %d ACABOU :\()\n", auxiliar->pid);
            auxiliar->proc = -1;
            auxiliar = auxiliar->next;
            sleep(1);
          }
      }
    }
    inicio=NULL;
    auxiliar = NULL;
    fim = NULL;
    fflush(stdin);
    printf("\n\n\nDigite enter para continuar\n" );
    system("read x");
    system("clear");
    menu();
}

void main()
{
    system("clear");
    inicio = NULL;
    auxiliar = NULL;
    fim = NULL;

    menu();
}
