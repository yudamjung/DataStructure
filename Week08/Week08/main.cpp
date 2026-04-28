#include <iostream>
using namespace std;

// Stack & full, empty check & push(), pop()
const int MAX_SIZE = 100;

class MyStack {
public:
    int data[MAX_SIZE];
    int top;                    // Stack Pointer, index
    
    MyStack() { top = -1; }     // Constructor
    
    bool is_stack_empty() {
//        if (top == -1) return true;
//        else return false;
        // 간소화 버전
        return (top == -1);
    }
    
    bool is_stack_full() {
//        if (top == (MAX_SIZE - 1)) return true;
//        else return false;
        // 간소화 버전
        return (top == (MAX_SIZE - 1));
    }
    
    void push(int item) {
        if (is_stack_full()) {
            cout << "STACK OVERFLOW ERROR" << endl;
            exit(1);
        }
        else {
//            top ++;
//            MyStack[top] = x;
            data[++top] = item;
        }
    }
    
    //
    int pop() {
        if (is_stack_empty()) {
            cout << "STACK UNDERFLOW ERROR" << endl;
            exit(1);
        }
        else return data[top--];
//        else {
//            x = MyStack[top];
//            top--;
//            return x;
//        }
    }
    
    // Stack 출력 함수
    void stack_status () {
        cout << "TOP = " << top << endl;
        for (int i = top; i >= 0; i--) {
            cout << data[i] << '\n';
        }
    }
};

int main() {
    MyStack s1;
    MyStack *s2 = &s1;
    
    s1.push(10);
    s2 -> push(15);
    s1.push(20);
    s1.push(30);
    s1.pop();       // 30을 pop
    s1.push(40);
    
    s1.stack_status();
}
