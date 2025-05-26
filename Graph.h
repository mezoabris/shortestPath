//
// Created by mezoabris on 20/05/25.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
    string target;
    string line;
    int weight;
};

class Graph {
    public:
    Graph();
    ~Graph() = default;
    void addEdge(string &from, string& to,  string& line, int weight);
    void findPath(const string & filename, const string & from, const string & to);
    void printGraph();
    void read_file(const string& filename);
    private:

    unordered_map<string, vector<Edge>> graph;
    unordered_map<string, bool> visited;
    unordered_map<string, int> distance;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    unordered_map<string, string> previous;

};
#endif //GRAPH_H
