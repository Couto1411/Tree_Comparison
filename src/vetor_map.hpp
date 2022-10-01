#ifndef vector_map
#define vector_map

#include <algorithm> 
#include <unordered_map>
#include <map>
#include "base.hpp"

long long insercaoUnorderedMap(unordered_map<double,Record> *hash,vector<double> numeros, int x);
long long buscaUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca);
long long remocaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca);

long long insercaoVetor(vector<double> *vetor,vector<double> numeros);
long long buscaVetor(vector<double> *vetor,vector<double> busca);
long long remocaoVetor(vector<double> *vetor,vector<double> busca);

long long insercaoMap(map<double,Record> *map,vector<double> numeros, int x);
long long buscaMap(map<double, Record> *map,vector<double> busca);
long long remocaoMap(map<double, Record> *map,vector<double> busca);

#endif
