#include "rand.hpp"

void randomize(){
    ofstream myfile ("files/rand500000.txt");
    float number;
    srand (static_cast <unsigned> (time(0)));
    if (myfile.is_open())
    {
        for (int i = 0; i < 500000; i++)
        {
            number = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.0F));
            myfile << number;
            myfile << "\n";
        }
    }
    myfile.close();
}

void arquivos(){
    ifstream myfile ("files/rand500000.txt");
    ofstream cinquenta ("files/rand50000.txt");
    ofstream cinco ("files/rand5000.txt");
    ofstream quinhentos ("files/rand500.txt");
    float number;
    if (myfile.is_open())
    {
        for (int i = 0; i < 40000; i++)
            myfile.ignore(50,'\n');
        for (int i = 0; i < 50000; i++){
            myfile >> number;
            cinquenta << number;
            cinquenta << "\n";
        }
    }
    myfile.close();
    myfile.open("files/rand500000.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < 37500; i++)
            myfile.ignore(50,'\n');
        for (int i = 0; i < 5000; i++){
            myfile >> number;
            cinco << number;
            cinco << "\n";
        }
    }
    myfile.close();
    myfile.open("files/rand500000.txt");
    if (myfile.is_open())
    {
        for (int i = 0; i < 37250; i++)
            myfile.ignore(50,'\n');
        for (int i = 0; i < 500; i++){
            myfile >> number;
            quinhentos << number;
            quinhentos << "\n";
        }
    }
    myfile.close();
}

void shuffleSearch(){
    ifstream arqbusca("files/search.txt");
	vector<double> numeros;
    double numero;
	for(int i=0; i<10000; i++){
		arqbusca>>numero;
		numeros.push_back(numero);
	}
    arqbusca.close();
    auto rng = default_random_engine {};
    shuffle(begin(numeros), end(numeros), rng);
    ofstream arqbuscaof("files/search.txt");
	for(size_t i=0; i<numeros.size(); i++)
        arqbuscaof<<numeros[i];
    arqbuscaof.close();
}