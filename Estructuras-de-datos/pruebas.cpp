#include <iostream>
#include "heap.hpp"
#include <math.h>

using namespace std;

Heap::Heap(){
    this->heapArray.push_back(0);
}

Heap::~Heap(){
    this->heapArray.clear();
}

void Heap::heapifyDown(int index){
    int left =  2*index;
    int right = 2*index + 1;
    int temp = index;
    if(left < this->heapArray.size() && this->heapArray[left] > this->heapArray[index]){
        temp = left;
    }
    if(right < this->heapArray.size() && this->heapArray[right] > this->heapArray[temp]){
        temp = right;
    }
    if(temp != index){
        swap(this->heapArray[index], this->heapArray[temp]);
        heapifyDown(temp);
    }
}

void Heap::heapifyUp(int index){
    int padre = index/2;
    if(padre >=1 && this->heapArray[padre] < this->heapArray[index]){
        swap(this->heapArray[padre], this->heapArray[index]);
        heapifyUp(padre);
    }
}

void Heap::insert(int value){
    this->heapArray.push_back(value);
    heapifyUp(this->heapArray.size()-1);
}

int Heap::getMax(){
    if(this->heapArray.size() == 1){
        throw runtime_error("El heap esta vacio");
    }
    return this->heapArray[1];
}

void Heap::deleteMax(){
    if(this->heapArray.size() == 1){
        throw runtime_error("El heap esta vacio");
    }
    this->heapArray[1] = this->heapArray[this->heapArray.size()-1];
    this->heapArray.pop_back();
    heapifyDown(1);
}

bool Heap::isEmpty(){
    return this->heapArray.size() == 1;
}

int Heap::size(){
    return this->heapArray.size()-1;
}

void inorder(int index, vector<int> heapArray){
    if(index >= heapArray.size()){
        return;
    }
    inorder(index*2, heapArray);
    cout << heapArray[index] << " ";
    inorder(index*2+1, heapArray);
}

void  preorder(int index, vector<int> heapArray){
    if(index >= heapArray.size()){
        return;
    }
    cout << heapArray[index] << " ";
    preorder(index*2, heapArray);
    preorder(index*2+1, heapArray);
}

void  postorder(int index, vector<int> heapArray){
    if(index >= heapArray.size()){
        return;
    }
    postorder(index*2, heapArray);
    postorder(index*2+1, heapArray);
    cout << heapArray[index] << " ";
}

void Heap::print(int option){
    if(option == 1){
        preorder(1, this->heapArray);
        cout << endl;
    }
    else if(option == 2){
        inorder(1, this->heapArray);
        cout << endl;
    }
    else if(option == 3){
        postorder(1, this->heapArray);
        cout << endl;
    }
    else if(option == 4){
        int p = 1;
        for(int i = 1; i < heapArray.size(); i++){
            cout << heapArray[i] << " ";
            if(i == pow(2,p)-1){
                cout << endl;
                p++;
            }
        }
    }
    else{
        cout << "Opcion no valida" << endl;
    }
}

int main(){
    Heap heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);

    cout<<"HEAP"<<endl;
    int menu = 0;
    while(menu == 0){
        cout<<"1. Insertar"<<endl;
        cout<<"2. Eliminar"<<endl;
        cout<<"3. Imprimir"<<endl;
        cout<<"4. Obtener máximo valor del heap"<<endl;
        cout<<"5. Borrar máximo valor del heap"<<endl;
        cout<<"6. Consultar tamaño del heap"<<endl;
        cout<<"7. Checar si el Heap esta vacio"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>menu;
        if(menu == 1){
            int valor = 0;
            cout<<"Valor: ";
            cin>>valor;
            heap.insert(valor);
        }
        else if(menu == 2){
            heap.deleteMax();
        }
        else if(menu == 3){
            int opcion = 0;
            cout<<"1. Preorder"<<endl;
            cout<<"2. Inorder"<<endl;
            cout<<"3. Postorder"<<endl;
            cout<<"4. Level by Level"<<endl;
            cout<<"Opcion: ";
            cin>>opcion;
            heap.print(opcion);
        }
        else if(menu == 4){
            cout<<"Maximo valor: "<<heap.getMax()<<endl;
        }
        else if(menu == 5){
            heap.deleteMax();
            cout<<"Maximo valor borrado"<<endl;
        }
        else if(menu == 6){
            cout<<"Tamaño del heap: "<<heap.size()<<endl;
        }
        else if(menu == 7){
            if(heap.isEmpty()){
                cout<<"El heap esta vacio"<<endl;
            }
            else{
                cout<<"El heap no esta vacio"<<endl;
            }
        }
        else if(menu == 8){
            cout<<"Saliendo..."<<endl;
        }
        else{
            cout<<"Opcion no valida"<<endl;
    }
}
}