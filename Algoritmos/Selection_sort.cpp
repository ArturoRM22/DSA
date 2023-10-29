#include<iostream>
using namespace std;

int* Selection_sort(int array[], int size){
    int min;
    for(int i=0; i < size ;i++){
        min = i;
        int aux;
        for(int j=i+1; j < size ;j++){
            if(array[min] > array[j]){
                min = j;
            }
        }
        aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
    return array;
}

int main(){
    int array[]= {40,20,10,2,3,12,100}; //{2,3,10,40,20,12,100}
    int size = sizeof(array)/sizeof(array[0]);
    int* ptr = Selection_sort(array, size);

    
    for(int k=0; k < size ;k++){
        cout<<*(ptr+k)<<" ";
    }
}