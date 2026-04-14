// qui implemento i tre ordinamenti e is_sorted()
#pragma once //include i file una sola volta
#include <vector>

//is_sorted
template <typename T>
bool is_sorted(const std::vector<T>& vec){ //il vettore non viene modificato -> const
    int N=vec.size();
    if (N>1){ // il vettore vuoto o con un solo elemento è ordinato
        for (int k=0; k<N-1; k++){
            if (vec[k]>vec[k+1]){
                return false;
            }
        }
    }
    return true;
}

//bubble sort
template <typename T>
void bubble_sort(std::vector<T>& vec){
    int N=vec.size();
    for (int i=0; i<N-1; i++){
        for (int j=N-1; j>i; j--){
            if (vec[j]<vec[j-1]){
                std:: swap(vec[j], vec[j-1]);
            }
        }
    }
}

//insertion 
template <typename T>
void insertion_sort(std::vector<T>& vec){
    int N=vec.size();
    for (int j=1; j<N; j++){
        T key=vec[j];
        int i=j-1;
        while(i>=0 && vec[i]>key){
            vec[i+1]=vec[i];
            i=i-1;
        }
        vec[i+1]=key;
    }
}

//selection
template <typename T>
void selection_sort(std::vector<T>& vec){
    int N=vec.size();
    for (int i=0; i<N-1; i++){
        int min=i;
        for (int j=i+1; j<N; j++){
            if (vec[j]<vec[min]){
                min=j;
            }
        }
        std:: swap (vec[i],vec[min]);
    }
}