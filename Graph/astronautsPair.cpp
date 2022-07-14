#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }

    int dfsHelper(int source, bool *visited, int &num)
    {
        visited[source] = true;
        num++;
        for (auto node : l[source])
        {
            if (!visited[node])
            {
                dfsHelper(node, visited, num);
            }
        }
        return num;
    }


    int count_pairs()
    {
        // vector<vector<int>> len;
        bool *visited = new bool[V]{0};
        int num = 0;
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            dfsHelper(i, visited, num);
            ans.push_back(num);
            // cout << num << " ";
            num = 0;
        }

        int pair = (V * (V - 1)) / 2;

        for (auto i : ans)
        {
            pair -= (i * (i - 1)) / 2;
        }
        return pair;
    }
};

int main()
{
    vector<vector<int>> astronauts = {{0, 1}, {2, 3}, {0, 4}};
    int n = 5;
    Graph g(n);
    for (auto i : astronauts)
    {
        int a = i[0];
        int b = i[1];
        g.addEdge(a, b);
    }
    cout << g.count_pairs();
    return 0;
}