#include "vetor_map.hpp"

long long insercaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> numeros,int x){
	Record r;
	auto start = chrono::high_resolution_clock::now();
	for(int i=0; i<x; i++){
		r.key = numeros[i];
		(*hash)[r.key]=r;
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long buscaUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca){
	Record r;
	auto start = chrono::high_resolution_clock::now();
	for(long unsigned int i=0; i<busca.size(); i++){
		r.key = busca[i];
		if((*hash).find(r.key)==(*hash).end())
            printf("%d\n",-1);
        else
            printf("%.5f\n",r.key);
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long remocaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca){
	auto start = chrono::high_resolution_clock::now();
	for(long unsigned int i=0; i<busca.size(); i++){
		(*hash).erase(busca[i]);
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long insercaoVetor(vector<double> *vetor,vector<double> numeros){
	auto start = chrono::high_resolution_clock::now();
    *vetor=numeros;
    sort((*vetor).begin(),(*vetor).end());
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long buscaVetor(vector<double> *vetor,vector<double> busca){
	auto start = chrono::high_resolution_clock::now();
	for(long unsigned int i=0; i<busca.size(); i++){
        if ( find((*vetor).begin(), (*vetor).end(), busca[i]) == (*vetor).end() )
            printf("%d\n",-1);
        else
            printf("%.5f\n",busca[i]);
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long remocaoVetor(vector<double> *vetor,vector<double> busca){
	auto start = chrono::high_resolution_clock::now();
	for(long unsigned int i=0; i<busca.size(); i++){
        auto iterator= find((*vetor).begin(), (*vetor).end(), busca[i]);
        if ( iterator == (*vetor).end() )
            printf("%d\n",-1);
        else
            (*vetor).erase(iterator);
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long insercaoMap(map<double, Record> *map,vector<double> numeros,int x){
	Record r;
	auto start = chrono::high_resolution_clock::now();
	for(int i=0; i<x; i++){
        r.key=numeros[i];
		(*map).insert(pair<double,Record>(r.key,r));
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long buscaMap(map<double, Record> *map,vector<double> busca){
	Record r;
	auto start = chrono::high_resolution_clock::now();
	for(long unsigned int i=0; i<busca.size(); i++){
        r.key=busca[i];
		if((*map).find(r.key)==(*map).end())
            printf("%d\n",-1);
        else
            printf("%.5f\n",r.key);
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}

long long remocaoMap(map<double, Record> *map,vector<double> busca){
	Record r;
	auto start = chrono::high_resolution_clock::now();
	for(long unsigned int i=0; i<busca.size(); i++){
        r.key=busca[i];
        auto iterator =(*map).find(r.key);
		if(iterator!=(*map).end())
            (*map).erase(iterator);
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	return duration.count();
}