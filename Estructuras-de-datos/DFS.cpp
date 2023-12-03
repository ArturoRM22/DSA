#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
    private:
        int V; //number of vertices
        list<int> *adj; // Adj list
    public:
        Graph(int v);
        void addEdge(int v, int w);
        void DFS(int s); // depth first search
};

Graph::Graph(int V){
    this -> V = V;
    adj = new list<int> [V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    //adj[w].push_back(v);
}

void Graph::DFS(int s){
    bool *visited = new bool[V];

    for(int i = 0; i < V ; i++){
        visited[i] = false;
    }

    // create stack
    stack<int> stack;
    stack.push(s);

    while(!stack.empty()){
        s = stack.top();
        stack.pop();

        if(!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }

        for(list<int>::iterator i = adj[s].begin(); i!= adj[s].end() ; i++){
            if(!visited[*i]){
                stack.push(*i);
            }
        }
    }


}

int main(){
    Graph g(6);// graph 0 to 4
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 0);
    g.DFS(0);
    return 0;
}


