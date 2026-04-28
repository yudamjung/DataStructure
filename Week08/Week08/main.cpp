#include <iostream>
using namespace std;

// 스택을 이용한 괄호 검사

class MyStack {
public:
    int data[100];
    int top;
    
    MyStack() { top = -1; }
    
    bool is_stack_empty() {
        return (top == -1);
    }
    
    void push(int item) {
        data[++top] = item;
    }
    
    int pop () {
        return data[top--];
    }
};

bool check_matching(char str[]) {
    MyStack s1;
    
    for (int i=0; i < strlen(str); i++) {       // 입력된 글자를 한 글자씩 순회
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {        // 개괄호면 push
            s1.push(str[i]);
        }
        else if (str[i] == ')') {
            if (s1.pop() != '(') return false;
        }
        else if (str[i] == ']') {
            if (s1.pop() != '[') return false;
        }
        else if (str[i] == '}') {
            if (s1.pop() != '{') return false;
        }
    }
    if (s1.is_stack_empty()) return true;
    else return false;
}
    
int main() {
    char str[100];
    cin.getline(str, 100, '\n');    // (버퍼 시작 주소, 버퍼 최대 크기, 구분자)
    
    if (check_matching(str)) {
        cout << "괄호 검사 성공" << endl;
    }
    else cout << "괄호 검사 실패" << endl;
    
    return 0;
}
