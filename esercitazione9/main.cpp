#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "graph.hpp"
#include "visite.hpp"
using namespace std;

int main(){
    undirected_graph <int> g;
    fifo <int> coda;
    lifo <int> pila;

    g.add_edge(undirected_edge<int>(1,2));
    g.add_edge(undirected_edge<int>(1,3));
    g.add_edge(undirected_edge<int>(1,4));
    g.add_edge(undirected_edge<int>(1,6));
    g.add_edge(undirected_edge<int>(2,4));
    g.add_edge(undirected_edge<int>(2,5));
    g.add_edge(undirected_edge<int>(2,7));
    g.add_edge(undirected_edge<int>(3,6));
    g.add_edge(undirected_edge<int>(4,6));
    g.add_edge(undirected_edge<int>(4,7));
    g.add_edge(undirected_edge<int>(5,7));
    g.add_edge(undirected_edge<int>(6,7));
    g.add_edge(undirected_edge<int>(6,8));
    g.add_edge(undirected_edge<int>(7,9));
    g.add_edge(undirected_edge<int>(8,9));
    
    
    to_dot(g, "grafo.dot");


    auto albero_dfs=graph_visit(g,1,pila);
    to_dot(albero_dfs, "albero_dfs.dot");

    auto albero_bfs=graph_visit(g,1,coda);   
    to_dot(albero_bfs, "albero_bfs.dot");

    auto albero_dijkstra=dijkstra(g,1);
    to_dot(albero_dijkstra, "albero_dijkstra.dot");

    auto albero_ricorsivo_bfs=recursive_dfs(g,1);
    to_dot(albero_ricorsivo_bfs, "albero_ricorsivo_bfs.dot");   

    return 0;
}
