#include <stdlib.h>
#include <stdio.h>

int cont = 0, pid = 100, _while = 0;

typedef struct no
{
    int pid;
    int proc;
    struct no *next;
} no;

struct no *inicio, *auxiliar, *fim;


void enterdata()
{
    printf("PID %d\nNº de Execuções: ", pid);
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
            printf("Queue overflow...\n");
            printf("Aperte enter para continuar");
	    system("read x");

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
	system("clear");
        printf("Queue underflow...\n\n");

    }
    else
    {
        cont--;
        auxiliar = inicio;
        inicio = inicio->next;
        auxiliar->next = NULL;
        free(auxiliar);
	system("clear");
        printf("Removido com sucesso...\n\n\n");
	system("read x");


    }
	printf("Aperte enter para continuar");
	system("read x");
        menu();
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
        printf("5. Executar!!!\n");
        printf("6. Sair\n");
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
        default:
            exit(0);
            break;
        }
    }
    while(opt < 5);
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
      _while = _while*10;
      auxiliar = inicio;
      while (_while != 0) {

          _while--;
          if(auxiliar->proc > 0){
                  printf("PID: %d\t|\tProc: %d\n", auxiliar->pid,auxiliar->proc);
                  auxiliar->proc--;
                  fim->next = inicio;
                  auxiliar = auxiliar->next;
                  sleep(1);

          }else if(auxiliar->proc == -1){
          
		auxiliar = auxiliar->next;
          
	  }else if (auxiliar->proc == 0){
            printf("PID: %d\t|\tProcessado \n", auxiliar->pid);
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

