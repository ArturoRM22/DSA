#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data, Node* next);
};

Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}

class Linkedlist{
    public: 
        Node* head;
        Node* tail;
        Linkedlist();
        void push(int);
        int pop();
        void display();
};

Linkedlist::Linkedlist(){
    this->head = nullptr;
    this->tail = nullptr;
}

void Linkedlist::push(int data){
    if(this->head== nullptr && this->tail==nullptr){
        Node* new_node = new Node(data, this->head);
        this->head = new_node;
        this->tail = new_node;
    }else{
        Node* new_node = new Node(data, this->head);
        this->head = new_node;
    }
}

int Linkedlist::pop(){
    if(this->head== nullptr && this->tail==nullptr){
        cout << "La lista ligada está vacia" << endl;
        return 0;
    }else if(this->head->next == nullptr && this->tail->next == nullptr){
        Node* head_tail_anteriores = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        delete head_tail_anteriores;
        return 0;
    }else{
        Node* head_anterior = this->head;
        this->head = this->head->next;
        delete head_anterior;
        return 1;
    }
}

void Linkedlist::display(){
    Node* current_head = this->head;
    cout<<"[";
    while(current_head != nullptr){
        cout<<current_head->data<<"->";
        current_head = current_head->next;
    }
    cout<<"nullptr"<<"]"<<endl;
}

class Stack{
    public:
        Linkedlist* linkedlist;
        int top;
        int capacity;
        Stack();
        void add(int);
        int del();
        bool isEmpty();
        int size();
        int peak();
};

Stack::Stack(){
    this->linkedlist = new Linkedlist;
    this->top = -1;
    this->capacity = 0;
}

void Stack::add(int data){
    this->linkedlist->push(data);
    top = linkedlist->head->data;
    capacity ++;
}

int Stack::del(){
    int top_anterior = top;
    int estado = this->linkedlist->pop();
    if(estado != 1){
        top = -1;
        capacity --;
        return top_anterior;
    }else{
        top = linkedlist->head->data;
        capacity --;
        return top_anterior;
    }
}

bool Stack::isEmpty(){
    return(capacity == 0);
}

int Stack::size(){
    return capacity;
}

int Stack::peak(){
    return top;
}

int main(){
    Stack stack1;
    stack1.add(3);
    stack1.add(1);
    stack1.add(37);
    cout << "Peak: "<<stack1.peak() << endl;
    cout << stack1.del() <<endl;
    cout << stack1.del() <<endl;
    cout << "Peak: "<<stack1.peak() << endl;
    stack1.linkedlist->display();
    cout << stack1.del() <<endl;
    cout << "size: "<<stack1.size() <<endl;
    cout << "status: "<<stack1.isEmpty() <<endl;
    stack1.linkedlist->display();
    stack1.add(4);
    stack1.add(7);
    cout << stack1.del() <<endl;
    cout << stack1.del() <<endl;
    cout << stack1.del() <<endl;
    stack1.linkedlist->display();
    cout << "status: "<<stack1.isEmpty() <<endl;
    return 0;
}
