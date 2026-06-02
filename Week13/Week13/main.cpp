#include <iostream>
#include <string>
using namespace std;


const int NODE_NUM = 8; // 노드의 개수

int adj[NODE_NUM][NODE_NUM] =
{
    0, 1, 1, 0, 0, 0, 0, 0,
    1, 0, 0, 1, 1, 0, 0, 0,
    1, 0, 0, 0, 0, 1, 1, 0,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 1, 1, 1, 0
};

string name[NODE_NUM] = { "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8" };

bool visited[NODE_NUM] = {};    // 모두 0으로 초기화

// Recursion
void DFS(int v) {
    if (visited[v]) return;                 // 방문했으면
    // 방문하지 않았으면
    visited[v] = 1;
    cout << name[v] << "을 방문함" << endl;
    
    for (int i=0; i<NODE_NUM; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);     // recursion
        }
    }
}

int main() {
    DFS(0);     // 0 번 부터 시작
    return 0;
}
