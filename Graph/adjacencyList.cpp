#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        for(int i = 0; i < V; i++){
            cout << i << "-->";
            for(auto node:l[i]){
                cout << node << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source){
        cout << "BFS: ";
        int visited[V];
        memset(visited, 0, sizeof visited);
        queue<int> que;
        que.push(source);
        visited[source] = 1;
        while(!que.empty()){
            int temp = que.front();
            que.pop();
            for(auto node: l[temp]){
                if(visited[node] == 0){
                    que.push(node);
                    visited[node] = 1;
                }
            }
            cout << temp << " ";
        } 
       cout << endl;
    }

    void dfsHelper(int node, bool *visited){
        visited[node] = true;
        //Make dfs call on all unvisited neighbours
        cout << node << ", ";
        for(int nbr:l[node]){
            if(!visited[nbr]){
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

    void dfs(int source){
        bool *visited = new bool[V]{0};
        dfsHelper(source, visited);
    }

};

int main(){
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 0);
    g.addEdge(4, 5);

    g.printAdjList();
    
    // g.bfs(0);

    g.dfs(0);
    return 0;
}