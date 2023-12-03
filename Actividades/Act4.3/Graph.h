#include <iostream>
#include <set>
#include <stack>
#include <queue>
using namespace std;

class Graph{
public:
    int V; // número de vértices
    int E; // número de Edges
    set<int> *adj; // Lista de adyacencia
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s); // Búsqueda en profundidad
    void BFS(int s);
    void loadGraph(int n, int m);
    bool isTree();
    void topologicalSort();
    void topologicalSortUtil(int v, bool visited[], stack<int> &stack);
    bool bipartiteGraph();
    void displayList();
};

