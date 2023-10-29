#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ordenaBurbuja(vector<int>&vector){
    for(int i = 0; i<vector.size(); i++){
        for(int j = 0; j<((vector.size()-1)-i); j++){
            if(vector[j+1]<vector[j]){
            int aux = vector[j];
            vector[j] = vector[j+1];
            vector[j+1] = aux;
        }
        }
    }
}
void merge(std::vector<double>& a, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<double> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = a[low + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            a[k] = leftArr[i];
            ++i;
        } else {
            a[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        a[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        a[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void ordenaMerge(std::vector<double>& a, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        ordenaMerge(a, low, mid);
        ordenaMerge(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int busqSecuencial(vector<int>a,int key){
    for(int i=0;i<=a.size();i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}
int busqBinariaRecursiva(vector<int> a,int key,int low,int high){
    if(low<=high){
        int mid=low +(high-low)/2;
        if(a[mid]==key){
            return mid;
        }
        if(a[mid]<key){
             return busqBinariaRecursiva(a,key,mid+1,high);
        }else{
             return busqBinariaRecursiva(a,key,low,mid-1);
        }
        return busqBinariaRecursiva(a,key,low,high);
    }else{
        return -1;
    }
}
int busqBinariaIterativa(vector<int> a,int key,int low,int high){
    while(low<=high){
        int mid=low +(high-low)/2;
        if(a[mid]==key){
            return mid;
        }
        if(a[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    vector <int>a = {3,3,10,3,4,1,10,0};
    vector <double>a_double = {2.4, 3.5, 1.0, 40.2, 3.4, 5.7};
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    int zise= a.size();
    ordenaMerge(a_double,0,a_double.size()-1);
    cout << "merge: "<<endl;
    for(int i:a_double){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Posicion en que se encuentra el 8 en el vector: "<<busqSecuencial(a,2)<<endl;
    cout<<"Posicion en que se encuentra el 8 en el vector: "<<busqBinariaIterativa(a,32,0,zise-1)<<endl;
    cout<<"Posicion en que se encuentra el 8 en el vector: "<<busqBinariaRecursiva(a,17,0,zise-1)<<endl;
    vector <int>a2 = {2,1,5,3,3,5,68,9,81,121,1,14,15,16,17};
    for(int i:a2){
        cout<<i<<" ";
    }
    cout<<endl;
    ordenaBurbuja(a2);
    for(int i:a2){
        cout<<i<<" ";
    }
}