#include <iostream>

// Definición de una estructura de nodo para una lista ligada
struct Node {
    int data;    // Almacena datos
    Node* next;  // Puntero al siguiente nodo
};

// Función para dividir una lista en dos partes
void splitList(Node* head, Node*& left, Node*& right, int size) {
    left = head;
    right = nullptr;
    Node* current = head;
    for (int i = 1; i < size / 2; i++) {
        current = current->next;
    }
    right = current->next;
    current->next = nullptr;
}

// Función para fusionar dos listas ordenadas
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Función principal para ordenar una lista ligada utilizando Merge Sort
Node* mergeSort(Node* head, int size) {
    if (size <= 1) return head;

    Node* left;
    Node* right;

    // Dividir la lista en dos partes
    splitList(head, left, right, size);

    // Ordenar recursivamente ambas partes
    left = mergeSort(left, size / 2);
    right = mergeSort(right, (size + 1) / 2);

    // Fusionar las dos partes ordenadas
    return merge(left, right);
}

// Función para imprimir una lista ligada
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Crear una lista ligada no ordenada
    Node* head = nullptr;
    for (int i = 10; i >= 1; i--) {
        Node* newNode = new Node;
        newNode->data = i * 10;
        newNode->next = head;
        head = newNode;
    }

    // Calcular el tamaño de la lista
    int size = 0;
    Node* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    // Ordenar la lista utilizando Merge Sort
    head = mergeSort(head, size);

    // Imprimir la lista ordenada
    printList(head);

    // Liberar la memoria
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
