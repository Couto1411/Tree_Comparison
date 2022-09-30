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

// Printando em ordem, filhos esquerdo, pai, filho direito.
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

Record removeTree(Tree **t, Record r){
	Tree *aux;
	Record retorno;
  	
  	if (*t == nullptr){ 
		retorno.key=-1;
    	return retorno;
  	}

  	if (r.key < (*t)->item.key){ return removeTree(&(*t)->FE, r); }
  	if (r.key > (*t)->item.key){ return removeTree(&(*t)->FD, r); }

  	if ((*t)->FD == nullptr){ 
  		aux = *t;  
		retorno=aux->item;
  		*t = (*t)->FE;
    	delete aux;
    	return retorno;
  	}

  	if ((*t)->FE != nullptr){ 
		antecessor(&(*t)->FE, *t,&retorno); 
		return retorno;
	}

  	aux = *t;  
	retorno=aux->item;
  	*t = (*t)->FD;
  	delete aux;
    return retorno;
}

void antecessor(Tree **t, Tree *aux,Record *retorno){ 

	if ((*t)->FD != nullptr){ 
		antecessor(&(*t)->FD, aux,retorno);
		return;
	}

	*retorno=aux->item;
	aux->item = (*t)->item;
	aux = *t; 
	*t = (*t)->FE;
	delete aux;
} 
