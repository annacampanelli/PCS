#pragma once
#include <list>
#include <fstream>
#include <string>
#include "graph.hpp"


//FIFO -> coda
template<typename T>    
class fifo {
    std::list<T> queue;
public:
    //default
    fifo()=default;

    //metodo empty()
    bool empty()const{
        return queue.empty();
    }

    //metodo put()
    void put(const T& nuovo){
        queue.push_back(nuovo); //inserisce un elemento in fondo alla coda
    }

    //metodo get()
    T get(){ 
        T x=queue.front(); // estrae l'elemento in testa alla coda
        queue.pop_front(); //rimuovo elemento in testa
        return x;
    }
};

//LIFO -> pila
template<typename T>    
class lifo {
    std::list<T> stack;
public:
    //default
    lifo()=default;

    //metodo empty()
    bool empty() const {
        return stack.empty();
    }

    //metodo put()
    void put(const T& nuovo){
        stack.push_front(nuovo); //inserisce un elemento in cima allo stack
    }

    //metodo get()
    T get(){ 
        T x=stack.front(); // estrae l'elemento in testa allo stack
        stack.pop_front(); //rimuovo elemento in testa
        return x;
    }
};

template <typename T> 
undirected_graph<T> graph_visit(const undirected_graph<T>& grafo, const T r, auto cont){ //cont è lifo o fifo --> in base a questo prende i metodi di uno o l'altro
    undirected_graph<T> albero;     
    std::map <T,bool> raggiunti; 
    std::vector<T> nodi=grafo.all_nodes(); 
    std::vector<T> pred;
    for (const T& nodo: grafo.all_nodes()){
        raggiunti[nodo]=false;
    }
    raggiunti[r]=true;
    cont.put(r);
    while(!cont.empty()){
        T u=cont.get();
        for (const T& w:grafo.neighbours(u)){ // scorro su tutti i vicini di u
            if (raggiunti[w]==false){
                raggiunti[w]=true;
                albero.add_edge(undirected_edge<T>(u,w));
                cont.put(w);
            }
        }
    }
    return albero;
}

template <typename T>
void recursive_dfs_helper(const undirected_graph<T>& grafo, const T nodo, std::map<T,bool>& raggiunti, undirected_graph<T>& albero){
    raggiunti[nodo]=true;
    for (const T& w: grafo.neighbours(nodo)){
        if(raggiunti[w]==false){
            albero.add_edge(undirected_edge<T>(nodo,w));
            recursive_dfs_helper(grafo,w,raggiunti,albero);
        }
    }
}


template <typename T>
undirected_graph<T> recursive_dfs(const undirected_graph<T>& grafo, const T r){ //dfs usa lifo
    std::map <T,bool> raggiunti;
    for (const T& nodo: grafo.all_nodes()){
        raggiunti[nodo]=false;
    }
    undirected_graph<T> albero;
    recursive_dfs_helper(grafo,r,raggiunti,albero);
    return albero;
}


template <typename T>
undirected_graph<T> dijkstra(const undirected_graph<T>& grafo, const T sorg){ //mettiamo pesi tutti a 1 -> coda con priorità=coda
    undirected_graph<T> albero;
    std::map <T,bool> raggiunti;
    std::map <T,int> distanza;
    const int INF = 1e9;  //eli niento cosimo numero nodi
    for (const T& nodo : grafo.all_nodes()) {
        raggiunti[nodo] = false;
        distanza[nodo] = INF;
    }
    fifo<T> q;
    raggiunti[sorg]=true;
    distanza[sorg]=0;
    q.put(sorg);
    while(!q.empty()){
        T u=q.get();
        for (const T& w: grafo.neighbours(u)){
            if (raggiunti[w]==false){
                raggiunti[w]=true;
                distanza[w]=distanza[u]+1;
                albero.add_edge(undirected_edge<T>(u,w));
                q.put(w);
            }
        }
    }
    return albero;
}


//claude mi ha aiutato qua:
template<typename T>
void to_dot(const undirected_graph<T>& grafo, const std::string& filename) {
    std::ofstream file(filename);
    file << "graph G {\n";
    for (const auto& arco : grafo.all_edges()) {
        file << "  " << arco.from() << " -- " << arco.to() << ";\n";
    }
    file << "}\n";
}