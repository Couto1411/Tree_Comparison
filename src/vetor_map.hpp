#ifndef vector_map
#define vector_map

#include <algorithm> 
#include <unordered_map>
#include <map>
#include "base.hpp"

long insercaoUnorderedMap(unordered_map<double,Record> *hash,vector<double> numeros, int x);
long buscaUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca);
long remocaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca);

long insercaoVetor(vector<double> *vetor,vector<double> numeros);
long buscaVetor(vector<double> *vetor,vector<double> busca);
long remocaoVetor(vector<double> *vetor,vector<double> busca);

long insercaoMap(map<double,Record> *map,vector<double> numeros, int x);
long buscaMap(map<double, Record> *map,vector<double> busca);
long remocaoMap(map<double, Record> *map,vector<double> busca);

#endif
