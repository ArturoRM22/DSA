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