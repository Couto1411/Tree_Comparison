#include "vetor_map.hpp"

float insercaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> numeros,int x){
	Record r;
	size_t t = clock();
	for(int i=0; i<x; i++){
		r.key = numeros[i];
		(*hash)[r.key]=r;
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float buscaUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca){
	Record r;
	size_t t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
		r.key = busca[i];
		if((*hash).find(r.key)==(*hash).end())
            printf("%d\n",-1);
        else
            printf("%.5f\n",r.key);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float remocaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca){
	size_t t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
		(*hash).erase(busca[i]);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float insercaoVetor(vector<double> *vetor,vector<double> numeros){
	size_t t = clock();
	(*vetor)=numeros;
	Quicksort sort((*vetor));
    sort.Sort();
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float buscaVetor(vector<double> *vetor,vector<double> busca){
	size_t t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        if (binary_search((*vetor).begin(), (*vetor).end(), busca[i]))
            printf("%d\n",-1);
        else
            printf("%.5f\n",busca[i]);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float remocaoVetor(vector<double> *vetor,vector<double> busca){
	size_t t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        auto iterator= find((*vetor).begin(), (*vetor).end(), busca[i]);
        if ( iterator != (*vetor).end() )
            (*vetor).erase(iterator);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float insercaoMap(map<double, Record> *map,vector<double> numeros,int x){
	Record r;
	size_t t = clock();
	for(int i=0; i<x; i++){
        r.key=numeros[i];
		(*map).insert(pair<double,Record>(r.key,r));
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float buscaMap(map<double, Record> *map,vector<double> busca){
	Record r;
	size_t t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        r.key=busca[i];
		if((*map).find(r.key)==(*map).end())
            printf("%d\n",-1);
        else
            printf("%.5f\n",r.key);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}

float remocaoMap(map<double, Record> *map,vector<double> busca){
	Record r;
	size_t t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        r.key=busca[i];
        auto iterator =(*map).find(r.key);
		if(iterator!=(*map).end())
            (*map).erase(iterator);
	}
	t = clock() - t;
	return (float(t)/CLOCKS_PER_SEC);
}