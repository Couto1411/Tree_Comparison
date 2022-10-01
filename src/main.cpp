#include "rb.hpp"
#include "avl.hpp"
#include "tree.hpp"
#include "rand.hpp"
#include <chrono>

int main(){
	// Record r;
	// double numero;
	// float temp;
	// vector<long long> Treetemposin,AVLtemposin,RBtemposin,Treetempossearch,AVLtempossearch,RBtempossearch;
	// vector<double> numeros;
	// vector<float> busca;
	// RedBlack *redblack;
	// Avl *avl;
	// Tree *Raiz;
	// int x=50;
	// ifstream arqbusca ("files/search.txt");
	// for(int i=0; i<10000; i++){
	// 	arqbusca>>temp;
	// 	busca.push_back(temp);
	// }
	// for (int i = 0; i < 4; i++)
	// {
	// 	CreateTree(&redblack);
	// 	CreateTree(&avl);
	// 	CreateTree(&Raiz);
	// 	x=x*10;

	// 	// leitura do arquivo 500/5000/50000/500000
	// 	string path="files/rand";
	// 	path=path+to_string(x)+".txt";
	// 	ifstream myfile (path);
	// 	for(int i=0; i<x; i++){
	// 		myfile>>numero;
	// 		numeros.push_back(numero);
	// 	}

	// 	// insercao Binaria
	// 	auto start = chrono::high_resolution_clock::now();
	// 	for(int i=0; i<x; i++){
	// 		r.key = numeros[i];
	// 		r.value = 1;
	// 		insertTree(&Raiz,r);
	// 	}
	// 	auto stop = chrono::high_resolution_clock::now();
	// 	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	// 	Treetemposin.push_back(duration.count());

	// 	// pesquisa e remocao Binaria
	// 	start = chrono::high_resolution_clock::now();
	// 	for (long unsigned int i = 0; i < busca.size(); i++){
	// 		r.key=busca[i];
	// 		cout<<removeTree(&Raiz,r).key<<endl;
	// 	}
	// 	stop = chrono::high_resolution_clock::now();
	// 	duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	// 	Treetempossearch.push_back(duration.count());
		
	// 	// insercao AVL
	// 	start = chrono::high_resolution_clock::now();
	// 	for(int i=0; i<x; i++){
	// 		r.key = numeros[i];
	// 		r.value = 1;
	// 		insertAvl(&avl, r);
	// 	}
	// 	stop = chrono::high_resolution_clock::now();
	// 	duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	// 	AVLtemposin.push_back(duration.count());

	// 	// pesquisa e remocao AVL
	// 	start = chrono::high_resolution_clock::now();
	// 	for (long unsigned int i = 0; i < busca.size(); i++){
	// 		r.key=busca[i];			
	// 		cout<<removeAvl(&avl,&avl,r).key<<endl;
	// 	}
	// 	stop = chrono::high_resolution_clock::now();
	// 	duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	// 	AVLtempossearch.push_back(duration.count());

	// 	// insercao RedBlack
	// 	start = chrono::high_resolution_clock::now();
	// 	for(int i=0; i<x; i++){
	// 		r.key = numeros[i];
	// 		r.value = 1;
	// 		insertRedBlack(&redblack, &redblack, &redblack, r);
	// 	};
	// 	stop = chrono::high_resolution_clock::now();
	// 	duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	// 	RBtemposin.push_back(duration.count());
	// }
	// cout<< "Tempos Insertion Tree:"<<endl;
	// for (size_t i = 0; i < Treetemposin.size(); i++)
	// 	cout<< Treetemposin[i]<< " ";
	// cout<< endl;

	// cout<< "Tempos Busca Tree:"<<endl;
	// for (size_t i = 0; i < Treetempossearch.size(); i++)
	// 	cout<< Treetempossearch[i]<< " ";
	// cout<< endl;
	
	// cout<< "Tempos Insertion AVL:"<<endl;
	// for (size_t i = 0; i < AVLtemposin.size(); i++)
	// 	cout<< AVLtemposin[i]<< " ";
	// cout<< endl;

	// cout<< "Tempos Busca AVL:"<<endl;
	// for (size_t i = 0; i < AVLtempossearch.size(); i++)
	// 	cout<< AVLtempossearch[i]<< " ";
	// cout<< endl;
	
	// cout<< "Tempos RB:"<<endl;
	// for (size_t i = 0; i < RBtemposin.size(); i++)
	// 	cout<< RBtemposin[i]<< " ";
	// cout<< endl;
	int reg[] = {10,2,8,5,3,9,16,4,11,1,7,23,14,6};
	RedBlack*RB;
	Record r;
	for (int j = 0; j < 14; j++)
	{
		CreateTree(&RB);
		for(int i=0; i<14; i++){
			r.key = reg[i];
			r.value = 1;
			insertRedBlack(&RB,&RB,&RB, r);
		}
		PrintInRangeRB(&RB);
		r.key=reg[j];
		cout<<endl;
		removeRB(&RB,&RB,r);
		PrintInRangeRB(&RB);
		cout<<endl;
		cout<<endl;
		cout<<endl;
	}
	

}