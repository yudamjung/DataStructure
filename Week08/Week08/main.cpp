#include <iostream>
using namespace std;

// 연결리스트로 구현하는 스택
class Node {
public:
    int data;
    Node *link;
};

class MyStack {
public:
    Node *top;                  // Stack Pointer, Pointer 변수, head 역할
    MyStack() { top = NULL; }
    
    bool is_stack_empty() {
        return (top == NULL);
    }
    
    void push(int item) {       // 단순 연결리스트에서 첫 노드 삽입하기
        Node *new_node = new Node;
        new_node -> data = item;
        //new_node -> link = NULL;
        
        // 단순 연결 리스트의 첫 노드로 삽입
        new_node -> link = top;
        top = new_node;
    }
    
    int pop() {
        if (is_stack_empty()) {
            cout << "UNDERFLOW" << endl;
            exit(1);
        } else {
            int value = top->data;
            Node* oldTop = top;
            top = top->link;
            delete oldTop;
            return value;
        }
    }
    
    // Stack 출력 함수
    void stack_status () {
        if (is_stack_empty()) {
            cout << "Stack is empty" << '\n';
            return;
        }
        else {
            for (Node *list = top; list != NULL; list = list->link) {
                cout << list->data;
                if (list->link) cout << " -> ";
            }
        }
        cout << '\n';
    }
};

int main() {
    MyStack s1;
    
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();       // 30을 pop
    s1.push(40);
    
    s1.stack_status();
}
