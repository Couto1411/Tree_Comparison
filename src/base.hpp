#ifndef Tree_H
#define Tree_H

#include <iostream>
#include <queue>
using namespace std;

struct Record{
	float key;
	int value;
};

template <typename T>
void CreateTree(T** raiz){
    (*raiz)=nullptr;
};

template <typename T>
T *Busca(T **raiz, Record valor){
	if ((*raiz)==nullptr)
		return nullptr;
	if ((*raiz)->item.key>valor.key)
		return Busca(&(*raiz)->FE,valor);
	else if ((*raiz)->item.key<valor.key)
		return Busca(&(*raiz)->FD,valor);
	else
		return *raiz;
	return nullptr;
}

#endif