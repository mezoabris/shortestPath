#include <iostream>
#include "Graph.h"
#include <string>
using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    string  filename;
    string from;
    string to;
    cout<<"Enter the file name, starting point and desired destination: ";
    try {
        cin>>filename>>from>>to;
    Graph graph;
    graph.findPath(filename, from, to);


    // graph.printGraph();
    }catch (string e) {
        cout<<"cant open file: "<<e<<endl;
    }
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}