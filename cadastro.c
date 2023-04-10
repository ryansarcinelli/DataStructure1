#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 3

typedef struct aluno{
    char nome[80];
    int mat;
}Aluno;
//sas
void start(Aluno** tab){
    for(int i=0;i<size;i++){
        tab[i]=NULL;
    }
}

void ler(Aluno** tab){
    for(int i=0;i<size;i++){
        if(tab[i]==NULL){
            tab[i]=malloc(sizeof(Aluno));
            printf("\nDigite o nome do aluno %d: ", i+1);
            scanf("%79[^\n]s", tab[i]->nome);
            fflush(stdin);
            printf("\nDigite a matricula do aluno %d: ", i+1);
            scanf("%d", &tab[i]->mat);
            fflush(stdin);
        }
    }
}

void imprime(Aluno** tab){
    for(int i=0;i<size;i++){
        if(tab[i]!=NULL){
            printf("\nAluno %d: %s, %d", i+1, tab[i]->nome, tab[i]->mat);
        }
    }
}

void remover_aluno(Aluno** tab, int *n){
    int x=1, mat2=0;
    char nome2[80] = "";
    while(x==1){
        printf("\nDeseja remover um aluno? (0 ou 1) ");
        scanf("%d", &x);

        if(x==1){
            printf("\nQual aluno deseja remover? (1, 2 ou 3) ");
            scanf("%d", n);
            (*n)--;
            tab[*n]->mat = 0;
            strcpy(tab[*n]->nome, "");
            for(int i=*n; i<size-1; i++){
                strcpy(nome2, tab[i+1]->nome);
                mat2 = tab[i+1]->mat;
                strcpy(tab[i]->nome, nome2);
                tab[i]->mat = mat2;
            }
            free(tab[size-1]);
            tab[size-1] = NULL;
            printf("\nO aluno %d foi removido", (*n)+1);
        }
    }
    printf("\nVoce digitou 0");
}

void imprime_tudo(Aluno** tab){
    for(int i=0;i<size;i++){
        printf("\nAluno %d: %s, %d", i+1, tab[i]->nome, tab[i]->mat);
    }
}

int main(){
    Aluno* tab[size];
    int n=0;

    start(tab);
    ler(tab);
    imprime(tab);
    remover_aluno(tab, &n);
    imprime_tudo(tab);
    printf("\nDeseja adicionar outro aluno?");
    ler(tab);
    /*for(int i=0;i<size;i++){
        if(tab[i]==NULL)
        printf("\n%d Null", i);
        else
        printf("\nNao");
    }*/

    return 0;
}