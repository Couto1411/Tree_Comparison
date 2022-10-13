#include "tree.hpp"

void insertTree(Binary **T, Record valor){
	if ((*T) == nullptr)
	{
		(*T) = new Binary;
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
void PrintTreeInOrder(Binary **T){
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
void PrintTreePreOrder(Binary **T){
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
void PrintTreePosOrder(Binary **T){
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

void PrintInRangeTree(Binary **T){
	if ((*T)!=nullptr)
	{
		queue<Binary*> tempFila;
		Binary *temp;
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

void antecessor(Binary **t, Binary *aux){ 

	if ((*t)->FD != nullptr){ 
		antecessor(&(*t)->FD, aux);
		return;
  }
  	
  aux->item = (*t)->item;
  aux = *t; 
  *t = (*t)->FE;
  delete aux;
} 


void removeTree(Binary **t, Record r){
	Binary *aux;
  	
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


float insercaoTree(Binary **Raiz,vector<double> numeros,int x){
	Record r;
	size_t t = clock();
	for(int i=0; i<x; i++){
		r.key = numeros[i];
		insertTree(Raiz,r);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}
float remocaoTree(Binary **Raiz,vector<double> busca){
	Record r;
	size_t t = clock();
	for (long unsigned int i = 0; i < busca.size(); i++){
		r.key=busca[i];			
		removeTree(Raiz,r);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}