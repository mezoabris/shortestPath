//
// Created by mezoabris on 20/05/25.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
using namespace std;

class Graph {
    public:
    Graph();
    ~Graph();
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    void printGraph();
    private:
    vector<vector<int> > graph;

};
#endif //GRAPH_H
