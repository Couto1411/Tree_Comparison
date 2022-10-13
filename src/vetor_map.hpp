#ifndef vector_map
#define vector_map

#include <algorithm> 
#include <unordered_map>
#include <map>
#include "base.hpp"

float insercaoUnorderedMap(unordered_map<double,Record> *hash,vector<double> numeros, int x);
float buscaUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca);
float remocaoUnorderedMap(unordered_map<double, Record> *hash,vector<double> busca);

float insercaoVetor(vector<double> *vetor,vector<double> numeros);
float buscaVetor(vector<double> *vetor,vector<double> busca);
float remocaoVetor(vector<double> *vetor,vector<double> busca);

float insercaoMap(map<double,Record> *map,vector<double> numeros, int x);
float buscaMap(map<double, Record> *map,vector<double> busca);
float remocaoMap(map<double, Record> *map,vector<double> busca);

#endif
