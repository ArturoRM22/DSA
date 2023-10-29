#include <iostream>
using namespace std;

#define SIZE 100

class Stack{
    public:
        int* array;
        int capacity;
        int top;
        bool status;
        Stack(int*);
        void Create(int);
        int Del();
        int Read();
        bool isFull();
        bool IsEmpty();
};
Stack::Stack(int *array_){
    array = array_;
    capacity = SIZE;
    status = false;
}

bool Stack::isFull(){
    if(top == capacity){
        status = true;
        return true;
    }else{
        status = false;
        return false;
    }
}

bool Stack::IsEmpty(){
    if(top != 0){
        return false;
    }
    return true;
}

void Stack::Create(int value){
    if(isFull() == false){
        *(array+top) = value;
        top = top + 1;
    }else{
        cout <<"El stack esta lleno"<<endl;
    }
}

int Stack::Read(){
    if(IsEmpty() == true){
        cout<<"El stack esta vacio"<<endl;
        exit(0);
    }
    cout<<"Top: "<<*(array+(top-1))<<endl;
    return *(array+(top-1));
}

int Stack::Del(){
    top = top-1;
    return *(array+top);
}
