#include "vetor_map.hpp"

long insercaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> numeros,int x){
	Record r;
	auto t = clock();
	for(int i=0; i<x; i++){
		r.key = numeros[i];
		(*hash)[r.key]=r;
	}
	auto duration = clock() - t;
	return duration;
}

long buscaUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca){
	Record r;
	auto t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
		r.key = busca[i];
		if((*hash).find(r.key)==(*hash).end())
            printf("%d\n",-1);
        else
            printf("%.5f\n",r.key);
	}
	auto duration = clock() - t;
	return duration;
}

long remocaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca){
	auto t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
		(*hash).erase(busca[i]);
	}
	auto duration = clock() - t;
	return duration;
}

long insercaoVetor(vector<double> *vetor,vector<double> numeros){
	auto t = clock();
    *vetor=numeros;
    sort((*vetor).begin(),(*vetor).end());
	auto duration = clock() - t;
	return duration;
}

long buscaVetor(vector<double> *vetor,vector<double> busca){
	auto t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        if ( find((*vetor).begin(), (*vetor).end(), busca[i]) == (*vetor).end() )
            printf("%d\n",-1);
        else
            printf("%.5f\n",busca[i]);
	}
	auto duration = clock() - t;
	return duration;
}

long remocaoVetor(vector<double> *vetor,vector<double> busca){
	auto t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        auto iterator= find((*vetor).begin(), (*vetor).end(), busca[i]);
        if ( iterator != (*vetor).end() )
            (*vetor).erase(iterator);
	}
	auto duration = clock() - t;
	return duration;
}

long insercaoMap(map<double, Record> *map,vector<double> numeros,int x){
	Record r;
	auto t = clock();
	for(int i=0; i<x; i++){
        r.key=numeros[i];
		(*map).insert(pair<double,Record>(r.key,r));
	}
	auto duration = clock() - t;
	return duration;
}

long buscaMap(map<double, Record> *map,vector<double> busca){
	Record r;
	auto t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        r.key=busca[i];
		if((*map).find(r.key)==(*map).end())
            printf("%d\n",-1);
        else
            printf("%.5f\n",r.key);
	}
	auto duration = clock() - t;
	return duration;
}

long remocaoMap(map<double, Record> *map,vector<double> busca){
	Record r;
	auto t = clock();
	for(long unsigned int i=0; i<busca.size(); i++){
        r.key=busca[i];
        auto iterator =(*map).find(r.key);
		if(iterator!=(*map).end())
            (*map).erase(iterator);
	}
	auto duration = clock() - t;
	return duration;
}