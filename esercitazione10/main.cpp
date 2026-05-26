#include <iostream>
#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "cg.hpp"
#include <string>

int main(){
    const double tol=1.0e-15;
    const double r_tol=1.0e-7; 
    const unsigned int it_max=2000;
    std::cout<<"precisione sull'errore richiesta: "<<r_tol<<"\n\n";
    std::vector<int> vett_dim;
    for (int k=3; k<=10; k++){
        vett_dim.push_back(1<<k);//testo dimensioni 2^k
    }
    for (int n=0; n<(int)vett_dim.size();n++){
        Eigen::MatrixXd B=Eigen::MatrixXd::Random(vett_dim[n],vett_dim[n]);
        //controllo (fatto con prof Vicini) che matrice non abbia det=0 
        //if (abs(B.determinant())<tol) 
        //    return -1;

        //ho chiesto a claude consiglio su questo controllo: mi ha detto che fare in questo modo è numericamente instabile 
        //quindi mi ha consigliato di ragionare sul rango della matrice B, se rango pieno -> A non è singolare 
        //fullPivLu() calcola la fattorizzazione LU con pivoting completo della matrice.
        //Il rango si legge dagli elementi diagonali di U:quanti sono non-nulli (sopra una soglia numerica), 
        // quello è il rango. È numericamente stabile perché il pivoting completo — scegliere ad ogni passo 
        // il pivot più grande in tutta la sottomatrice rimanente — minimizza gli errori di arrotondamento.
        if (B.fullPivLu().rank() < vett_dim[n]) 
            return -1;
        Eigen::MatrixXd A=B.transpose()*B; //voglio simmetrica definita positiva
        Eigen::VectorXd x_ex=Eigen::VectorXd::Ones(vett_dim[n]);
        Eigen::VectorXd b=A*x_ex; //termine noto
        Output cg_output= cg(A,b, r_tol, it_max);
        std::cout<<"Dimensione matrice: "<<vett_dim[n]<<"\n";
        std::cout<< "Convergenza: " << cg_output.convergenza<<"\n";
        std::cout<< "Num iterazioni: " << cg_output.iter<<"\n";
        std::cout << "Norma residuo: " << cg_output.residuo.norm() << "\n";
        std::cout << "Errore soluzione: "   << (cg_output.sol - x_ex).norm() << "\n";
        std::cout<<"\n";
    }
}
