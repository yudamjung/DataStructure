#include <iostream>
#include <string>
using namespace std;

#define NODE_NUM 7 // 노드의 개수
#define INF 9999 // 무한대

int Weight[NODE_NUM][NODE_NUM] = {
    0, 7, INF, INF, 3, 10, INF,
    7, 0, 4, 10, 2, 6, INF,
    INF, 4, 0, 2, INF, INF, INF,
    INF, 10, 2, 0, 11, 9, 4,
    3, 2, INF, 11, 0, INF, 5,
    10, 6, INF, 9, INF, 0, INF,
    INF, INF, INF, 4, 5, INF, 0
};

 

bool S[NODE_NUM] = { }; // 모두 0으로 초기화

int Distance[NODE_NUM]; // 최단거리 저장


int choose_best_one() { // S[i] 가 0인 노드 중, 가장 작은 distance 값을 갖는 노드를 best_node 로 선택
    int Min = INF;
    int best_node = 0;  // u 를 의미
    
    for (int i = 0; i < NODE_NUM; i++) {
        // 가장 작은 distance 값을 갖는 노드를 best_node로 선택
        if (S[i] != 0) continue;
        if (Distance[i] < Min) {
            Min = Distance[i];
            best_node = i;
        }
    }
    
    return best_node;
}


void shortest_path(int v) {         // v는 출발점, 다른 노드의 Distance[] 값 계산
    // 배열 초기화
    for (int i=0; i < NODE_NUM; i++) {
        // S[i] = 0;
        Distance[i] = Weight[v][i];     // v 에서 i 까지의 최단거리, 초기화
    }
    
    S[v] = 1;               // 공식 발표 (v 를 서울이라고 가정)
    Distance[v] = 0;        // 서울 -> 서울 최단 거리는 0
    
    for (int i = 0; i < NODE_NUM - 2; i++) {        // 다음 공식 발표할 대상 (최단거리인 인천) 을 찾음
        int u = choose_best_one();                  // 서울에서 최단거리는 인천
        S[u] = 1;
        
        for (int w = 0; w < NODE_NUM; w++) {
            if (S[w] == 0 && Distance[w] > Distance[u] + Weight[u][w]) {
                Distance[w] = Distance[u] + Weight[u][w];
            }
            
            // 이렇게도 작성할 수 있음
            // if (S[i] != 0) continue;
            // Distance[w] = min(Distance[w], Distance[u] + Weight[u][w]);
            
        }
    }
}
 

int main() {
    int start = 0;
    
    shortest_path(start); // shotest_diastance(start)
    
    cout << "출발점은 " << start << endl;
    cout << "도착점 번호를 입력하시오 : ";
    int dest;
    cin >> dest;
    
    cout << "출발점 " << start << " 부터 도착점 " << dest << "까지의 최단 거리는  " <<  Distance[dest] << endl;
}
