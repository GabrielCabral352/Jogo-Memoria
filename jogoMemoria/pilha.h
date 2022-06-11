#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

struct Node{
 char vLetra;
 struct Node *prox;
};
typedef struct Node node;

void libera(node *PILHA);
void push(node *PILHA, char letra);
void inicia(node *PILHA);
node *pop(node *PILHA);
int tam;


void inicia(node *PILHA)
{
 PILHA->prox = NULL;
 tam=0;
}

int vazia(node *PILHA)
{
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}

node *aloca(char letra){
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
    novo->vLetra = letra;
    return novo;
 }

}


void exibe(node *PILHA)
{
 if(vazia(PILHA)){
  printf("PILHA vazia!\n\n");
  return ;
 }

 node *tmp;
 tmp = PILHA->prox;
 printf("PILHA:");
 while( tmp != NULL){
  printf(" %C ", tmp->vLetra);
  tmp = tmp->prox;
 }
}

void libera(node *PILHA)
{
 if(!vazia(PILHA)){
  node *proxNode,
     *atual;

  atual = PILHA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void push(node *PILHA, char letra){
 node *novo=aloca(letra);
 novo->prox = NULL;

 if(vazia(PILHA))
  PILHA->prox=novo;
 else{
  node *tmp = PILHA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}


node *pop(node *PILHA){
 if(PILHA->prox == NULL){
  printf("PILHA ja vazia\n\n");
  return NULL;
 }else{
  node *ultimo = PILHA->prox, *penultimo = PILHA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}
#endif // PILHA_H_INCLUDED
