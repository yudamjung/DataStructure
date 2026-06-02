#include <iostream>
#include <string>
using namespace std;

const int MAX_NODE = 8;

class Edge {
public:
    int node_number;
    Edge *link;
    // Constructor
    Edge(int number) {
        node_number = number;
        link = NULL;
    }
};

class Node {
public:
    string node_name;
    Edge *list;
    // Constructor
    Node(string new_name) {
        node_name = new_name;
    }
};

int main() {
    
    return 0;
}
