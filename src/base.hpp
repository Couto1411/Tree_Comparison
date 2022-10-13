#ifndef Tree_H
#define Tree_H

#include <iostream>
#include <queue>
#include <ctime>
#include <fstream>
using namespace std;

struct Tempos{
	vector<float> Insert={0,0,0,0};
	vector<float> Search={0,0,0,0};
	vector<float> Remove={0,0,0,0};
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
float timedSearch(T **raiz, vector<double> busca){
	Record r;
	size_t t = clock();
	for (long unsigned int i = 0; i < busca.size(); i++){
		r.key=busca[i];			
		printf("%.5f\n",Busca(raiz,r));
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

template <typename T>
void printTempos(T classe, int qtd,string nome){
	cout<< "Tempos "<<nome<<":" <<endl<< "Insertion: ";
	for (size_t i = 0; i < classe.Insert.size(); i++)
		cout<< (classe.Insert[i]/qtd)<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < classe.Search.size(); i++)
		cout<< (classe.Search[i]/qtd)<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < classe.Remove.size(); i++)
		cout<< (classe.Remove[i]/qtd)<< " ";
	cout<<endl;
}


#endif