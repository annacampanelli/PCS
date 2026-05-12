#include <iostream>
#include "undirected_edge.hpp"
#include "undirected_graph.hpp"
using namespace std;

int main(){
    grafo <int> g1;
    grafo <int> g2;

    //add_edge
    g1.add_edge(undirected_edge<int>(1,2));
    g1.add_edge(undirected_edge<int>(4,1));
    g1.add_edge(undirected_edge<int>(3,2));
    g1.add_edge(undirected_edge<int>(3, 3));
    g1.add_edge(undirected_edge<int>(4, 4));
    g1.add_edge(undirected_edge<int>(5, 6));
    g1.add_edge(undirected_edge<int>(6, 2));

    g2.add_edge(undirected_edge<int>(1,2));
    g2.add_edge(undirected_edge<int>(1,7));
    g2.add_edge(undirected_edge<int>(3, 2));
    g2.add_edge(undirected_edge<int>(3, 3));
    g2.add_edge(undirected_edge<int>(12, 7));
    g2.add_edge(undirected_edge<int>(7, 3));
    g2.add_edge(undirected_edge<int>(9, 12));

    vector<int> nodi;

    cout << "vicini di 99 in g1: ";
    nodi = g1.neighbours(99);
    for (int k = 0; k<(int)nodi.size(); k++) {
      cout << nodi[k] << " ";
    }
    cout << endl;

    vector<int> vic3;
    cout << "vicini di 3 in g1: ";
    vic3 = g1.neighbours(3);
    for (int k = 0; k<(int)vic3.size(); k++) {
      cout << vic3[k] << " ";
    }
    cout << endl;

    vector<int> vic7;
    cout << "vicini di 7 in g2: ";
    vic7 = g2.neighbours(7);
    for (int k = 0; k<(int)vic7.size(); k++) {
      cout << vic7[k] << " ";
    }
    cout << endl;

    //all_nodes
    cout<<"nodi in g1: ";
    vector<int> nodi1=g1.all_nodes();
    for (int k=0; k<(int)nodi1.size(); k++){
        cout<< nodi1[k]<<" ";
    }
    cout<< endl;
    
    cout<<"nodi in g2: ";
    vector<int> nodi2=g2.all_nodes();
    for (int k=0; k<(int)nodi2.size(); k++){
        cout<< nodi2[k]<<" ";
    }
    cout<< endl;

    //all_edges
    vector<undirected_edge<int>> archi1=g1.all_edges();
    cout<<"archi di g1: ";
    for(int k=0; k<(int)archi1.size(); k++){
        cout<<archi1[k]<<" ";
    }
    cout<<endl;

    vector<undirected_edge<int>> archi2=g2.all_edges();
    cout<<"archi di g2: ";
    for(int k=0; k<(int)archi2.size(); k++){
        cout<<archi2[k]<<" ";
    }
    cout<<endl;

    //edge_number
    undirected_edge<int> arco(2,3);
    int pos=g1.edge_number(arco);
    if(pos!=-1){
        cout<<"arco "<<arco<< " trovato in posizione "<< pos<< " di g1\n";
    }
    else{
        cout<<"arco "<<arco<<" non presente in g1 \n";
    }

    undirected_edge<int> arco_ass(1,9); //controllo che arco assente non viene trovato
    int pos2=g2.edge_number(arco_ass);
    if(pos2!=-1){
        cout<<"arco "<<arco_ass<< " trovato in posizione "<< pos2<< " di g2\n";
    }
    else{
        cout<<"arco "<<arco_ass<<" non presente in g2\n";
    }

    //edge_at
    if(2 < (int)g2.all_edges().size()) {
        undirected_edge<int> arco2 = g2.edge_at(2);
        cout << "arco in posizione 2 di g2: " << arco2 << "\n";
    } 
    else{
        cout << "non esiste arco in posizione 2 di g2\n";
    }

    if(7 < (int)g1.all_edges().size()) {
        undirected_edge<int> arco7 = g1.edge_at(7);
        cout<<"arco in posizione 7 del g1: " <<arco7 << "\n";
    } 
    else{
        cout<<"non esiste arco in posizione 7 di g1\n";
    }
    
    
    //operator -
    vector<undirected_edge<int>> differenza=g1-g2;
    cout<<"g1-g2= ";
    for (int k=0; k<(int)differenza.size(); k++){
        cout<<differenza[k] <<" ";
    }
    cout<<endl;

    return 0;

}