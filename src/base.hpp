#ifndef Tree_H
#define Tree_H

#include <iostream>
#include <queue>
#include <chrono>
#include <ctime>
#include <fstream>
using namespace std;

struct Tempos{
	vector<long long> Insert;
	vector<long long> Search;
	vector<long long> Remove;
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
long long timedSearch(T **raiz, vector<double> busca){
	Record r;
	auto start = chrono::high_resolution_clock::now();
	for (long unsigned int i = 0; i < busca.size(); i++){
		r.key=busca[i];			
		printf("%.5f\n",Busca(raiz,r));
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

#endif