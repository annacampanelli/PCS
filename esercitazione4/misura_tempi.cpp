#include <string>
#include <algorithm>    
#include <cmath> //per usare pow
#include "randfiller.h"
#include "timecounter.h"
#include "sort.hpp"
using namespace std;

int main(){
    timecounter tc;
    randfiller rf;
    for (int k=2; k<14; k++){ //creo vettori di dimensioni 4,8,16...8192 riempiti casualmente
        int dim = 1 << k;  // shiftando 1 di k ottengo potenza di 2.
        vector <int> vet;
        vet.resize(dim);
        rf.fill(vet,-100,100);
        // creo copie del vettore altrimenti dopo aver fatto il primo metodo di sort il vettore sarebbe già ordinato
        vector <int> v1=vet; //per selection
        vector <int> v2=vet; //per insertion
        vector <int> v3=vet; //per sort
        

        //tempo per bubble_sort
        tc.tic();
        bubble_sort(vet);
        double bubble_secs= tc.toc();
        string metodo_migliore="Bubble";
        double tempo_migliore=bubble_secs;

        //tempo per selection_sort
        tc.tic();
        selection_sort(v1);
        double sel_secs= tc.toc();
        if (sel_secs<tempo_migliore){
            metodo_migliore="Selection";
            tempo_migliore=sel_secs;
        }

        //tempo per insertion_sort
        tc.tic();
        insertion_sort(v2);
        double ins_secs= tc.toc();
        if (ins_secs<tempo_migliore){
            metodo_migliore="Insertion";
            tempo_migliore=ins_secs;
        }

        //tempo per sort 
        tc.tic();
        sort(v3.begin(),v3.end());
        double sort_secs= tc.toc();
        if (sort_secs<tempo_migliore){
            metodo_migliore="Sort";
            tempo_migliore=sort_secs;
        }
        cout<<"Dimensione: "<< dim << ", più veloce: "<< metodo_migliore <<  
        " - Bubble: "<< bubble_secs << " Insertion: "<< ins_secs  << " Selection: "<< sel_secs <<  " Sort: "<< sort_secs << " \n";

    }
    return 0;
}