//
// Created by mezoabris on 24/05/25.
//
#include "Graph.h"

#include <limits.h>

Graph::Graph() {
    cout<<"Graph created"<<endl;

}
void Graph::addEdge(string &from, string &to, string &line, int weight) {

    graph[from].push_back({to, line, weight});
    graph[to].push_back({from, line, weight});
    visited[from] = false;
    visited[to] = false;
    distance[from] = INT_MAX;
    distance[to] = INT_MAX;

}
void Graph::printGraph() {
    for (const auto& [source, edges] : graph) {
        std::cout << "Station: " << source << "\n";
        std::cout << "  Connections:\n";

        for (const Edge& edge : edges) {
            std::cout << "    -> " << edge.target
                      << " (Line: " << edge.line
                      << ", Time: " << edge.weight << " mins)\n";
        }

        std::cout << "\n";
    }
}



void Graph::read_file(const string& filename){
    ifstream file("../"+filename);
    if(!file.is_open()){
    throw (filename);

    }
    string line;
    //this part breaks the whole text data into SINGLE LINES
    while(getline(file,line)){
        if(line.empty()) continue;

    //istringstream make
    istringstream ss(line);
    string token;
    ss >> token;
    string lineName = token.substr(0, token.size()-1);

    string station1, station2;
    int duration;
    bool first = true;
    while(ss>> ws && ss.peek()== '"'){
    ss.ignore();
    getline(ss, station2, '"');

    if(!first){
        addEdge(station1, station2, lineName, duration);
    }
    station1 = station2;
    first = false;
    if(!(ss>>duration)){
    break;
    }

    }
    }
    file.close();
}
void Graph::findPath(const string &filename, const string &from, const string &to) {
    this->read_file(filename);
    vector<Edge> path = graph[from];

    int minWeg = 0;
    for (auto station : graph) {
        distance[station.first] = INT_MAX;
        visited[station.first] = false;
    }
    distance[from] = 0;
    pq.push({distance[from], from});

    while(!pq.empty()) {
        auto [currDist, station] = pq.top();
        pq.pop();
        if (visited[station]) {
            continue;
        }
        visited[station] = true;
        if (station == to) {
            break;
        }
        for (auto neighbor : graph[station]) {
            if (!visited[neighbor.target]) {
                cout<<"currently visiting "<<neighbor.target<<endl;
                int new_distance = currDist + neighbor.weight;
                cout<<"distance from "<<from<<" to "<<neighbor.target<<" is "<<new_distance<<endl;
                if (new_distance < distance[neighbor.target]) {
                    cout<<"found new best distance from "<<from<<" to "<<neighbor.target<<" is :"<<new_distance<<" which is better than the previous: "<<distance[neighbor.target]<<endl;
                    distance[neighbor.target] = new_distance;
                    pq.push({distance[neighbor.target], neighbor.target});
                    previous[neighbor.target] = station;
                }else {
                cout<<" new distance from "<<from<< " to "<<neighbor.target<< " is "<< new_distance<<" but its worse or same than previous"<<distance[neighbor.target] <<endl;
                }
            }else {
            cout<<"skipping "<<neighbor.target<<" since we already visited it"<<endl;
            }
        }
    }
    if (distance[to] == INT_MAX) {
        cout<<"NO ROUTE FOUND FROM "<<from<<" TO "<<to<<endl;
        return;
    }
    vector<string> path_print;
    for (string at = to; at != from ; at = previous[at]) {
        path_print.push_back(at);
    }
    path_print.push_back(from);
    reverse(path_print.begin(), path_print.end());
    cout << "Shortest path from " << from << " to " << to << " (" << distance[to] << " min):\n";
    for (size_t i = 0; i < path_print.size() - 1; ++i) {
        const string& current = path_print[i];
        const string& next = path_print[i+1];

        for (const Edge& edge : graph[current]) {
            if (edge.target == next) {
                cout << current << " --(" << edge.line << ", " << edge.weight << "min)--> " << next << endl;
                break; // assuming no duplicate edges
            }
        }
    }




}

