#include <iostream>
#include <algorithm> // per usare min e max
#include <cmath> // per usare sqrt
using namespace std;
int main()
{
    static const int N=13;
    double arr[N]={42.7, 5.3, 78.1, 19.6, 33.4, 87.9, 12.8, 64.2, 29.5, 71.0, 8.6, 5.1, 9.4};
    //faccio prova con array di lunghezza diversa e contente valori diveri
    //static const int N=10;
    //double arr[N]={3.7, 22.6, 87.5, 14.7, 1.1, 43.0, 36.3, 59.2, 28.5, 99.9};
    //static const int N=1;
    //double arr[N]={5.6};
    cout<< "Elementi dell'array: "; // stampo elementi a schermo, non utile se array molto lungo. 
    for (int k=0; k<N; k++){
        if (k<N-1){
            cout<< arr[k]<< ", ";
        }
        else{ 
            cout << arr[N-1] << "\n";
        }
    }
    //massimo e minimo
    double minimo=arr[0];
    double massimo=arr[0];
    for (int k=1; k<N; k++) {
        minimo=min(minimo,arr[k]);
        massimo=max(massimo,arr[k]);
    }
    //media
    double somma=0;
    for (int k=0; k<N; k++) {
        somma=somma+ arr[k];
    }
    double media=somma/N;
    // deviazione standard
    double varianza=0;
    for (int k=0; k<N; k++) {
        varianza=varianza +((arr[k]-media)*(arr[k]-media));
    }
    double dev_standard = sqrt((varianza)/N);
    //stampo a schermo risultati
    cout<<"Il valore minimo è: "<< minimo <<"\n";
    cout<<"Il valore massimo è: "<< massimo <<"\n";
    cout<<"Il valore medio è: "<< media <<"\n";
    cout<<"La deviazione standard è: "<< dev_standard<<"\n";
    return 0;
}