#include <iostream>
using namespace std;

// 후위 표기식 변환 알고리즘
// 1. 개괄호 만나면 무시
// 2. 피연산자를 만나면 출력
// 3. 연산자를 만나면 스택에 push
// 4. 폐괄호를 만나면 스택에서 Pop
// 5. 수식이 끝나면 스택이 empty 될 때까지 pop

const int MAX_SIZE = 100;

class MyStack {
public:
    int data[MAX_SIZE];
    int top;
    
    MyStack() {
        // constructor
        top = -1;
    }
    
    void push(int item) {
        // isStackFull 검사
        data[++top] = item;
    }
    
    int pop() {
        // isStackEmpty 검사
        return data[top--];
    }
};


int main() {
    MyStack s1;
    char str[100];
    cout << "중위 수식 입력 : ";
    cin.getline(str, 100, '\n');
    
    for (int i=0; i<strlen(str); i++) {
        char ch = str[i];
        
            
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {     // 사칙연산 이면
            s1.push(ch);              // push
        }
        else if (ch == ')') {         // 폐괄호면 pop하고 출력한다
            // 단, 괄호는 소괄호만 사용한다고 가정
            cout << (char)s1.pop();
        }
        else if (ch == '(') {         // 개괄호는 무시하고 건너뛴다
            continue;
        }
        else {                        // 피연산자이면
            cout << ch;        // 그냥 출력한다
        }
    }
    
    return 0;
}
