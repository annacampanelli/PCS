#include <iostream>
#include "rational.hpp"
using namespace std;

int main(){

    int num1, den1, num2, den2; 

    cout<<"Inserire prima frazione \n";
    cout<< "numeratore: ";
    cin >> num1;

    cout<< "\ndenominatore: ";
    cin >> den1;

    cout <<"\nInserire seconda frazione \n";
    cout<< "numeratore: ";
    cin >> num2;

    cout<< "\ndenominatore: ";
    cin >> den2;
    cout<<"\n";

    rational <int> r1(num1,den1);
    rational <int> r2(num2,den2);
    cout<< "La prima frazione è: "<< r1 << "\n";
    cout<< "La seconda frazione è: "<< r2  << "\n";

    rational <int> somma = r1 + r2;
    rational <int> differenza = r1 - r2;
    rational <int> prodotto = r1 * r2;
    rational <int> divisione = r1 / r2;
    cout<< "(" << r1 << ") + (" << r2 <<") = " << somma<<"\n";
    cout<< "(" << r1 << ") - (" << r2 <<") = " << differenza<<"\n";
    cout<< "(" << r1 << ") * (" << r2 <<") = " << prodotto<<"\n";
    cout<< "(" << r1 << ") / ("<< r2 <<") = " << divisione<<"\n";
}