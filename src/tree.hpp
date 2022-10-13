#ifndef TreeStruc
#define TreeStruc

#include "base.hpp"

struct Binary{
	Record item;
	Binary *FE, *FD;
};

void insertTree(Binary **T, Record valor);

void PrintTreePreOrder(Binary **T);
void PrintTreePosOrder(Binary **T);
void PrintTreeInOrder(Binary **T);
void PrintInRangeTree(Binary **T);

void removeTree(Binary **T, Record valor);
void antecessor(Binary **t, Binary *aux);

float insercaoTree(Binary **Raiz,vector<double> numeros,int x);
float remocaoTree(Binary **Raiz,vector<double> busca);

#endif