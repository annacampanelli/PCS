#include <vector>
#include <string>
#include "sort.hpp"
#include "randfiller.h"
using namespace std;

int main(){
    randfiller rf; 
    vector <int> dim; //creo vettore dimensione di dimensione 0
    dim.resize(100);//esapando dimensione di vettore dimensione mette tutti 0
    rf.fill(dim,0,1000); //riempo vettore dimensioni
    for (int t=0; t<100; t++) {//100 vettori
        vector <int> vet; 
        vet.resize(dim[t]); 
        rf.fill(vet,-100,100); //scelgo io per avere anche valori negativi
        insertion_sort(vet);
        if (is_sorted(vet)==false){
            return EXIT_FAILURE;
        }
    }

    vector <string> vet_string={"anna","lucrezia","tommaso","andrea","francesco","celeste", "chiara", "giulia", "giulio","karim","lorenzo", 
                         "maddalena","massimiliano" ,"mattia", "filippo"};
    insertion_sort(vet_string);
    if (is_sorted(vet_string)==false){
         return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

