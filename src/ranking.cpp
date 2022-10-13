#include "ranking.hpp"
bool compare(const pair<string,float> &a,const pair<string,float> &b){
	return a.second<b.second;
}

void ranking(Tempos binaryTree,Tempos avlTree,Tempos redblackTree,Tempos Vetor,Tempos unorderedMap,Tempos Map, int grandeza, int metodo){
	vector<pair<string,float>> rank;
	pair<string,float> par;
	if (metodo==1){
		rank.push_back(make_pair("Binary",binaryTree.Insert[grandeza]));
		rank.push_back(make_pair("Avl",avlTree.Insert[grandeza]));
		rank.push_back(make_pair("RedBlack",redblackTree.Insert[grandeza]));
		rank.push_back(make_pair("Vector",Vetor.Insert[grandeza]));
		rank.push_back(make_pair("Unordered_Map",unorderedMap.Insert[grandeza]));
		rank.push_back(make_pair("Map",Map.Insert[grandeza]));
	}else if (metodo==2){
		rank.push_back(make_pair("Binary",binaryTree.Search[grandeza]));
		rank.push_back(make_pair("Avl",avlTree.Search[grandeza]));
		rank.push_back(make_pair("RedBlack",redblackTree.Search[grandeza]));
		rank.push_back(make_pair("Vector",Vetor.Search[grandeza]));
		rank.push_back(make_pair("Unordered_Map",unorderedMap.Search[grandeza]));
		rank.push_back(make_pair("Map",Map.Search[grandeza]));
	}else{
		rank.push_back(make_pair("Binary",binaryTree.Remove[grandeza]));
		rank.push_back(make_pair("Avl",avlTree.Remove[grandeza]));
		rank.push_back(make_pair("RedBlack",redblackTree.Remove[grandeza]));
		rank.push_back(make_pair("Vector",Vetor.Remove[grandeza]));
		rank.push_back(make_pair("Unordered_Map",unorderedMap.Remove[grandeza]));
		rank.push_back(make_pair("Map",Map.Remove[grandeza]));
	}
	sort(rank.begin(),rank.end(),compare);
	for (int i = 0; i < 6; i++)
		cout<<i+1<<":"<<rank[i].first<<endl;
}