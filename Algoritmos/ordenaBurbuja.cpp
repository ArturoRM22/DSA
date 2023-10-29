#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> vector){
    for(int i = 0; i<vector.size(); i++){
        for(int j = 0; j<((vector.size()-1)-i); j++){
            if(vector[j+1]<vector[j]){
            int aux = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = aux;
        }
        }
    }
    return vector;
}
int main(){
    vector<int> vector = {300,10,44,32,26,7,0,1,4,12,30}; //{}
    std::vector<int> sorted_vector = bubbleSort(vector);
    for(int num : sorted_vector){
        cout<<num<<" ";
    }
}
