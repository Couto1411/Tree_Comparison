#include "rb.hpp"
#include "avl.hpp"
#include "tree.hpp"
#include "vetor_map.hpp"
// #include "rand.hpp"

int main(){

	// // Inicializacao de arquivos
	// void randomize();
	// void arquivos();
	// void shuffleSearch();

	double numero;
	Tempos avlTree,binaryTree,redblackTree, unorderedMap, Map, Vetor;
	vector<double> numeros;
	vector<double> busca;
	RedBlack *redblack; Avl *avl; Tree *binary;
	unordered_map<double,Record> hash; map<double,Record> map; vector<double> vetor;
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

		// insercao Vetor
		Vetor.Insert.push_back(insercaoVetor(&vetor,numeros));
		// pesquisa Vetor
		Vetor.Search.push_back(buscaVetor(&vetor,busca));
		// remocao Vetor
		Vetor.Remove.push_back(remocaoVetor(&vetor,busca));
		
		// insercao Hash
		unorderedMap.Insert.push_back(insercaoUnorderedMap(&hash,numeros,x));
		// pesquisa Hash
		unorderedMap.Search.push_back(buscaUnorderedMap(&hash,busca));
		// remocao Hash
		unorderedMap.Remove.push_back(remocaoUnorderedMap(&hash,busca));
		
		// insercao Map
		Map.Insert.push_back(insercaoMap(&map,numeros,x));
		// pesquisa Map
		Map.Search.push_back(buscaMap(&map,busca));
		// remocao Map
		Map.Remove.push_back(remocaoMap(&map,busca));



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
	cout<<endl<<endl;
	
	cout<< "Tempos Vetor:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < Vetor.Insert.size(); i++)
		cout<< Vetor.Insert[i]<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < Vetor.Search.size(); i++)
		cout<< Vetor.Search[i]<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < Vetor.Remove.size(); i++)
		cout<< Vetor.Remove[i]<< " ";
	cout<<endl<<endl;
	
	cout<< "Tempos Hash:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < unorderedMap.Insert.size(); i++)
		cout<< unorderedMap.Insert[i]<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < unorderedMap.Search.size(); i++)
		cout<< unorderedMap.Search[i]<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < unorderedMap.Remove.size(); i++)
		cout<< unorderedMap.Remove[i]<< " ";
	cout<<endl<<endl;
	
	cout<< "Tempos Map:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < Map.Insert.size(); i++)
		cout<< Map.Insert[i]<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < Map.Search.size(); i++)
		cout<< Map.Search[i]<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < Map.Remove.size(); i++)
		cout<< Map.Remove[i]<< " ";
}