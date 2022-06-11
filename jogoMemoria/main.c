#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "pilha.h"
#include <time.h>

int menu(void);
int pontos = 0;
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void setRodada(node *PILHA);
int compara(node *PILHA, node *RESPOSTAS);
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

void gameHeader(){
    system("cls");
    printf("\t              Jogo da Memória          \n");
    printf("\t            *****Genius C*****         \n\n\n");

}



int menu(void){

    gameHeader();
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
            pontos = 0;
            setRodada(PILHA);
        break;

        default:
            printf("\n\nComando invalido\n\n");
    }
    //system("pause");
}

int finalScreen(node *PILHA,int cont){
    gameHeader();
    printf("\n\n\t\t*****Final de jogo*****\n\n");
    exibe(PILHA);
    printf("\n\n\t\tPontos: %d \n\n\n\n", pontos);
    system("pause");
    if(cont){
        printf("\n\n\tContinuar Jogando? 1-Sim 0-Não >");
        scanf("%d", &cont);
        return cont;
    }else main();

}

void verificaResp(node *PILHA){
    gameHeader();
    printf("Informe a sequência de letras até o momento iniciando pela última letra informada até a primeira:\n\n >");
    char letra;
    char todas[tam];
    int size = tam;

    for(int i = 0; i < size; i++){
        letra = getch();
        node *cLetra = pop(PILHA);
        todas[i] = cLetra->vLetra;
        int cor = 0;
        if(toupper(letra) == cLetra->vLetra){
            printf("%c ", toupper(letra) );
            pontos += 10;
            cor+=1;
        }else{
            for(int i = cor; i >= 0; i--){
                if(todas[i] != ""){
                    push(PILHA, todas[i]);
                }
            }
            printf("\n ERROU % \n");
            finalScreen(PILHA, 0);
        }
    };
    //printf("\n\n\tAcertou!!! Pontuação: %d", pontos);

    for(int i = size-1; i >= 0; i--){
        push(PILHA, todas[i]);
    }


}

void setRodada(node *PILHA){

    int jogando = 1;
    char * selecionada;
    char random;

    do{
        gameHeader();
        srand(time(0));
        random = alfabeto[(rand() % 25)];
        printf("\n\t\tInforme uma letra entre A e Z:");
        scanf("%s", &selecionada);
        //selecionada = getch();
        //printf("%c", toupper(selecionada));
        push(PILHA, toupper(selecionada));;

        push(PILHA, random);

        printf("\n\t\tLetra selecionada pelo programa: %c \n\n", random);
        printf("\n\t\tVocê tem 3 segundos para memorizar! \n\n");
        //exibe(PILHA);

        sleep(3);
        verificaResp(PILHA);
        jogando = finalScreen(PILHA, 1);
    }while(jogando);
    esvaziar(PILHA);
    exibe(PILHA);
    system("pause");
}



