#include "rb.hpp"

void insertFixUp(RedBlack **raiz, RedBlack *child)
{
  RedBlack *tio;

  while ((child != *raiz) && (child->pai->cor == false))
  {

    if (child->pai == child->pai->pai->FE)
    {

      tio = child->pai->pai->FD;

      // caso 1:
      if ((tio != nullptr) && (tio->cor == false))
      {
        child->pai->cor = true;
        tio->cor = true;
        child->pai->pai->cor = false;
        child = child->pai->pai;
      }
      else
      {

        // caso 2
        if (child == child->pai->FD)
        {
          child = child->pai;
          rotacaoSimplesEsquerdaRB(raiz, child);
        }

        // caso 3
        child->pai->cor = true;
        child->pai->pai->cor = false;
        rotacaoSimplesDireitaRB(raiz, child->pai->pai);
      }
    }
    else
    {

      tio = child->pai->pai->FE;

      // caso 1
      if ((tio != nullptr) && (tio->cor == false))
      {
        child->pai->cor = true;
        tio->cor = true;
        child->pai->pai->cor = false;
        child = child->pai->pai;
      }
      else
      {

        // caso 2
        if (child == child->pai->FE)
        {
          child = child->pai;
          rotacaoSimplesDireitaRB(raiz, child);
        }

        // caso 3
        child->pai->cor = true;
        child->pai->pai->cor = false;
        rotacaoSimplesEsquerdaRB(raiz, child->pai->pai);
      }
    }
  }

  (*raiz)->cor = true;
}

void insertRB(RedBlack **t, RedBlack **pai, RedBlack **raiz, Record r)
{

  if (*t == nullptr)
  {
    *t = new RedBlack;
    (*t)->FE = nullptr;
    (*t)->FD = nullptr;
    (*t)->pai = pai != t ? *pai : nullptr;
    (*t)->cor = false; // false: vermelho  true:preto
    (*t)->item = r;
    insertFixUp(raiz, *t);
  }
  else
  {

    if (r.key < (*t)->item.key)
    {
      insertRB(&(*t)->FE, t, raiz, r);
      return;
    }

    if (r.key > (*t)->item.key)
    {
      insertRB(&(*t)->FD, t, raiz, r);
      return;
    }
  }
}

void rotacaoSimplesEsquerdaRB(RedBlack **raiz, RedBlack *child)
{
    RedBlack *x, *y;

  x = child;
  y = child->FD;
  x->FD = y->FE;

  if (y->FE != nullptr)
    y->FE->pai = x;

  y->pai = x->pai;

  if (x->pai == nullptr)
    *raiz = y;

  else
  {

    if (x == x->pai->FE)
      x->pai->FE = y;

    else
      x->pai->FD = y;
  }

  y->FE = x;
  x->pai = y;
}

void rotacaoSimplesDireitaRB(RedBlack **raiz, RedBlack *child)
{
  RedBlack *x, *y;

  x = child;
  y = child->FE;
  x->FE = y->FD;

  if (y->FD != nullptr)
    y->FD->pai = x;

  y->pai = x->pai;

  if (x->pai == nullptr)
  {
    *raiz = y;
  }

  else
  {

    if (x == x->pai->FD)
      x->pai->FD = y;

    else
      x->pai->FE = y;
  }

  y->FD = x;
  x->pai = y;
}

void PrintRBPreOrder(RedBlack *t)
{
  if (!(t == nullptr))
  {
    printf("%.2f - %s\t", t->item.key, t->cor ? "black" : "red");
    PrintRBPreOrder(t->FE);
    PrintRBPreOrder(t->FD);
  }
}

void PrintRBInOrder(RedBlack *t)
{
  if (!(t == nullptr))
  {
    PrintRBInOrder(t->FE);
    printf("%.2f - %s\t", t->item.key, t->cor ? "black" : "red");
    PrintRBInOrder(t->FD);
  }
}

void PrintRBPosOrder(RedBlack *t)
{
  if (!(t == nullptr))
  {
    PrintRBPosOrder(t->FE);
    PrintRBPosOrder(t->FD);
    printf("%.2f - %s\t", t->item.key, t->cor ? "black" : "red");
  }
}

