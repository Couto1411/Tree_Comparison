#ifndef TreeStruc
#define TreeStruc

#include <queue>
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

Record removeTree(Tree **T, Record valor);
void antecessor(Tree **t, Tree *aux,Record *retorno);

#endif