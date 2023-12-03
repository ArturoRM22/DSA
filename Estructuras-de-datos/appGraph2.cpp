#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Graph{
private:
    int V; // número de vértices
    int E; // número de Edges
    list<int> *adj; // Lista de adyacencia
    int d; // dirijido o no dirijido 
public:
    Graph(int V,int E, int d);
    void addEdge(int v, int w);
    void DFS(int s); // Búsqueda en profundidad
    void BFS(int s);
    void loadGraph();
    bool isTree();
    void topologicalSort();
    bool bipartiteGraph();
    bool isVisited(bool* visited_array);
    void displayList();
};

Graph::Graph(int V,int E, int d) {
    this->V = V;
    this->E = E;
    this->d = d;
    adj = new list<int>[V];
    loadGraph();
}

void Graph::addEdge(int v, int w) {
    if(d == 0){
        adj[v].push_back(w);
        adj[w].push_back(v); 
    }
    else{
    adj[v].push_back(w);
    }
}

void Graph::loadGraph(){
    if(V>=0&&E>=0){
    int num1;
    int num2;
    for(int i=0; i<E; i++){
            cout<<"Ingresa el nodo al que le quieres añadir una conexion"<<endl;
            cin>>num1;
            cout<<"Ingresa el nodo con el que lo quieres conectar"<<endl;
            cin>>num2;
            addEdge(num1, num2);
        }
    }else{
        cout<<"Los valosres de n y m no son enteros positivos"<<endl;
    }
}

void Graph::DFS(int s) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    stack<int> stack;
    stack.push(s);
    while (!stack.empty()) {
        s = stack.top();
        stack.pop();
        if (!visited[s]) {
            cout << s << " ";
            visited[s] = true;
        }
        for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    queue<int> queue;
    queue.push(s);
    while (!queue.empty()) {
        s = queue.front();
        queue.pop();
        if (!visited[s]) {
            cout << s << " ";
            visited[s] = true;
        }
        for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                queue.push(*i);
            }
        }
    }
}

void Graph::displayList(){
    cout << "--------------------------------" << endl;
    cout << "Lista de adyacencia" << endl;
    for(int i = 0; i < V; i++){
        cout << "vertice: " <<i<<" [";
        for(list<int>::iterator j = adj[i].begin(); j!= adj[i].end() ; j++){
            cout << *j <<" "; 
        }
        cout <<"]"<< endl;
    }
    cout << "--------------------------------" << endl;
}

bool Graph::isTree(){
    int s = 0;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    stack<int> stack;
    stack.push(s);
    while (!stack.empty()) {
        s = stack.top();
        stack.pop();
        if (!visited[s]) {
            visited[s] = true;
        }else{
            cout <<"El grafo no puede tener ciclos";
            return false;
        }
        for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
    for(int n=0; n<V;n++){
        if(visited[n]==false){
            return false;
        }
    }
    return true;
}

bool Graph::bipartiteGraph(){
    int s = 0;
    bool *visited = new bool[V];
    bool *colors = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        if(i % 2 == 0){
            colors[i] = false;
        }else if(i == 0){
            colors[i] = false;
        }
        else{
            colors[i] = true;
        }
    }
    queue<int> queue;
    queue.push(s);
    while (!queue.empty()) {
        s = queue.front();
        queue.pop();
        if (!visited[s]) {
            visited[s] = true;
        }
        for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                queue.push(*i);
                if(colors[s] == colors[*i]){
                    return false;
                }
            }
        }
    }
    return true;
}

void Graph::topologicalSort(){
    if(d == 0){
        cout << "El grafo no puede ser no dirijido" << endl;
        return;
    }
    bool* visited = new bool[V]; // nodos ya explorados
    // primeramente inicializar con todas las posiciones del array(que a su vez representan cada nodo en el gráfo) en false. 
    for(int i = 0; i< V; i++){
        visited[i] = false;
    }
    stack<int> dfs; // para DFS normal
    stack<int> tp;
    for(int s = 0; s < V;s++){
        if(!visited[s]){
            dfs.push(s);
            while(!dfs.empty()){
            s = dfs.top(); // actualizar el nodo actual
            if(!visited[s]){
                visited[s] = true;
            }
            for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    dfs.push(*i);
                }
            }
            if(dfs.top() == s){
                tp.push(s);
                dfs.pop();
            }
        }
    }
    }
    
    cout << "[";
    for (int i = 0; i < V;i++){
        cout << tp.top()<< " ";
        tp.pop();
    }
    cout << "]";
}

bool Graph::isVisited(bool* visited_array){
    for(int i = 0; i < V;i++){
        if(!visited_array[i]){
            cout << "no todos visitados" << endl;
            cout <<"visited: "<< visited_array[i] << endl;
            return false;
        }

    }
    cout << "todos visitados" << endl;
    return true;
}

int main() {
    int V, E, e;
    cout<<"Dime el numero de V para tu grafo"<<endl;
    cin>>V;
    cout<<"Dime el numero de conexiones en tu grafo"<<endl;
    cin>>E;
    cout <<"Dirijido. (1)"<<endl;
    cout <<"No dirijido. (0)"<<endl;
    cin>>e;
    Graph g(V, E, e);
    g.displayList();
    cout<<"Tree: "<<g.isTree() << endl;
    cout<<"Bipartita: "<<g.bipartiteGraph() << endl;
    cout <<"Orden topolígico: " << endl;
    g.topologicalSort();
    cout<<endl;
}
