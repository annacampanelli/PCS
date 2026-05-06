#include <string>
#include <algorithm>    
#include "randfiller.h"
#include "timecounter.h"
#include "sort.hpp"
using namespace std;


void fill_vectors(vector<vector<int>> &vets, int dim)
{
  randfiller rf;

  for (unsigned int i = 0; i < vets.size(); i++) {
    vets[i].resize(dim);
    rf.fill(vets[i], -1000, 1000);
  }
    
}

int main(){
    timecounter tc;
    int n=3000;  //numero di dimensioni che voglio misurare 
    int reps=100; //numero di vettori per ogni dimensione 

    int start=1;
    int step=50;

    //vettori contenenti i tempi per ogni algoritmo per ogni dimensione
    vector <double> t_bubble;
    vector <double> t_insertion;
    vector <double> t_selection;
    vector <double> t_sort;
    vector <double> t_merge;
    vector <double> t_quick;
    vector <double> t_mine;

    //vet è un vettore di n vettori che contiene vettori di dimensione k
    for (int k=start; k<=n; k+=step){ // 

        // preallocazione di reps vettori
        vector<vector<int>> vets(reps);

        //misuro tempo necessario ad ogni algoritmo per ordinare i 100 vettori di dimensione k

        //bubble
        fill_vectors(vets,k);
        tc.tic();
        for (int i=0; i<reps; i++){ 
            bubble_sort(vets[i]);
        }
        t_bubble.push_back(tc.toc()/reps);


        //insertion_sort
        fill_vectors(vets,k);
        tc.tic();
        for (int i=0; i<reps; i++){
            insertion_sort(vets[i]); 
        }
        t_insertion.push_back(tc.toc()/reps);
        
        //selection_sort
        fill_vectors(vets,k);
        tc.tic();
        for (int i=0; i<reps; i++){ 
            selection_sort(vets[i]);
        }
        t_selection.push_back(tc.toc()/reps); 
        
        //std sort
        fill_vectors(vets,k);
        tc.tic();
        for (int i=0; i<reps; i++){
            sort(vets[i].begin(),vets[i].end()); 
        }
        t_sort.push_back(tc.toc()/reps);

        //merge_sort
        fill_vectors(vets,k);
        tc.tic();
        for (int i=0; i<reps; i++){ 
            merge_sort(vets[i],0,k-1);
        }
        t_merge.push_back(tc.toc()/reps);

        //quick_sort
        fill_vectors(vets,k);
        tc.tic();
        for (int i=0; i<reps; i++){ 
            quick_sort(vets[i],0,k-1);
        }
        t_quick.push_back(tc.toc()/reps);

        //my_sort
        fill_vectors(vets,k);
        tc.tic();
        for (int i=0; i<reps; i++){ 
            my_sort(vets[i],0,k-1);
        }
        t_mine.push_back(tc.toc()/reps);
    }

    cout <<"dimensione;quick;bubble;selection;insertion;merge;standard;mine\n";
    int dim=t_quick.size();
    for (int i=0; i<dim; i++){
        cout<<i*step<<";"<< t_quick[i]<<";"<<t_bubble[i]<<";"<<t_selection[i]<<";"<<t_insertion[i]<<";"<<t_merge[i]<<";"<<t_sort[i]<<";"<<t_mine[i]<<"\n"; 
        }

    return 0;
}