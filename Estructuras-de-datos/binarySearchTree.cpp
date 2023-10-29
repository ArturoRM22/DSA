#include <iostream>

using namespace std;
struct node{
    public:
        int data;
        node* right;
        node* left;
        node(){
            data = 0;
            right = nullptr;
            left = nullptr;
        }
};

class BST{
public:
   node *raiz;
   int altura;
   BST();
   void push(int num);
   node* recursiveInsertion(node* current, node* new_node);
   void preOrder(node* root);
   void inOrder(node* root);
   void postOrder(node* root);
   void levelByLevel(node* root,int num);
   void visit(BST* arbolito);
   int height(node* root);
   int whatLevelIAm(int num);
   int ancestors(int num);
};
BST::BST(){
    altura=0;
    raiz=nullptr;
}

node* BST::recursiveInsertion(node* current, node* new_node){
    if(current == nullptr){
        current = new_node;
        return current;
    }
    if(current->data > new_node->data){
        current->left = recursiveInsertion(current->left, new_node);
    }else if(current->data < new_node->data){
        current->right = recursiveInsertion(current->right, new_node);
    }else{
        cout << "no duplicates allowed" << endl;
        return current;
    }
    return current;
}

void BST::push(int num){
    node* nodo=new node;
    nodo->data=num;
    if(raiz==nullptr){
        raiz=nodo;
    }else{
        node*ptr=raiz;
        while(ptr!=nullptr){ 
           if(nodo->data<ptr->data&&ptr->left==nullptr){
                ptr->left=nodo;
                break;
            }else if(nodo->data>ptr->data&&ptr->right==nullptr){
                ptr->right=nodo;
                break;
            }else if(nodo->data==ptr->data){
                cout<<"Ese valor ya habia sido ingresado, intenta con otro"<<endl;
                return;
            }else if(nodo->data<ptr->data){
                ptr=ptr->left;
            }else{
                ptr=ptr->right;
            }
        }
    }
}
void BST::preOrder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void BST::inOrder(node* root){
    if (root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void BST::postOrder(node* root){
    if (root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void BST::levelByLevel(node* root, int level) {
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
void BST::visit(BST* arbolito){
    int op=0;
    cout<<"Introduce un numero entero del 1 al 4 para decir como quieres que muestre el BST"<<endl;
    cout<<"1. preOrder"<<endl;
    cout<<"2. inOrder"<<endl;
    cout<<"3. postOrder"<<endl;
    cout<<"4. Level by level"<<endl;
    cin>>op;
    if(op==1){
        cout<<"Opcion seleccionada (1. preOrder)"<<endl;
        arbolito->preOrder
(arbolito->raiz);
        cout<<endl;
    
    }else if(op==2){
        cout<<"Opcion seleccionada (2. inOrder)"<<endl;
        arbolito->inOrder(arbolito->raiz);
        cout<<endl;
    
    }else if(op==3){
        cout<<"Opcion seleccionada (3. postOrder)"<<endl;
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

int BST::height(node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight>=rightHeight){
            altura=leftHeight+1;
        }else{
            altura=rightHeight+1;
        }
        return altura;
    }
}
int BST::whatLevelIAm(int num){
    int cont=0;
    node* nodo=new node;
    nodo->data=num;
    node*ptr=raiz;
    while(ptr!=nullptr){
        if(ptr->data>num&&ptr->left!=nullptr){
            ptr=ptr->left;
            cont+=1;
        }else if(ptr->data<num&&ptr->right!=nullptr){
            ptr=ptr->right;
            cont+=1;
        }else if(ptr->data==num){
            cont+=1;
            return cont;
        }
        else{
            return -1;
        }
    }
}
int BST::ancestors(int num){
    node* nodo=new node;
    nodo->data=num;
    node*ptr=raiz;
    if(num == raiz->data){
        cout << "El nodo raíz no tiene ancestros"<<endl;
        return -1;
    }
    while(ptr!=nullptr){
        if(ptr->data>num&&ptr->left!=nullptr){
            cout << ptr->data << endl;
            ptr=ptr->left;
        }else if(ptr->data<num&&ptr->right!=nullptr){
            cout << ptr->data << endl;
            ptr=ptr->right;
        }else if(ptr->data==num){
            cout<<"Descendiente: " << ptr->data << endl;
            return 1;
        }else{
            return -1;
        }
    }

}
int main(){
    int eleccion;
    BST BST;
    BST.push(7);
    BST.push(2);
    BST.push(9);
    BST.push(1);
    BST.push(3);
    BST.push(8);
    BST.push(12);
    BST.push(4);
    BST.height(BST.raiz);
    do{
        cout <<"\n---------------------------------------" << endl;
        cout <<"Acciones BST" << endl;
        cout << "Escoje la accion que deseas realizar: "<<endl;
        cout << "Agregar un valor (push). 1"<<endl;
        cout << "Mostrar valores preOrder. 2"<<endl;
        cout << "Mostrar valores inOrder. 3"<<endl;
        cout << "Mostrar valores postOrder. 4"<<endl;
        cout << "Mostrar valores levelByLevel. 5"<<endl;
        cout << "Nivel de algun valor. 6"<<endl;
        cout << "Altura. 7"<<endl;
        cout << "Ancestros. 8"<<endl;
        cout << "Salir. 9"<<endl;
        cout <<"---------------------------------------" << endl;
        cin>>eleccion;
        switch (eleccion)
        {
        case 1:
            int valor;
            cout << "Valor (int): ";
            cin>>valor;
            BST.push(valor);
        break;
        case 2:
            cout << "Pre_order:"<<endl;
            BST.preOrder(BST.raiz);
        break;
        case 3:
            cout << "In_order:"<<endl;
            BST.inOrder(BST.raiz);
        break;
        case 4:
            cout << "Post_order:"<<endl;
            BST.postOrder(BST.raiz);
        break;
        case 5:
            cout << "Level by level:"<<endl;
            for (int i = 1; i <= BST.height(BST.raiz); i++) {
            cout << "Nivel " << i << ": ";
            BST.levelByLevel(BST.raiz, i);
            cout << endl;
            }
        break;
        case 6:
            cout << "Ingresa el valor del cual quieres conocer el nivel donde se encuentra encuentra" << endl;
            int num;
            cin>>num;
            cout << "Nivel: "<<BST.whatLevelIAm(num)<<endl;
        break;
        case 7:
            cout << "Altura:" << BST.altura <<endl;
        break;
        case 8:
            int value;
            cout << "Valor del cual quieres conocer sus ancestros:"<<endl;
            cin>>value;
            cout << "ancestros: "<<endl;
            BST.ancestors(value);
        break;
        case 9:
            cout << "Saliendo..."<<endl;
        break;
        default:
            cout << "Esa opción no está disponible, favor de ingresar otro número" << endl;
        break;
        }
    }while(eleccion != 9);
    return 0;
}
