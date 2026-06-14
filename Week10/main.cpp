#include <iostream>
using namespace std;

// Queue 연결리스트 방식으로 구현

class QNode {
public:
    int data;
    QNode *link;
};

class MyQueue {
public:
    QNode *front, *rear;
    
    MyQueue() {
        front = rear = NULL;
    }
    
    // Queue가 비어있는지 확인하는 메서드 - front 나 rear가 NULL
    bool is_queue_empty() {
        return (front == NULL);     // rear == NULL
    }
    
    // Queue에 원소를 삽입하는 메서드
    void enQueue(int item) {
        QNode *new_node = new QNode;
        new_node -> data = item;
        new_node -> link = NULL;
        
        if (is_queue_empty()) {         // 첫 노드이면 특별하게 처리
            front = rear = new_node;
        }
        else {
            rear -> link  = new_node;
            rear = new_node;
        }
    }
    
    // Queue의 원소를 삭제하는 메서드
    int deQueue() {
        if (is_queue_empty()) {
            cout << "QUEUE EMPTY";
            return -1;
        }
        else {
            int item = front->data;
            front = front -> link;
            if (front == NULL) rear = NULL;
            return item;
        }
    }
    
    // Queue의 요소들을 출력하는 메서드
    void queue_list() {
        if (is_queue_empty()) { cout << "큐가 비어있습니다."; }
        for (QNode* list = front; list != NULL; list = list->link) {
            cout << ' ' << front-> data << ' ';
        }
};


int main() {
    MyQueue q1;
    
    q1.enQueue(10);
    q1.enQueue(10);
    q1.enQueue(10);
    q1.enQueue(10);
    
    
    
    return 0;
} //아니 메인함수에 
