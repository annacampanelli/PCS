#include <iostream>
#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include <string>

struct Output{
        std::string convergenza;
        int iter;
        Eigen::VectorXd sol;
        Eigen::VectorXd residuo;
};

Output cg(Eigen::MatrixXd& A,Eigen::VectorXd& b, const double r_tol, const unsigned int it_max){
    
    Eigen::VectorXd x=Eigen::VectorXd::Zero(b.size());
    Eigen::VectorXd res=b-A*x;
    Eigen::VectorXd p=res;
    const double res0_norm = res.norm();
    unsigned it=0; 
    while(it<it_max && res.norm() > r_tol * res0_norm){ //relativa
        const double alpha=(p.transpose()*res).value()/(p.transpose()*A*p).value();
        x=x+alpha*p;
        res=b-A*x;
        const double beta=(p.transpose()*A*res).value()/(p.transpose()*A*p).value();
        p=res-beta*p;
        it++;
    }
    std::string conv;
    if (it<it_max){
        conv="SI";
    }
    else{
        conv="NO";
    }
    struct Output s{.convergenza=conv, .iter=(int)it, .sol=x, .residuo=res};
    return s;
}
 