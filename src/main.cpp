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
	int x=50,qtd=100;
	ifstream arqbusca,myfile;
	arqbusca.open("files/search.txt",ios::in);
	for(int i=0; i<10000; i++){
		arqbusca>>numero;
		busca.push_back(numero);
	}
	arqbusca.close();
	for (int j = 0; j < qtd; j++)
	{
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
			binaryTree.Insert[i]+=(insercaoTree(&binary,numeros,x));
			// pesquisa Binaria
			binaryTree.Search[i]+=(timedSearch(&binary,busca));
			// remocao Binaria
			binaryTree.Remove[i]+=(remocaoTree(&binary,busca));
			
			// insercao AVL
			avlTree.Insert[i]+=(insercaoAvl(&avl,numeros,x));
			// pesquisa AVL
			avlTree.Search[i]+=(timedSearch(&avl,busca));
			// remocao AVL
			avlTree.Remove[i]+=(remocaoAvl(&avl,busca));
			
			// insercao RB
			redblackTree.Insert[i]+=(insercaoRB(&redblack,numeros,x));
			// pesquisa RB
			redblackTree.Search[i]+=(timedSearch(&redblack,busca));
			// remocao RB
			redblackTree.Remove[i]+=(remocaoRB(&redblack,busca));

			// insercao Vetor
			Vetor.Insert[i]+=(insercaoVetor(&vetor,numeros));
			// pesquisa Vetor
			Vetor.Search[i]+=(buscaVetor(&vetor,busca));
			// remocao Vetor
			Vetor.Remove[i]+=(remocaoVetor(&vetor,busca));
			
			// insercao Hash
			unorderedMap.Insert[i]+=(insercaoUnorderedMap(&hash,numeros,x));
			// pesquisa Hash
			unorderedMap.Search[i]+=(buscaUnorderedMap(&hash,busca));
			// remocao Hash
			unorderedMap.Remove[i]+=(remocaoUnorderedMap(&hash,busca));
			
			// insercao Map
			Map.Insert[i]+=(insercaoMap(&map,numeros,x));
			// pesquisa Map
			Map.Search[i]+=(buscaMap(&map,busca));
			// remocao Map
			Map.Remove[i]+=(remocaoMap(&map,busca));

			numeros.clear();
		}
		x=50;
	}
	cout<< "Tempos Binary Tree:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < binaryTree.Insert.size(); i++)
		cout<< (binaryTree.Insert[i]/qtd)<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < binaryTree.Search.size(); i++)
		cout<< (binaryTree.Search[i]/qtd)<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < binaryTree.Remove.size(); i++)
		cout<< (binaryTree.Remove[i]/qtd)<< " ";
	cout<<endl<<endl;

	cout<< "Tempos AVL Tree:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < avlTree.Insert.size(); i++)
		cout<< (avlTree.Insert[i]/qtd)<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < avlTree.Search.size(); i++)
		cout<< (avlTree.Search[i]/qtd)<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < avlTree.Remove.size(); i++)
		cout<< (avlTree.Remove[i]/qtd)<< " ";
	cout<<endl<<endl;
	
	cout<< "Tempos Redblack Tree:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < redblackTree.Insert.size(); i++)
		cout<< (redblackTree.Insert[i]/qtd)<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < redblackTree.Search.size(); i++)
		cout<< (redblackTree.Search[i]/qtd)<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < redblackTree.Remove.size(); i++)
		cout<< (redblackTree.Remove[i]/qtd)<< " ";
	cout<<endl<<endl;
	
	cout<< "Tempos Vetor:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < Vetor.Insert.size(); i++)
		cout<< (Vetor.Insert[i]/qtd)<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < Vetor.Search.size(); i++)
		cout<< (Vetor.Search[i]/qtd)<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < Vetor.Remove.size(); i++)
		cout<< (Vetor.Remove[i]/qtd)<< " ";
	cout<<endl<<endl;
	
	cout<< "Tempos Hash:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < unorderedMap.Insert.size(); i++)
		cout<< (unorderedMap.Insert[i]/qtd)<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < unorderedMap.Search.size(); i++)
		cout<< (unorderedMap.Search[i]/qtd)<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < unorderedMap.Remove.size(); i++)
		cout<< (unorderedMap.Remove[i]/qtd)<< " ";
	cout<<endl<<endl;
	
	cout<< "Tempos Map:"<<endl<< "Insertion: ";
	for (size_t i = 0; i < Map.Insert.size(); i++)
		cout<< (Map.Insert[i]/qtd)<< " ";
	cout<< endl << "Search: ";
	for (size_t i = 0; i < Map.Search.size(); i++)
		cout<< (Map.Search[i]/qtd)<< " ";
	cout<< endl << "Removal: ";
	for (size_t i = 0; i < Map.Remove.size(); i++)
		cout<< (Map.Remove[i]/qtd)<< " ";


}