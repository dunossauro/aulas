#include <stdio.h>
#include <stdlib.h>

// alacerdabr@hotmail.com

typedef struct node{
    struct node *esquerda;
    struct node *direita;
    int dado;
}NODE;

typedef struct tree{
    NODE *root;
}ARVORE;

ARVORE* criar_arvore(){
    ARVORE *t = (ARVORE*) malloc(sizeof(ARVORE));
    if(t == NULL)
        return t;
    t->root = NULL;
    return t;
}

void inserir(NODE *root, NODE *p){
    if(root->dado > p->dado){
        if(root->esquerda == NULL)
            root->esquerda = p;
        else
            inserir(root->esquerda, p);
    }
    else if(root->dado < p->dado){
        if(root->direita == NULL)
            root->direita = p;
        else
            inserir(root->direita, p);
    }
}

void inserir_node(ARVORE *t, int value){
    if(t == NULL)
        return;

    NODE *p = (NODE*)malloc(sizeof(NODE));
    if(p == NULL)
        return;
    p->esquerda = p->direita = NULL;
    p->dado = value;

    if(t->root == NULL)
        t->root = p;
    else
        inserir(t->root, p);

}

void pre(NODE *root){
    if(root != NULL){
        printf("%d ", root->dado);
        pre(root->esquerda);
        pre(root->direita);
    }
}

void pre_orden(ARVORE *t){
    if(t == NULL){
        printf("NULL\n");
        return;
    }
    printf("{");
    pre(t->root);
    printf("}");
    printf("\n");
}

void in(NODE *root){
    if(root != NULL){
        in(root->esquerda);
        printf("%d ", root->dado);
        in(root->direita);
    }
}

void in_orden(ARVORE *t){
    if(t == NULL){
        printf("NULL\n");
        return;
    }

    printf("{");
    in(t->root);
    printf("}");
    printf("\n");
}

void post(NODE *root){
    if(root != NULL){
        post(root->esquerda);
        post(root->direita);
        printf("%d ",root->dado);
    }
}

void post_orden(ARVORE *t){
    if(t == NULL){
        printf("NULL\n");
        return;
    }
    printf("{");
    post(t->root);
    printf("}");
    printf("\n");
}

void min(NODE *root){
    if(root == NULL){
        printf("Empty\n");
        return;
    }

    if(root->esquerda == NULL)
       printf("Min = %d\n", root->dado);
    else
        min(root->esquerda);
}

void min_value(ARVORE *t){
    if(t == NULL){
        printf("NULL\n");
        return;
    }

    min(t->root);
}

void max(NODE *root){
    if(root == NULL){
        printf("Empty\n");
        return;
    }

    if(root->direita == NULL)
        printf("Max = %d\n", root->dado);
    else
        max(root->direita);
}

void max_value(ARVORE *t){
    if(t == NULL){
        printf("NULL\n");
        return;
    }
    max(t->root);
}
void destroy(NODE *root){
    if(root != NULL){
        destroy(root->esquerda);
        destroy(root->direita);
        free(root);
    }
}

void destroy_tree(ARVORE* t){
    if(t == NULL)
        return;
    destroy(t->root);
    free(t);
}

int main(){

    ARVORE *t;
    t = criar_arvore();
    inserir_node(t, 4);
    inserir_node(t, 3);
    inserir_node(t, 9);
    inserir_node(t, 5);
    inserir_node(t, 8);
    inserir_node(t, 2);
    inserir_node(t, 0);
    inserir_node(t, 6);
    inserir_node(t, 7);
    inserir_node(t, 1);
//    in(1);

    printf("PREORDEN\n");
    pre_orden(t);

    printf("INORDEN\n");
    in_orden(t);

    printf("POSTORDEN\n");
    post_orden(t);

    min_value(t);
    max_value(t);
    destroy_tree(t);
    return 0;
}
