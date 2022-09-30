#ifndef AVL_H 
#define AVL_H

#include <iostream>
#include "base.hpp"

struct Avl{
	Record item;
	Avl *FE, *FD;
	int weight;
};

void insertAvl(Avl **t, Record r);
int isInAvl(Avl *t, Record r);

void PrintAvlPreOrder(Avl *t);
void PrintAvlInOrder(Avl *t);
void PrintAvlPosOrder(Avl *t);
void PrintInRangeAVL(Avl **T);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
Record removeAvl(Avl **t, Avl **f, Record r);
void antecessor(Avl **t, Avl *aux,Record *retorno);
void rebalanceAvl(Avl **t);

int getWeight(Avl **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(Avl **t);
void rotacaoSimplesEsquerda(Avl **t);
void rotacaoDuplaDireita(Avl **t);
void rotacaoDuplaEsquerda(Avl **t);


#endif