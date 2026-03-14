#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{
	if (argc==1) { // poichè se non ho inserito il file ho solo un argomento 
		cout <<" C'è un errore: non hai inserito il nome del file \n";
	return 1;// ret 0 tutto è andato bene, altrimenti nonzero
	}	
	string filename (argv[1]);
	ifstream ifs(filename);
	if (ifs.is_open()) {
		for (int k=0; k<=2; k++){ //inizializzazione, condizione,incremento k++ -> k=k+1
			string citta; 
			double t1,t2,t3,t4;
			ifs >> citta >> t1 >> t2 >> t3 >> t4; 
			double media = (t1+t2+t3+t4)/4;
			cout << "La temperatura media a " << citta << " è "<< media<< "\n";	
		}
		
	return 0; 
	}
	else { cout <<"Il file non è stato correttamente aperto \n";
	return 1; 	
	}

}
