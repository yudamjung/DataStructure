#include <iostream>
#include <queue>
#include <deque>
using namespace std;

const int MAX_SIZE = 10;

class MyQueue {
public:
    int data[MAX_SIZE];
    int front, rear;
    
    MyQueue () {    // constructor
        front = rear = 0;
    }
    
    bool is_empty() {
        // if (front == rear) return true;
        // else return false;
        return (front == rear);
    }
    
    bool is_full() {
        // if (front == (rear + 1) % MAX_SIZE) return true;
        // else return false;
        return (front == (rear + 1) % MAX_SIZE);
    }
    
    void enQueue (int x) {
        if (is_full()) { cout << "ERROR: QUEUE OVERFLOW"; return; }
        else {
            // 일반 큐 rear++; data[rear] = x; => data[++rear] = x;
            rear = (rear + 1) % MAX_SIZE; // ⭐️
            data[rear] = x;
        }
    }
    
    int deQueue() {
        if (is_empty()) { cout << "ERROR : QUEUE UNDERFLOW"; return -1; }
        else {
            /* 일반 큐
            front++;
            return data[front];
            => return data[++front]; */
            front = (front + 1) % MAX_SIZE;
            return data[front];
        }
    }
    
    void printQueue() {
        cout << "원형 큐 상태 출력" << '\n';
        // front가 rear보다 앞에 있는 경우
        if (front <= rear) {
            for (int i = front + 1; i <= rear; i++) {
                cout << data[i] << ' ';
            }
        }
        // rear가 front보다 앞에 있는 경우
        else {
//            for(int i = front + 1; i <= MAX_SIZE - 1; i++) {
//                cout << data[i] << ' ';
//            }
//            for (int i = 0 ; i<= rear; i++) {
//                cout << data[i] << ' ';
//            }
            for (int i = front + 1; i <= rear + MAX_SIZE; i++) {
                cout << data[i % MAX_SIZE] << endl;
            }
        }
    }
};

int main() {
    MyQueue q1;
    
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.enQueue(40);
    q1.enQueue(50);
    q1.deQueue();
    q1.printQueue();
    cout << endl;
    
    // STL 활용
    queue<int> q2;
    q2.push(10);
    q2.push(20);
    q2.push(30);
    q2.push(40);
    q2.push(50);
    q2.push(60);
    q2.pop();
    
    cout << '\n' << "STL 제공 큐 사용" << endl;
    while (!q2.empty()) {
        cout << q2.front() << ' ';
        q2.pop();
    }
    cout << endl;
    
    
    // STL 활용 Deque
    deque<int> q3;
    // insert
    // push_back, push_front, insert ... 찾아보기
    
    return 0;
}
