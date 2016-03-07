#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define STRLEN_MAX 20

typedef struct no{
    int codigo;
    char nome[STRLEN_MAX];
    struct no *next;
} no;

struct no *corrente, *inicio, *auxiliar;

void enterdata(){
    printf("Digite o código: ");
    scanf("%i", &auxiliar->codigo);

    printf("Digite o nome: ");
    scanf("%s", &auxiliar->nome);
}

void insere(){
    if (inicio == NULL)
    {
        corrente = (no*)malloc(sizeof(no));

        inicio = corrente;
        auxiliar = corrente;
        corrente->next = NULL;

        enterdata();
    }
    else
    {
        auxiliar = corrente;
        corrente = (no*)malloc(sizeof(no));

        corrente->next = NULL;
        auxiliar->next = corrente;
        auxiliar = corrente;

        enterdata();
    }
}

void menu(){
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
        printf("5. Sair");
        printf("\n\n");
        printf("Opção: ");

        scanf("%i", &opt);

        system("clear");

        switch(opt)
        {
        case 1:
            insere();
            break;
        case 2:
            exibir();
            break;
        case 3:
            pesquisar();
            break;
        case 4:
            remover();
            break;
        default:
            exit(0);
            break;
        }
    }
    while(opt < 5);
}

void exibir(){
    if (inicio == NULL)
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

    system("read");
}

void pesquisar(){
    if (inicio == NULL)
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

    system("read");
}

void remover(){
    if (inicio == NULL)
    {
        printf("Lista vazia\n\n");
    }
    else
    {
        int cod = 0, res = 0;

        auxiliar = inicio;

        printf("==== Remover ====\n\n");

        printf("Digite o código desejado: ");
        scanf("%i", &cod);

        if (auxiliar->codigo == cod)
        {
            res = 1;

            inicio = inicio->next;
            auxiliar->next = NULL;

            free(auxiliar);
        }
        else
        {
            corrente = auxiliar;
            auxiliar = auxiliar->next;

            while(auxiliar != NULL && res == 0)
            {
                if (auxiliar->codigo == cod)
                {
                    res = 1;

                    corrente->next = auxiliar->next;
                    auxiliar->next = NULL;

                    free(auxiliar);
                }
                else
                {
                    auxiliar = auxiliar->next;
                    corrente = corrente->next;
                }
            }
        }

        if (res)
        {
            printf("Removido!");
        }
        else
        {
            printf("Nada encontrado!\n\n");
        }
    }

    system("read");
}

void main(){
    inicio = NULL;
    auxiliar = NULL;
    corrente = NULL;

    setlocale(LC_ALL, "Portuguese");

    menu();
}
