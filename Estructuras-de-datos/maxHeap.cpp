#include <iostream>
using namespace std;

#define SIZE 12

class Maxheap{
    public:
        int* array;
        int capacity;
        int heap_size;
        Maxheap();
        Maxheap(int*, int);
        bool empty();
        void push(int);
        void heapify();
        void pop();
        int top();
        int size();
        void display();
};

Maxheap::Maxheap(){
    capacity = SIZE;
}

Maxheap::Maxheap(int* array, int size){
    this->array = array;
    capacity = SIZE;
    heap_size = size;
}

bool Maxheap::empty(){
    return heap_size == 0;
}

void Maxheap::push(int new_value){
    if(heap_size == capacity){
        cout << "No hay espacio para más elementos" << endl;
        return;
    }
    heap_size ++;
    int i  = heap_size-1;
    array[i] = new_value;
    while(i != 0 && array[i]>array[(i-1)/2]){
        swap(array[i], array[(i-1)/2]);
        i = (i-1)/2;
    }
}

void Maxheap::pop(){
    if(heap_size == 0){
        cout << "Heap vacío" << endl;
        return;
    }
    int deleted = array[0];
    swap(array[0], array[heap_size-1]);
    heap_size--;
    int i = 0;
    int max_index;
    while((i*2+2 <= heap_size-1) && (array[i] < array[i*2+1] || array[i] < array[i*2+2])){
        max_index = i*2+2;
        if(array[i*2+1]>array[i*2+2]){
            max_index = i*2+1;
        }
        swap(array[i], array[max_index]);
        i = max_index;
    }
    cout << "Se eliminó el: " <<deleted<<endl;
}

int Maxheap::top(){
    if(empty()){
        cout << "Heap vacío" << endl;
        return -1;
    }
    return array[0];
}

int Maxheap::size(){
    return heap_size;
}

void Maxheap::heapify(){
    if(empty()){
        cout << "Array vacío" << endl;
        return;
    }
    int num_iteraciones = heap_size/2;
    int max_index;
    for(int i = num_iteraciones-1; i >= 0; i--){
    while((i*2+2 <= heap_size-1) && (array[i] < array[i*2+1] || array[i] < array[i*2+2])){
        max_index = i*2+2;
        if(array[i*2+1]>array[i*2+2]){
            max_index = i*2+1;
        }
        swap(array[i], array[max_index]);
        i = max_index;
    }
    }
}

void Maxheap::display(){
    cout << "[";
    for (int i = 0; i < heap_size; i++){
        cout << array[i] << ", " ;
    }
    cout << "]" << endl;
}

int main() {
    int eleccion;
    int eleccion2;
    int emArray[SIZE];
    int Array[SIZE] = {30,3,14,55,5,7,11,1,20,4,88,2};
    Maxheap* heap;
    cout << "Max heap" << endl;
    cout << "Elige entre crear un max heap desde cero, agregando elementos uno a uno o \ntransforma un array con valores ya establecidos en un max heap" << endl;
    cout << "Crear max heap uno a uno. teclea 1" << endl;
    cout << "Crear max heap a partir de un array. teclea 2" << endl;
    cin >> eleccion;

    if(eleccion == 1){
        heap = new Maxheap(emArray,0);
    }
    else if(eleccion == 2){
        heap = new Maxheap(Array,SIZE);
        heap->heapify();
    }

    do{
    cout << "------------------" << endl;
    cout << "Max heap métodos" << endl;
    cout << "push. 1" << endl;
    cout << "pop. 2" << endl;
    cout << "top. 3" << endl;
    cout << "size. 4" << endl;
    cout << "display. 5" << endl;
    cout << "salir. 6" << endl;
    cout << "------------------" << endl;
    cin >> eleccion2;
    switch (eleccion2)
    {
    case 1:
        int value;
        cout << "Valor (int): " << endl;
        cin >> value;
        heap->push(value);
        break;
    case 2:
        heap->pop();
        break;
    case 3:
        cout <<"Max: "<< heap->top() << endl;
    break;
    case 4:
        cout <<"Size: "<<heap->size() << endl;
    break;
    case 5:
        heap->display();
    break;
    default:
        break;
    }
    }while(eleccion2 != 6);
    return 0;
}