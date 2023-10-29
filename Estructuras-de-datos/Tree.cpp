#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node(){
            data = 0;
            right = nullptr;
            left = nullptr;
        }
};

class BST{
    public: 
        Node* root;
        BST();
        void push(int);
        void printInOrder(Node*);
        void printPreOrder(Node*);
        void printPostOrder(Node*);
};

BST::BST(){
    root = nullptr;
}

void BST::push(int data){
    Node* new_node = new Node();
    new_node->data = data;
    if(root == nullptr){
        root = new_node;
        cout << "valor incertado como raiz" << endl;
    }else{
        Node* aux_root = root;
        while(aux_root != nullptr){
            if(aux_root->data == new_node->data){
                cout << "Valor repetido" << endl;
                return;
            }else if(new_node->data < aux_root->data && aux_root->left == nullptr){
                aux_root->left = new_node;
                break;
            }else if(new_node->data > aux_root->data && aux_root->right == nullptr){
                aux_root->right = new_node;
                break;
            }else if(new_node->data < aux_root->data){
                aux_root = aux_root->left;
            }
            else{
                aux_root = aux_root->right;
            }
        }
    }
}

void BST::printInOrder(Node* current){
    if (current == nullptr)
    return;
    printInOrder(current->left);

    cout << current->data << " ";

    printInOrder(current->right);
}

void BST::printPreOrder(Node* current){
    if (current == nullptr)
    return;
    cout << current->data << " ";

    printPreOrder(current->left);

    printPreOrder(current->right);
}

void BST::printPostOrder(Node* current){
    if (current == nullptr)
    return;
    printPostOrder(current->left);

    printPostOrder(current->right);     

    cout << current->data << " ";
}

int main(){
    BST tree;
    tree.push(10);
    tree.push(1);
    tree.push(20);
    tree.push(33);
    tree.push(7);
    tree.push(0);
    tree.push(19);
    tree.printInOrder(tree.root);
    cout << "\n";
    tree.printPreOrder(tree.root);
    cout << "\n";
    tree.printPostOrder(tree.root);
    return 0;
}
