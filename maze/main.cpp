#include <iostream>
using namespace std;

const int MAX_SIZE = 6;

char maze[MAX_SIZE][MAX_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'}
};

class Element {
public:
    int r, c;
    Element() {
        r = c = 0;
    }
    Element(int row, int col) {
        r = row;
        c = col;
    }
};

class Stack {
    Element data[MAX_SIZE * MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(Element e) {
        if (top < MAX_SIZE * MAX_SIZE - 1) {
            data[++top] = e;
        }
    }
    Element pop() {
        if (top >= 0)
            return data[top--];
        return Element(-1, -1);
    }
    bool is_empty() { return top == -1; }
};

// 미로를 출력하는 함수
void printMaze(char maze[MAX_SIZE][MAX_SIZE]) {
    cout << "\n";
    for (int r = 0; r < MAX_SIZE; r++) {
        for (int c = 0; c < MAX_SIZE; c++) {
            cout << maze[r][c];
        }
        cout << endl;
    }
}


bool isMovable(int r, int c) {
    return r >= 0 && r < MAX_SIZE && c >= 0 && c < MAX_SIZE && (maze[r][c] == '0' || maze[r][c] == 'x');
}

void maze_search(int sr, int sc) {
    Stack s;
    Element here(sr, sc);
    s.push(here);
    bool found = false; // 미로 탈출여부를 저장하는 변수

    while (!s.is_empty()) {
        here = s.pop();
        int r = here.r, c = here.c;

        if (maze[r][c] == 'x') {
            printMaze(maze);
            found = true;
            break;
        }
        maze[r][c] = '.'; // 지나온 경로를 .으로 표시
        printMaze(maze);

        // 상하좌우를 스택에 저장
        if (isMovable(r - 1, c)) s.push(Element(r - 1, c));
        if (isMovable(r + 1, c)) s.push(Element(r + 1, c));
        if (isMovable(r, c - 1)) s.push(Element(r, c - 1));
        if (isMovable(r, c + 1)) s.push(Element(r, c + 1));
    }

    if (found) cout << "성공" << endl;
    else cout << "실패" << endl;
}

int main() {
    int sr = 0, sc = 0;
    for (int r = 0; r < MAX_SIZE; ++r) {
        for (int c = 0; c < MAX_SIZE; ++c) {
            if (maze[r][c] == 'e') { sr = r; sc = c; }
        }
    }
    maze_search(sr, sc);
    return 0;
}
