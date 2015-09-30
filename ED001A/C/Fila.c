#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct no
{
    int codigo;
    char nome[20];
    struct no *next;
} no;

struct no *inicio, *auxiliar, *fim;

int cont = 0;

void enterdata()
{
    printf("Digite o código: ");
    scanf("%i", &auxiliar->codigo);

    printf("Digite o nome: ");
    scanf("%s", &auxiliar->nome);
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
            system("pause");
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
        system("pause");
    }
    else
    {
        cont--;
        auxiliar = inicio;
        inicio = inicio->next;
        auxiliar->next = NULL;
        free(auxiliar);
        printf("Removido com sucesso...");
        system("pause");
    }
}

void menu()
{
    int opt = 0;

    do
    {
        system("cls");

        printf("=== MENU ====");
        printf("\n\n");
        printf("1. Inserir\n");
        printf("2. Imprimir\n");
        printf("3. Pesquisar\n");
        printf("4. Remover\n");
        printf("5. Sair");
        printf("\n\n");
        printf("Opção: ");

        scanf("%i", &opt);

        system("cls");

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
            printf("Código: %i\n", auxiliar->codigo);
            printf("Nome: %s\n\n", auxiliar->nome);

            auxiliar = auxiliar->next;
        }
    }

    system("pause");
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

        printf("Digite o código desejado: ");
        scanf("%i", &cod);

        while(auxiliar != NULL && res == 0)
        {
            if (auxiliar->codigo == cod)
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
            printf("Nome: %s\n\n", auxiliar->nome);
        }
        else
        {
            printf("Nada encontrado!\n\n");
        }
    }

    system("pause");
}

void main()
{
    inicio = NULL;
    auxiliar = NULL;
    fim = NULL;

    setlocale(LC_ALL, "Portuguese");

    menu();
}
