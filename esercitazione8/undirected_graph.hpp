#pragma once    
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include "undirected_edge.hpp"

template<typename T>    
class grafo { 
private:
    std:: map <T, std::set<T>> la; //mappa chiave valore (nodo set dei vicini) -> lista adiacenza
public:
    //default
    grafo()=default;
    //copia
    grafo(const grafo& other)=default; //come dire la(other.la)


    //neighbours
    std::vector<T> neighbours(const T& nodo) const {
      const auto it = la.find(nodo);
      if (it == la.end())
        return {};
      else
        return std::vector<T>(it->second.begin(), it->second.end()); //come sempre primo compreso secondo esclusso
    }


    //add_edge 
    void add_edge(const undirected_edge<T>& nuovo_arco){       
        la[nuovo_arco.from()].insert(nuovo_arco.to()); //nel caso in cui la chiave non ci fosse [] la crea
        if (nuovo_arco.to() != nuovo_arco.from())
          la[nuovo_arco.to()].insert(nuovo_arco.from());
    }

    //all_edges
    std::vector<undirected_edge<T>> all_edges() const {
        std::vector<undirected_edge<T>> archi;
        for (auto it1 = la.begin(); it1 != la.end(); ++it1) { //scorro elementi della mappa
          for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) { //per ogni coppia chiave valore scorro sui valori
            if (*it2 >= it1->first) {  // se elemento del set è maggiore della chiave inserisce l'arco, (coì da inserire 1--2 ma non 2--1)
              undirected_edge<T> arco(it1->first, *it2);  // it1->first = node, *it2 = neighbor
              archi.push_back(arco);
            }
          }
        }
        return archi;
    }

    //all_nodes
    std::vector<T> all_nodes() const{
        std::vector<T> nodi;
        for (const auto& [key,value]: la){
            nodi.push_back(key);
        }
        return nodi;
    }

    //edge_number()
    int edge_number(undirected_edge<T> arco) const{
        auto archi=all_edges();
        for (int k=0; k<(int)archi.size(); k++){
            if(archi[k]==arco){
                return k; //numerazione archi parte da 0
            }
        }
        return -1; //se l'arco non è presente
    }
    
    //edge_at()
    undirected_edge<T> edge_at(int posizione) const{
        auto archi=all_edges();
        return archi[posizione]; //se arco assente mi da 0--0
    }

    //G1-G2 --> deve darmi gli archi presenti in G1 ma non in G2
    std::vector<undirected_edge<T>> operator-(const grafo<T>& other) const {
        auto archi_g1  = all_edges();
        auto archi_g2 = other.all_edges();

        std::vector<undirected_edge<T>> differenza;
        std::set_difference(archi_g1.begin(), archi_g1.end(), archi_g2.begin(), archi_g2.end(), std::inserter(differenza, differenza.begin()));
        return differenza;
    }
};