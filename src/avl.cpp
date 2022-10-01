#include "avl.hpp"

void insertAvl(Avl **t, Record r){
	if(*t == nullptr){
		*t = new Avl;
		(*t)->FE   = nullptr; 
		(*t)->FD  = nullptr; 
		(*t)->weight = 0;
		(*t)->item    = r; 

	} else {
		
		if(r.key < (*t)->item.key){
			insertAvl(&(*t)->FE, r);
			if ((getWeight(&(*t)->FE) - getWeight(&(*t)->FD)) == 2){
				if(r.key < (*t)->FE->item.key)
					rotacaoSimplesDireita(t);
				else
					rotacaoDuplaDireita(t);
			}
		}
			
		if(r.key > (*t)->item.key){
			insertAvl(&(*t)->FD, r);
			if ((getWeight(&(*t)->FD) - getWeight(&(*t)->FE)) == 2){
				if(r.key > (*t)->FD->item.key)
					rotacaoSimplesEsquerda(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}

	}

	(*t)->weight = getMaxWeight(getWeight(&(*t)->FE), getWeight(&(*t)->FD)) + 1;
}

int isInAvl(Avl *t, Record r){
	if(t == nullptr){ 
		return 0;
	}

	return t->item.key == r.key || isInAvl(t->FE, r) || isInAvl(t->FD, r);
}

void antecessor(Avl **t, Avl *aux){ 

	if ((*t)->FD != nullptr){ 
		antecessor(&(*t)->FD, aux);
		return;
  	}
  	
  	aux->item = (*t)->item;
  	aux = *t; 
  	*t = (*t)->FE;
  	delete aux;
} 

void rebalanceAvl(Avl **t){
	int balance;
  	int FE = 0;
  	int FD = 0;

	balance = getWeight(&(*t)->FE) - getWeight(&(*t)->FD);
	if((*t)->FE)
		FE = getWeight(&(*t)->FE->FE) - getWeight(&(*t)->FE->FD);
	if((*t)->FD)
		FD = getWeight(&(*t)->FD->FE) - getWeight(&(*t)->FD->FD);

	if(balance == 2 && FE >= 0)
		rotacaoSimplesDireita(t);
	if(balance == 2 && FE < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && FD <= 0)
		rotacaoSimplesEsquerda(t);
	if(balance == -2 && FD > 0)
		rotacaoDuplaEsquerda(t); 	

}

void removeAvl(Avl **t, Avl **f, Record r){
	Avl *aux;
  	
  	if (*t == nullptr){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->item.key){ removeAvl(&(*t)->FE, t, r); return;}
  	if (r.key > (*t)->item.key){ removeAvl(&(*t)->FD, t, r); return;}

  	if ((*t)->FD == nullptr){ 
  		aux = *t;  
  		*t = (*t)->FE;
    	delete aux;
    	rebalanceAvl(f);
    	return;
  	}

  	if ((*t)->FE != nullptr){ 
  		antecessor(&(*t)->FE, *t);
  		rebalanceAvl(t);
  		rebalanceAvl(f);
  		return;
  	}

  	aux = *t;  
  	*t = (*t)->FD;
  	delete aux;
  	rebalanceAvl(t);
  	rebalanceAvl(f); 	
  	
}

void PrintAvlPreOrder(Avl *t){
	if(!(t == nullptr)){
		printf("%.2f:%d\t", t->item.key, t->weight);
		PrintAvlPreOrder(t->FE); 
		PrintAvlPreOrder(t->FD); 
	}
}


void PrintAvlInOrder(Avl *t){
	if(!(t == nullptr)){
		PrintAvlInOrder(t->FE); 
		printf("%.2f\t", t->item.key);
		PrintAvlInOrder(t->FD); 
	}
}

void PrintAvlPosOrder(Avl *t){
	if(!(t == nullptr)){
		PrintAvlPosOrder(t->FE); 
		PrintAvlPosOrder(t->FD); 
		printf("%.2f\t", t->item.key);
	}
}

void PrintInRangeAVL(Avl **T){
	if ((*T)!=nullptr)
	{
		queue<Avl*> tempFila;
		Avl *temp;
		int tempCont=1,cont=0;
		tempFila.push((*T));
		while (!(tempFila.empty())){
			cont=0;
			for (int i = 0; i < tempCont; i++){
				temp =tempFila.front();
				printf("%.2f:%d\t",temp->item.key, temp->weight);
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


int getWeight(Avl **t){
	if(*t == nullptr)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int FE, int FD){
	if(FE > FD)
		return FE;
	return FD;
}

void rotacaoSimplesDireita(Avl **t){
	Avl *aux;
	aux = (*t)->FE;
	(*t)->FE = aux->FD;
	aux->FD = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->FE), getWeight(&(*t)->FD)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->FE), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(Avl **t){
	Avl *aux;
	aux = (*t)->FD;
	(*t)->FD = aux->FE;
	aux->FE = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->FE), getWeight(&(*t)->FD)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->FE), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(Avl **t){
	rotacaoSimplesEsquerda(&(*t)->FE);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(Avl **t){
	rotacaoSimplesDireita(&(*t)->FD);
	rotacaoSimplesEsquerda(t);
}













