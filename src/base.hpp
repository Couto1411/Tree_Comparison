#ifndef Tree_H
#define Tree_H

#include <iostream>
#include <queue>
#include <time.h>
#include <fstream>
using namespace std;

struct Tempos{
	vector<long> Insert={0,0,0,0};
	vector<long> Search={0,0,0,0};
	vector<long> Remove={0,0,0,0};
};

struct Record{
	double key;
	int value;
};

template <typename T>
void CreateTree(T** raiz){
    (*raiz)=nullptr;
};

template <typename T>
double Busca(T **raiz, Record valor){
	if ((*raiz)==nullptr)
		return -1;
	if ((*raiz)->item.key>valor.key)
		return Busca(&(*raiz)->FE,valor);
	else if ((*raiz)->item.key<valor.key)
		return Busca(&(*raiz)->FD,valor);
	else
		return (*raiz)->item.key;
	return -1;
}

template <typename T>
long timedSearch(T **raiz, vector<double> busca){
	Record r;
	auto t = clock();
	for (long unsigned int i = 0; i < busca.size(); i++){
		r.key=busca[i];			
		printf("%.5f\n",Busca(raiz,r));
	}
	auto duration = clock() - t;
	return duration;
}

#endif