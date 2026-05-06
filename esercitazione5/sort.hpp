//implementare merge_sort e quick_sort e copiare altri da esercitazione 4.
#include <vector>
#include <algorithm>
//#include <cassert>
#pragma once


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

//merge
template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r){ //notiamo che qua L e R sono sottometà del mio vettore iniziale già ordinate singolarmente
    int dim1 = q-p+1;
    int dim2 = r-q;
    std:: vector <T> L;
        L.resize(dim1);
    std:: vector <T> R;
        R.resize(dim2);
    for (int i=0; i<dim1; i++){
        L[i]=vec[p+i]; 
    }
    for (int j=0; j<dim2; j++){
        R[j]=vec[q+j+1]; 
    }
    int i=0;
    int j=0;
    int k=p;
    while (i<dim1 && j<dim2){
        if (L[i]<=R[j]){
            vec[k]=L[i];
            i++;
        }
        else{
            vec[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<dim1){
        vec[k]=L[i];
        i++;
        k++;
    }
    while(j<dim2){
        vec[k]=R[j];
        j++;
        k++;
    }
}

//merge_sort
template <typename T>
void merge_sort(std::vector<T>& vec, int p, int r){
    if (p<r){
        int q=(p+r)/2;
        merge_sort(vec,p,q);
        merge_sort(vec,q+1,r);
        merge(vec,p,q,r);
    }
}

//partition
template <typename T>
int partition(std:: vector <T>& vec, int p, int r){
    T x=vec[r];
    int i= p-1;
    for (int j=p; j<r; j++){
        if (vec[j]<=x){
            i++;
            //assert(i>= 0 and i < vec.size());
            //assert(j>= 0 and j < vec.size());
            std::swap(vec[i],vec[j]);
        }
    }
    //assert(i+1>= 0 and i+1 < vec.size());

    std::swap(vec[i+1],vec[r]);
    return (i+1);
}


//quick_sort
template <typename T>
void quick_sort(std::vector<T>& vec, int p, int r){
    if (p<r){
        int q=partition(vec,p,r);
        quick_sort(vec,p,q-1);
        quick_sort(vec,q+1,r);
    }
}


// insertion sort 3 input
template <typename T>
void my_insertion_sort(std::vector<T>& vec, int p, int r){
    for (int j = p + 1; j <= r; j++){
        T key = vec[j];
        int i = j - 1;
        while (i >= p && vec[i] > key){
            vec[i+1] = vec[i];
            i = i - 1;
        }
        vec[i+1] = key;
    }
}

// my_sort 
template <typename T>
void my_sort(std::vector<T>& vec, int p, int r){
    if (p < r){
        if (r - p < 250){
            my_insertion_sort(vec, p, r);
        } else {
            int q = partition(vec, p, r);
            my_sort(vec, p, q-1);
            my_sort(vec, q+1, r);
        }
    }
}
