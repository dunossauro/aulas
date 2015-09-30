#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct no
{
    int codigo;
    char nome[20];
    struct no *next;
    struct no *back;
} no;

struct no *topo, *auxiliar;

int cont = 0;

void enterdata()
{
    printf("Digite o código: ");
    scanf("%i", &auxiliar->codigo);

    printf("Digite o nome: ");
    scanf("%s", &auxiliar->nome);
}

void push(no **Lista)
{
    if (topo == NULL)
    {
        topo = (no*)malloc(sizeof(no));
        auxiliar = topo;
        topo->back = NULL;
        topo->next = NULL;
        enterdata();
        cont++;
    }
    else
    {
        if (cont >= 10)
        {
            printf("Stack overflow.\n\n");
            system("pause");
        }
        else
        {
            topo = (no*)malloc(sizeof(no));
            auxiliar->next = topo;
            topo->back = auxiliar;
            auxiliar = topo;
            topo->next = NULL;
            enterdata();
            cont++;
        }
    }
}

/* Remove o elemento do topo da Pilha. */
void pop(no **Lista)
{
    if (topo == NULL)
    {
        printf("Stack underflow.\n\n");
    }
    else
    {
        auxiliar = topo;
        topo = topo->back;
        auxiliar->back = NULL;
        topo->next = NULL;
        cont--;
        free(auxiliar);
        printf("Removido com sucesso.\n\n");
    }

    system("pause");
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
            push(&topo);
            break;
        case 2:
            exibir(&topo);
            break;
        case 3:
            pesquisar(&topo);
            break;
        case 4:
            pop(&topo);
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
    if (topo == NULL)
    {
        printf("Empilhamento vazio\n\n");
    }
    else
    {
        auxiliar = topo;

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
    if (topo == NULL)
    {
        printf("Empilhamento vazio\n\n");
    }
    else
    {
        int cod = 0, res = 0;

        auxiliar = topo;

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
    topo = NULL;
    auxiliar = NULL;

    setlocale(LC_ALL, "Portuguese");

    menu();
}
