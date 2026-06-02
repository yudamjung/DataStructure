#include <iostream>
#include <string>
#include <stack>
using namespace std;

// recursive version

const int NODE_NUM = 8;

class Edge {  // EDGE 정보
public:
    int vertex_number;
    Edge* link;
};


class Node { // VERTEX 정보
public:
    string name;
    Edge* list; // 인접한 노드 목록을 연결리스트로 정리`
    Node(string new_name) {
        name = new_name;
        list = NULL;
    }
} *vertex[NODE_NUM];

int visited[NODE_NUM] = {};

void add_Edge(int from, int to) {
    Edge* new_edge = new Edge;
    new_edge->vertex_number = to;
    new_edge->link = vertex[from]->list;
    vertex[from]->list = new_edge;
}

// 입접 리스트 구성
void makeGraph() {
// 인접리스트 방식 - 그래프 구성 - 배열 0 부터 사용
    vertex[0] = new Node("V1"); // v2, v3
    add_Edge(0, 1);add_Edge(0, 2);

    vertex[1] = new Node("V2"); // v1, v4, v5
    add_Edge(1, 0); add_Edge(1, 3);add_Edge(1, 4);

    vertex[2] = new Node("V3"); // v1, v6, v7
    add_Edge(2, 0);add_Edge(2, 5);add_Edge(2, 6);

    vertex[3] = new Node("V4"); // v2, v8
    add_Edge(3, 1);add_Edge(3, 7);

    vertex[4] = new Node("V5"); // v2, v8
    add_Edge(4, 1);add_Edge(4, 7);

    vertex[5] = new Node("V6"); // v3, v8
    add_Edge(5, 2);add_Edge(5, 7);

    vertex[6] = new Node("V7"); // v3, v8
    add_Edge(6, 2);add_Edge(6, 7);

    vertex[7] = new Node("V8"); // v4, v5, v6, v7
    add_Edge(7, 3);add_Edge(7, 4);add_Edge(7, 5);add_Edge(7, 6);
}

stack<int> MyStack;

// Stack (STL) + Adjacent List 활용 (No Recursion)
void DFS(int v) {
    MyStack.push(v);
    while(!MyStack.empty()) {
        v = MyStack.top();
        MyStack.pop();
        
        if(visited[v]) continue;
        visited[v] = 1;
        cout << vertex[v]->name << "을 방문함" << endl;
        
        for (Edge *w = vertex[v]->list; w != NULL; w = w->link) {
            if (!visited[w->vertex_number]) {
                MyStack.push(w->vertex_number);     // recursion 대신 push
            }
        }
    }
    
    // Adjacent List + Recursion + DFS 에서의 DFS 함수 내부
//    if(visited[v]) return;
//    
//    // 방문한 적 있으면
//    visited[v] = 1;
//    cout << vertex[v]->name << "을 방문함" << endl;
//
//    for (Edge *w = vertex[v]->list; w != NULL; w = w->link) {
//        if (!visited[w->vertex_number]) {
//            DFS(w->vertex_number);
//        }
//    }
}

int main() {
    makeGraph();
    DFS(0);
    return 0;
}
