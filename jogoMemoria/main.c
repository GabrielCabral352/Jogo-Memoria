#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "pilha.h"
#include <time.h>

int menu(void);

void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void setRodada(node *PILHA);
void compara(node *PILHA, node *RESPOSTAS);
char alfabeto[26] = {
                    'A','B','C','D','E','F','G','H',
                    'I','J','K','L','M','N','O','P',
                    'Q','R','S','T','U','V','W','X',
                    'Y','Z'
                    };


int main(void){
    setlocale(LC_ALL,"");
    node *PILHA = (node *) malloc(sizeof(node));
    if(!PILHA){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        inicia(PILHA);
        int opt;
        do{
            opt=menu();
            opcao(PILHA,opt);
        }while(opt);
        free(PILHA);
        return 0;
    }
}

int menu(void){

    system("cls");
    printf("            Jogo da Memória          \n");
    printf("          *****Genius C*****         \n\n\n");
    int opt;

    printf("            Escolha a opcao\n");
    printf("            1. Jogar\n");
    printf("            0. Sair\n");
    printf("            Opcao: ");scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, int op){
    node *tmp;
    switch(op){
        case 0:
            libera(PILHA);
        break;

        case 1:
            setRodada(PILHA);
        break;

        default:
            printf("\n\nComando invalido\n\n");
    }
    //system("pause");
}

void verificaResp(){
    system("cls");

    system("pause");

}


void setRodada(node *PILHA){
    //alfabeto[rand() % 25];
    int jogando = 1;
    char * selecionada;
    char random;

    do{
        srand(time(0));
        random = alfabeto[(rand() % 25)];
        printf("\nInforme uma letra entre A e Z:");
        scanf("%s", &selecionada);
        push(PILHA, toupper(selecionada));
        push(PILHA, random);
        printf("Letra selecionada pelo programa: %c \n\n", random);
        printf("Você tem 3 segundos para memorizar!");
        exibe(PILHA);
        sleep(3);
        verificaResp();
        printf("%i", tam);
        //;
    }while(jogando);


    system("pause");
}


