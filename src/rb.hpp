#ifndef RB_H 
#define RB_H

#include <iostream>
#include "base.hpp"

struct RedBlack{
	Record item;
	RedBlack *FE, *FD;
	RedBlack *pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};


void insertFixUp(RedBlack **raiz, RedBlack *child);
void insertRedBlack(RedBlack **t, RedBlack **pai, RedBlack **raiz, Record r);

void rotacaoSimplesEsquerdaRB(RedBlack **raiz, RedBlack *child);
void rotacaoSimplesDireitaRB(RedBlack **raiz, RedBlack *child);

void PrintRBPreOrder(RedBlack *t);
void PrintRBInOrder(RedBlack *t);
void PrintRBPosOrder(RedBlack *t);
void PrintInRangeRB(RedBlack **T);

void RBTransplant(RedBlack **T, RedBlack *valor, RedBlack *Sucessor);
void RBDeleteFixup(RedBlack **T, RedBlack *valor);
void deleteRB(RedBlack **T, RedBlack *valor);
void removeRB(RedBlack **raiz,RedBlack **t, Record r);

RedBlack * TreeMinimun(RedBlack **t);


#endif
