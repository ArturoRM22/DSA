#include <iostream>
using namespace std;

struct node
{
 int data;
 struct node *next;
};
class LinkedList{
    public:
    //Properties
    node *head;
    node *tail;
    //Methods
    LinkedList();
    void push(int);
    void dell();
};
LinkedList::LinkedList(){
    this->head = NULL;
    this->tail=head;
}
void LinkedList::push(int num){
    node *nodo = new node; 
    nodo->data = num;
    nodo->next = head;
    head = nodo;
}
void LinkedList::dell(){
    if (head != nullptr)
    {
        node *temp=head;
        head=head->next;
        delete temp;
    }
}

int main(){
    LinkedList *list = new LinkedList();
    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);
    list->push(5);

    list->dell();

    node *temp = list->head;
    while (temp != nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }

    return 0;
}



