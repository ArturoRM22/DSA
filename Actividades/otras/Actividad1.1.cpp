#include <iostream>
using namespace std;
// Aplicación de 3 métodos diferentes para calcular la sumatoria de 1 hasta n. (Directa, Iterativa y Recursiva).
// Arturo Ramos Martínez. A01643269
// 17/08/2023 - 19/08/2023

int sumaIterativa(int n){
    if(n<=0){
        return 0;
    }
    int sum=0;
    for(int i=1; i<=n ;i++){
        sum=sum+i;
    }
    return sum;
}

int sumaDirecta(int n){
    if(n<=0){
        return 0;
    }
    return n*(n+1)/2;
}

int sumaRecursiva(int n, int i){
    if(n<=0){
        return 0;
    }
    if(i==n){
       return i; 
    }
    return i+sumaRecursiva(n, i+1);
}

int main(){
    int num;
    cout<<"Elige un número para n: "<<endl;
    cin>>num;
    cout<<"Suma Directa: "<<sumaDirecta(num)<<endl;
    cout<<"Suma Iterativa: "<<sumaRecursiva(num, 0)<<endl;
    cout<<"Suma Recursiva: "<<sumaIterativa(num);
}