void PrintInRangeRB(RedBlack **T){
  if ((*T)!=nullptr)
  {
    queue<RedBlack*> tempFila;
    RedBlack *temp;
    int tempCont=1,cont=0;
    tempFila.push((*T));
    while (!(tempFila.empty())){
      cont=0;
      for (int i = 0; i < tempCont; i++){
        temp =tempFila.front();
        printf("%.2f - %s\t",temp->item.key, temp->cor ? "black" : "red");
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

void deleteRB(RedBlack **T, RedBlack *valor){
  RedBlack *y=valor;
  RedBlack *x;
  bool corOriginal=y->cor;
  if (valor->FE==nullptr){
    x=valor->FD;
    if (x==nullptr){
      x=new RedBlack;
      x->item.key=404;
      x->cor=true;
      valor->FD=x;
    }
    RBTransplant(T,valor,valor->FD);
    x->pai=valor->pai;
  }
  else if(valor->FD==nullptr){
    x=valor->FE;
    if (x==nullptr){
      x=new RedBlack;
      x->item.key=404;
      x->cor=true;
      valor->FE=x;
    }
    RBTransplant(T,valor,valor->FE);
    x->pai=valor->pai;
  }
  else{
    y=TreeMinimun(&valor->FE);
    corOriginal=y->cor;
    x=y->FE;
    if (x==nullptr){
      x=new RedBlack;
      x->pai=y;
      x->item.key=404;
      x->cor=true;
      y->FE=x;
    }
    if (y->pai==valor){
      x->pai=y;
    }
    else{
      RBTransplant(T,y,y->FE);
      y->FE=valor->FE;
      y->FE->pai=y;
    }
    RBTransplant(T,valor,y);
    y->FD=valor->FD;
    y->FD->pai=y;
    y->cor=valor->cor;
  }
  RedBlack *aux=x;
  if (corOriginal)
    RBDeleteFixup(T,x);
  if (aux->item.key==404){
    if (aux==aux->pai->FE)
      aux->pai->FE=nullptr;
    else
      aux->pai->FD=nullptr;
    delete aux;
  }
  delete valor;
}

void RBTransplant(RedBlack **T, RedBlack *valor, RedBlack *sucessor){
  if (valor->pai==nullptr)
    (*T)=sucessor;
  else if(valor==valor->pai->FE)
    valor->pai->FE=sucessor;
  else
    valor->pai->FD=sucessor;
  sucessor->pai=valor->pai;
}

void removeRB(RedBlack **raiz,RedBlack **t, Record r){
  if (*t == nullptr){ 
    return;
  }

  if (r.key < (*t)->item.key){ removeRB(raiz, &(*t)->FE, r); return; }
  if (r.key > (*t)->item.key){ removeRB(raiz, &(*t)->FD, r); return; }

  if ((*raiz)->FD==nullptr && (*raiz)->FE==nullptr){delete (*raiz);(*raiz)=nullptr;return;}

  deleteRB(raiz,(*t));
  
}

RedBlack *TreeMinimun(RedBlack **t){
  if ((*t)->FD != nullptr){
    return TreeMinimun(&(*t)->FD);
  }
  else{
    return (*t);
  }
  return nullptr;
} 

void RBDeleteFixup(RedBlack **T, RedBlack *x){
  while (x!=(*T)&&x->cor){
    if (x==x->pai->FE){
      RedBlack* w=x->pai->FD;
      if (w!=nullptr){
        if (!w->cor){
          w->cor=true;
          x->pai->cor=false;
          rotacaoSimplesEsquerdaRB(T,x->pai);
          w=x->pai->FD;
        }
        if ((w->FD==nullptr||w->FD->cor)&&(w->FE==nullptr||w->FE->cor)){
          w->cor=false;
          x=x->pai;
        }
        else if(w->FD==nullptr||w->FD->cor){
          w->FE->cor=true;
          w->cor=false;
          rotacaoSimplesDireitaRB(T,w);
          w=x->pai->FD;
        }
        if(w->FD!=nullptr&&!w->FD->cor){
          w->cor=x->pai->cor;
          x->pai->cor=true;
          w->FD->cor=true;
          rotacaoSimplesEsquerdaRB(T,x->pai);
          x=(*T);
        }
      }
      else
        x=x->pai;
    }
    else{
      RedBlack* w=x->pai->FE;
      if (w!=nullptr){
        if (!w->cor){
          w->cor=true;
          x->pai->cor=false;
          rotacaoSimplesDireitaRB(T,x->pai);
          w=x->pai->FE;
        }
        if ((w->FD==nullptr||w->FD->cor)&&(w->FE==nullptr||w->FE->cor)){
          if(w)
            w->cor=false;
          x=x->pai;
        }
        else if(w->FE==nullptr||w->FE->cor){
          w->FD->cor=true;
          w->cor=false;
          rotacaoSimplesEsquerdaRB(T,w);
          w=x->pai->FE;
        }
        if(w->FE!=nullptr&&!w->FE->cor){
          w->cor=x->pai->cor;
          x->pai->cor=true;
          w->FE->cor=true;
          rotacaoSimplesDireitaRB(T,x->pai);
          x=(*T);
        }
      }
      else
        x=x->pai;
    }
  }
  x->cor=true;  
}

long insercaoRB(RedBlack **Raiz,vector<double> numeros,int x){
	Record r;
	auto t = clock();
	for(int i=0; i<x; i++){
		r.key = numeros[i];
		insertRB(Raiz,Raiz,Raiz,r);
	}
	auto duration = clock() - t;
	return duration;
}
long remocaoRB(RedBlack **Raiz,vector<double> busca){
	Record r;
	auto t = clock();
	for (long unsigned int i = 0; i < busca.size(); i++){
		r.key=busca[i];			
		removeRB(Raiz,Raiz,r);
	}
	auto duration = clock() - t;
	return duration;
}