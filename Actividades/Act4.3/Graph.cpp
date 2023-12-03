#include "Graph.h"

Graph::Graph(int V) {
    this->V = V;
    adj = new set<int>[V];
    //loadGraph(V,E,this->adj);
}

void Graph::addEdge(int v, int w) {
    adj[v].insert(w);
    this->E++;
}

void Graph::loadGraph(int n, int m){
    if(n>=0&&m>=0){
    int num1;
    int num2;
    for(int i=0; i<m;i++){
            cout<<"Ingresa el nodo al que le quieres añadir una conexion"<<endl;
            cin>>num1;
            cout<<"Ingresa el nodo con el que lo quieres conectar"<<endl;
            cin>>num2;
            addEdge(num1,num2);
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
        for (set<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
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
        for (set<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
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
        for(set<int>::iterator j = adj[i].begin(); j!= adj[i].end() ; j++){
            cout << *j <<" "; 
        }
        cout <<"]"<< endl;
    }
    cout << "--------------------------------" << endl;
}

bool Graph::isTree(){
    int s = 0;
    bool *visited = new bool[V];
    if(E>=V){
        return false;
    }
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
            return false;
        }
        for (set<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
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
        for (set<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
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
 bool *visited = new bool[V];
 stack<int> stack;
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    for(int s=0; s < V; s++){
     if(!visited[s]){
        topologicalSortUtil(s,visited,stack);
     }
    }
    while(!stack.empty()){
        cout<<stack.top()<< " ";
        stack.pop();
    }
    cout<<endl;
}
void Graph::topologicalSortUtil(int s, bool visited[], stack<int> &stack){
    visited[s]=true;
    for(set<int>::iterator i = adj[s].begin(); i!= adj[s].end();i++){
        if(!visited[*i]){
            topologicalSortUtil(*i,visited,stack);
        }
    }
    stack.push(s);
}