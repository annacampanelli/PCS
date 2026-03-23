#include <iostream>

using namespace std;
int main()
{
	double ad[4]={0.0, 1.1, 2.2, 3.3}; //sizeof(double)=8
	float af[8]={0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7}; //sizeof(float)=4
	int ai[3]={0, 1, 2}; //sizeof(int)=4
	//stampa degli indirizzi degli elementi dell'array ad
	cout << "indirizzi elementi di ad:" << "\n";
	for (int i=0; i<=3; i++){
		cout << &ad[i] << "\n";
	}
	//stampa degli indirizzi degli elementi dell'array af
	cout << "indirizzi elementi di af:" << "\n";
	for (int i=0; i<=7; i++) {
		cout << &af[i] << "\n";
	}
	//stampa degli indirizzi degli elementi dell'array ai
	cout << "indirizzi elementi di ai:" << "\n";
	for (int i=0; i<=2; i++){
		cout << &ai[i] << "\n";
	}
	int x=1;
	//stampa degli indirizzi delle variabili scalari
	cout << "indirizzo x: ";
	cout << &x << "\n";
	float y=1.1;
	cout << "indirizzo y: " ;
	cout << &y << "\n";
	(&y)[1]=0; 
	cout << x << "\n";
	return 0;
}