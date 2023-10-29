#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* previous;
        Node(int data, Node* previous, Node* next){
            this-> data = data;
            this-> next = next;
            this-> previous = previous;
        }
};

class dLinkedList{
    public:
        Node* head;
        Node* tail;
        dLinkedList();
        void push(int);
        void display_h_to_t();
        void display_t_to_h();

};

dLinkedList::dLinkedList(){
    head = nullptr;
    tail = nullptr;
}

void dLinkedList::push(int data){
    Node* new_node = new Node(data, nullptr, nullptr);
    if(head == nullptr && tail == nullptr){
        new_node->next = head;
        new_node->previous = nullptr;
        head = new_node;
        tail = new_node;
    }else{
        new_node->next = head;
        head->previous = new_node;
        head = new_node;
        new_node->previous = nullptr; 
    }
}

void dLinkedList::display_h_to_t(){
    Node* current_head = this->head;
    cout<<"[";
    while(current_head != nullptr){
        cout<<current_head->data<<"->";
        current_head = current_head->next;
    }
    cout<<"nullptr"<<"]"<<endl;
}

void dLinkedList::display_t_to_h(){
    Node* current_tail = this->tail;
    cout<<"[";
    while(current_tail != nullptr){
        cout<<current_tail->data<<"->";
        current_tail = current_tail->previous;
    }
    cout<<"nullptr"<<"]"<<endl;
}


int main(){
    dLinkedList list;
    list.push(3);
    list.push(2);
    list.push(1);
    list.push(10);
    list.push(20);
    list.push(4);
    list.display_h_to_t();
    list.display_t_to_h();
    return 0;
}