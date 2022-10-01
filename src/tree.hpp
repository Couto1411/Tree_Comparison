#ifndef TreeStruc
#define TreeStruc

#include "base.hpp"

struct Tree{
	Record item;
	Tree *FE, *FD;
};

void insertTree(Tree **T, Record valor);

void PrintTreePreOrder(Tree **T);
void PrintTreePosOrder(Tree **T);
void PrintTreeInOrder(Tree **T);
void PrintInRangeTree(Tree **T);

void removeTree(Tree **T, Record valor);
void antecessor(Tree **t, Tree *aux);

long long insercaoTree(Tree **Raiz,vector<double> numeros,int x);
long long remocaoTree(Tree **Raiz,vector<double> busca);

#endif