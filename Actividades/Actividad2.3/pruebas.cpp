#include <stdio.h>
#include <stdlib.h>


struct Node{

    int data;
    Node* next;

};

Node* globalHead;

void printList(Node* head){

    Node* current = head;
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");

}
void partition(Node* head, Node* *front, Node* *back){

    Node* fast;
    Node* slow;

    if (head == NULL || head->next == NULL){

        *front = head; // &a
        *back = NULL; // &b

    }else{

        slow = head;
        fast = head->next;

        while(fast != NULL){

            fast = fast->next;

            if(fast != NULL){

                slow = slow->next;
                fast = fast->next;

            }

        }

        *front = head; // a
        *back = slow->next; // b
        slow->next = NULL;
        printList(*front);
        printList(*back);

    }

}

Node* mergeLists(Node* a, Node* b){

    Node* mergedList = NULL;

    if (a == NULL){
        return b;
    }else if (b == NULL){
        return a;
    }

    if (a->data <= b->data){
        mergedList = a;
        mergedList->next = mergeLists(a->next, b);
    }else{
        mergedList = b;
        mergedList->next = mergeLists(a, b->next);
    }

    return mergedList;

}

void mergeSort(Node* *source){

    Node* head = *source;
    Node* a = NULL;
    Node* b = NULL;

    if(head == NULL || head->next == NULL){

        return;

    }

    partition(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *source = mergeLists(a, b);

}

void push(Node** head, int data){

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if ((*head) == NULL){
        *head = newNode;
        globalHead = *head;
    }else{
        (*head)->next = newNode;
        *head = newNode;
    }

}

