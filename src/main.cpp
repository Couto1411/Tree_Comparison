#include "rb.hpp"
#include "avl.hpp"
#include "tree.hpp"
// #include "rand.hpp"

int main(){

	// // Inicializacao de arquivos
	// void randomize();
	// void arquivos();
	// void shuffleSearch();

	double numero;
	Tempos avlTree,binaryTree,redblackTree;
	vector<double> numeros;
	vector<double> busca;
	RedBlack *redblack; Avl *avl; Tree *binary;
	int x=50;
	ifstream arqbusca,myfile;
	arqbusca.open("files/search.txt",ios::in);
	for(int i=0; i<10000; i++){
		arqbusca>>numero;
		busca.push_back(numero);
	}
	arqbusca.close();
	for (int i = 0; i < 4; i++)
	{
		CreateTree(&redblack);
		CreateTree(&avl);
		CreateTree(&binary);
		x=x*10;

		// leitura do arquivo 500/5000/50000/500000
		myfile.open("files/rand"+to_string(x)+".txt",ios::in);
		for(int i=0; i<x; i++){
			myfile>>numero;
			numeros.push_back(numero);
		}
		myfile.close();

		// insercao Binaria
		binaryTree.Insert.push_back(insercaoTree(&binary,numeros,x));
		// pesquisa Binaria
		binaryTree.Search.push_back(timedSearch(&binary,busca));
		// remocao Binaria
		binaryTree.Remove.push_back(remocaoTree(&binary,busca));
		
		// insercao AVL
		avlTree.Insert.push_back(insercaoAvl(&avl,numeros,x));
		// pesquisa AVL
		avlTree.Search.push_back(timedSearch(&avl,busca));
		// remocao AVL
		avlTree.Remove.push_back(remocaoAvl(&avl,busca));
		
		// insercao RB
		redblackTree.Insert.push_back(insercaoRB(&redblack,numeros,x));
		// pesquisa RB
		redblackTree.Search.push_back(timedSearch(&redblack,busca));
		// remocao RB
		redblackTree.Remove.push_back(remocaoRB(&redblack,busca));

		numeros.clear();
	}
	cout<< "Tempos Binary Tree:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < binaryTree.Insert.size(); i++)
		cout<< binaryTree.Insert[i]<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < binaryTree.Search.size(); i++)
		cout<< binaryTree.Search[i]<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < binaryTree.Remove.size(); i++)
		cout<< binaryTree.Remove[i]<< " ";
	cout<<endl<<endl;

	cout<< "Tempos AVL Tree:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < avlTree.Insert.size(); i++)
		cout<< avlTree.Insert[i]<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < avlTree.Search.size(); i++)
		cout<< avlTree.Search[i]<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < avlTree.Remove.size(); i++)
		cout<< avlTree.Remove[i]<< " ";
	cout<<endl<<endl;
	
	cout<< "Tempos Redblack Tree:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < redblackTree.Insert.size(); i++)
		cout<< redblackTree.Insert[i]<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < redblackTree.Search.size(); i++)
		cout<< redblackTree.Search[i]<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < redblackTree.Remove.size(); i++)
		cout<< redblackTree.Remove[i]<< " ";
}