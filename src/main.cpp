#include "rb.hpp"
#include "avl.hpp"
#include "tree.hpp"
#include "vetor_map.hpp"
#include "ranking.hpp"
// #include "rand.hpp"

int main(){

	// // Inicializacao de arquivos
	// void randomize();
	// void arquivos();
	// void shuffleSearch();

	double numero;
	Tempos avlTree,binaryTree,redblackTree, unorderedMap, Map, Vetor;
	vector<double> numeros, busca;
	RedBlack *redblack; Avl *avl; Binary *binary;
	unordered_map<double,Record> hash; map<double,Record> map; vector<double> vetor;
	int x=50,qtd=1,temp,temp2;
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
	while (true){
		cout<< "\nOpções:\n1) Print tempos\n2) Print rankings\n0) Exit"<<endl;
		cin>>temp;
		if(temp==1){
			cout<< "1) Binary Tree\n2) AVL Tree\n3) RedBlack Tree\n4) Ordered Vector\n5) Unordered Map\n6) Map\n0) Exit"<<endl;
			cin>>temp;
			switch (temp)
			{
			case 1:
				printTempos(binaryTree, qtd,"Binary");
				break;
			case 2:
				printTempos(avlTree, qtd,"AVL");
				break;
			case 3:
				printTempos(redblackTree, qtd,"RedBlack");
				break;
			case 4:
				printTempos(Vetor, qtd,"Vector");
				break;
			case 5:
				printTempos(unorderedMap, qtd,"Unordered Map");
				break;
			case 6:
				printTempos(Map, qtd,"Map");
				break;
			default:
				break;
			}
		}
		else if (temp==2){
			cout<< "1) Tempo de inserção\n2) Tempo de busca\n3) Tempo de remoção"<<endl;
			cin>>temp;
			cout<< "1) 500\n2) 5000\n3) 50000\n4)500000"<<endl;
			cin>>temp2;
			ranking(binaryTree,avlTree,redblackTree,Vetor,unorderedMap,Map,(temp2-1),temp);		
		}else if (temp==0){
			break;
		}
	}
	exit(0);
}