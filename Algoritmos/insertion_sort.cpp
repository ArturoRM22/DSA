#include <iostream>
using namespace std;

int* Insertion_sort(int array[], int size){
    int key; //Esta es la variable que se busca acamodar en si sitio en cada interación.
    int j;
    for(int i = 1; i<size;i++ ){
    key = array[i];
    j=i-1; //Esta nos sirve para hacer las comparaciónes entre el key y el elemento que esta a la izquiera. 
    while(key < array[j] && j >=0){ //Este ciclo comprueba que el elemento a la izquierda  
        array[j+1]=array[j];
        j=j-1;
    }
    array[j+1]=key;
    }
    return array;
}
int main(){
    int array[] = {10,10,10,10,10,10,10,10,10,10,10,0};
    int size = sizeof(array)/sizeof(array[0]); 
    int* ptr = Insertion_sort(array, size);
    for(int i=0; i<size ;i++){
        cout<<*(ptr+i)<<" ";
    }
}