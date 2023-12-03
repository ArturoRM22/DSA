#include "binarySearchTree.h"

BinarySearchTree::BinarySearchTree(){
    altura=0;
    raiz=nullptr;
    puertos[0]=nullptr;
    puertos[1]=nullptr;
    puertos[2]=nullptr;
    puertos[3]=nullptr;
    puertos[4]=nullptr;
}
void BinarySearchTree::push(int num) {
    node* nodo = new node;
    nodo->puerto = num;

    for (int i = 0; i <= 4; i++) {
        if (puertos[i] != nullptr && puertos[i]->puerto == num) {
            puertos[i]->data++; 
            return; 
        }
    }

    if (raiz == nullptr) {
        raiz = nodo;
        altura += 1;
        puertos[0] = nodo;
    }else {
        node* ptr = raiz;
        while (ptr != nullptr) {
            if (nodo->puerto < ptr->puerto && ptr->left == nullptr) {
                ptr->left = nodo;
                return;
            } else if (nodo->puerto > ptr->puerto && ptr->right == nullptr) {
                ptr->right = nodo;
                return;
            } else if (nodo->puerto == ptr->puerto) {
                ptr->data++;
                for (int i = 0; i <= 4; i++) {
                    if (puertos[i] == nullptr || ptr->data > puertos[i]->data) {
                        puertos[i] = puertos[i - 1];
                        puertos[i] = ptr;
                        break;
                    }
                }
                return;
            } else if (nodo->puerto < ptr->puerto) {
                ptr = ptr->left;
            } else{
                ptr = ptr->right;
            }
        }
    }
}


void::BinarySearchTree::preOrder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    cout<<root->puerto<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void::BinarySearchTree::inOrder(node* root){
    if (root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void::BinarySearchTree::postOrder(node* root){
    if (root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void BinarySearchTree::levelByLevel(node* root, int level) {
    if (root == nullptr) {
        return;
    }

    if (level == 1) {
        cout << root->data << " ";
    }
    else if (level > 1) {
        levelByLevel(root->left, level - 1);
        levelByLevel(root->right, level - 1);
    }
}

void::BinarySearchTree::visit(BinarySearchTree* arbolito){
    int op=0;
    cout<<"Introduce un numero entero del 1 al 4 para decir como quieres que muestre el BST"<<endl;
    cout<<"1. Preorder"<<endl;
    cout<<"2. Inorder"<<endl;
    cout<<"3. Postorder"<<endl;
    cout<<"4. Level by level"<<endl;
    cin>>op;
    if(op==1){
        cout<<"Opcion seleccionada (1. Preorder)"<<endl;
        arbolito->preOrder(arbolito->raiz);
        cout<<endl;
    
    }else if(op==2){
        cout<<"Opcion seleccionada (2. Inorder)"<<endl;
        arbolito->inOrder(arbolito->raiz);
        cout<<endl;
    
    }else if(op==3){
        cout<<"Opcion seleccionada (3. Postorder)"<<endl;
        arbolito->postOrder(arbolito->raiz);
        cout<<endl;
    }else if(op==4){
        cout<<"Opcion seleccionada (4. Level by level)"<<endl;
        for (int i = 1; i < arbolito->height(arbolito->raiz); i++) {
            cout << "Nivel " << i << ": ";
            arbolito->levelByLevel(arbolito->raiz, i);
            cout << endl;
        }
    }else{
        cout<<"Esa no es una opcion disponible"<<endl;
    }
}

int BinarySearchTree::height(node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        altura = max(leftHeight, rightHeight)+1;
        return altura;
    }
}

