#include <iostream>
using namespace std;

// 후위 표기식 계산 알고리즘
// 1. 개괄호 만나면 무시
// 2. 피연산자를 만나면 스택에 ㅔush
// 3. 연산자를 만나면 필요한 개수의 피연산자를 스택에서 pop
// 4. 연산결과를 다시 스택에 Push
// 5. 수식이 끝나면 마지막으로 스택을 pop 하여 출력

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
    cout << "후위 수식 입력 : ";
    cin.getline(str, 100, '\n');
    
    for (int i=0; i<strlen(str); i++) {
        char opr1, opr2;
        char ch = str[i];
        
        if(ch == ' ') continue;     // 공백이 입력되는 경우 처리
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {     // 사칙연산자가 아니면 (피연산자이면)
                s1.push(ch - '0');              // push => 아스키코드 6 -> 숫자문자 6
        }
        else if (ch == '+') {
            opr2 = s1.pop();
            opr1 = s1.pop();
            s1.push(opr1 + opr2);
        }
        else if (ch == '-') {
            opr2 = s1.pop();
            opr1 = s1.pop();
            s1.push(opr1 - opr2);
        }
        else if (ch == '*') {
            opr2 = s1.pop();
            opr1 = s1.pop();
            s1.push(opr1 * opr2);
        }
        else if (ch == '/') {
            opr2 = s1.pop();
            opr1 = s1.pop();
            s1.push(opr1 / opr2);
        }
    }
    
    cout << str << " = " << s1.pop() << endl;
    
    return 0;
}
