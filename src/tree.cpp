#include "tree.hpp"

void insertTree(Tree **T, Record valor){
	if ((*T) == nullptr)
	{
		(*T) = new Tree;
		(*T)->item = valor;
		(*T)->FE = nullptr;
		(*T)->FD = nullptr;
		return;
	}
	if (valor.key < (*T)->item.key)
		insertTree(&(*T)->FE, valor);
	else if (valor.key > (*T)->item.key)
		insertTree(&(*T)->FD, valor);
}

// Printando em ordem, filhos FEuerdo, pai, filho FDeito.
void PrintTreeInOrder(Tree **T){
	if ((*T)){
		if ((*T)->FE)
			PrintTreeInOrder(&(*T)->FE);
		printf("%.2f, ", (*T)->item.key);
		if ((*T)->FD)
			PrintTreeInOrder(&(*T)->FD);
	}
	else
		printf("0");
}

// Printando pai antes dos filhos.
void PrintTreePreOrder(Tree **T){
	if ((*T)){
		printf("%.2f, ", (*T)->item.key);
		if ((*T)->FE)
			PrintTreePreOrder(&(*T)->FE);
		if ((*T)->FD)
			PrintTreePreOrder(&(*T)->FD);
	}
	else
		printf("0");
}

// Printando filhos antes do pai.
void PrintTreePosOrder(Tree **T){
	if ((*T)){
		if ((*T)->FE)
			PrintTreePosOrder(&(*T)->FE);
		if ((*T)->FD)
			PrintTreePosOrder(&(*T)->FD);
		printf("%.2f, ", (*T)->item.key);
	}
	else
		printf("0");
}

void PrintInRangeTree(Tree **T){
	if ((*T)!=nullptr)
	{
		queue<Tree*> tempFila;
		Tree *temp;
		int tempCont=1,cont=0;
		tempFila.push((*T));
		while (!(tempFila.empty())){
			cont=0;
			for (int i = 0; i < tempCont; i++){
				temp =tempFila.front();
				printf("%.2f\t",temp->item.key);
				tempFila.pop();
				if (temp->FE) {
					tempFila.push(temp->FE);
					cont++;
				}
				if (temp->FD) {
					tempFila.push(temp->FD);
					cont++;
				}
			}
			printf("\n");
			tempCont=cont;
		}
	}
	else{
		cout << "Arvore vazia"<<endl;
	}
}

void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->FD != nullptr){ 
		antecessor(&(*t)->FD, aux);
		return;
  }
  	
  aux->item = (*t)->item;
  aux = *t; 
  *t = (*t)->FE;
  delete aux;
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == nullptr){ 
    	return;
  	}

  	if (r.key < (*t)->item.key){ removeTree(&(*t)->FE, r); return; }
  	if (r.key > (*t)->item.key){ removeTree(&(*t)->FD, r); return; }

  	if ((*t)->FD == nullptr){ 
  		aux = *t;  
  		*t = (*t)->FE;
    	delete aux;
    	return;
  	}

  	if ((*t)->FE != nullptr){ antecessor(&(*t)->FE, *t); return; }

  	aux = *t;  
  	*t = (*t)->FD;
  	delete aux;
}


long insercaoTree(Tree **Raiz,vector<double> numeros,int x){
	Record r;
	auto t = clock();
	for(int i=0; i<x; i++){
		r.key = numeros[i];
		insertTree(Raiz,r);
	}
	auto duration = clock() - t;
	return duration;
}
long remocaoTree(Tree **Raiz,vector<double> busca){
	Record r;
	auto t = clock();
	for (long unsigned int i = 0; i < busca.size(); i++){
		r.key=busca[i];			
		removeTree(Raiz,r);
	}
	auto duration = clock() - t;
	return duration;
}