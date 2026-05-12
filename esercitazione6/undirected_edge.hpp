#pragma once
#include <iostream>
#include <concepts>

template<typename T> 
class undirected_edge { 
private: 

    T from_; //nic di mettere _from
    T to_;

    void ordina(){
        if (from_>to_){
            std::swap(from_,to_);
        }
}

public:
//costruttore di default
    undirected_edge()
        : from_(0),to_(1)
    {}

//costruttore user-defined
    undirected_edge(const T& nodo1, const T& nodo2)
        : from_(nodo1),to_(nodo2)
        {ordina();}

    T from() const {return from_;} 
    T to() const {return to_;}
            
    
    //operatori

    bool operator<(const undirected_edge& other)const{
        if (from_<other.from_ ||(from_==other.from_ && to_<other.to_)){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator==(const undirected_edge& other)const {
        if(from_==other.from_ && to_==other.to_){
            return true;
        }
        else{
            return false;
        }

    }
};
 
template <typename T>
std :: ostream&
operator<<(std::ostream& os, const undirected_edge <T>& arco)
{
    os<<arco.from()<<"--"<<arco.to();
    return os;
}