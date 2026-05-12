#include <iostream>
using namespace std;

// Queue 배열 방식으로 구현

const int MAX_SIZE = 100;

class MyQueue {
public:
    int data[MAX_SIZE];
    int front, rear;
    
    MyQueue() {
        // constructor
        front = rear = -1;
    }
    
    // Queue 가 꽉 찼는지 확인하는 메서드
    bool is_queue_full() {
//        if(rear = MAX_SIZE - 1) return true;
//        else return false;
        return (rear == MAX_SIZE - 1);
    }
    
    // Queue가 비어있는지 확인하는 메서드
    bool is_queue_empty() {
//        if (front == rear) return true;
//        else return false;
        return (front == rear);
    }
    
    // Queue에 원소를 삽입하는 메서드
    void enQueue(int item) {
        // Queue가 full 인지 검사
        if (is_queue_full()) {
            cout << "QUEUE OVERFLOW" << endl;
        }
        else data[++rear] = item;
    }
    
    // Queue의 원소를 삭제하는 메서드
    int deQueue() {
        // Queue가 empty 인지 검사
        if (is_queue_empty()) {
            cout << "QUEUE UNDERFLOW" << endl;
            exit(1);
        }
        else return data[++front];
    }
    
    // Queue의 요소들을 출력하는 메서드
    void queue_list() {
        if (is_queue_empty()) { cout << "큐가 비어있습니다."; }
        for (int i = front + 1; i <= rear; i++) {
            cout << ' ' << data[i] << ' ';
        }
    }
    
};


int main() {
    MyQueue q1;
    
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.deQueue();
    
    q1.queue_list();
    return 0;
}
