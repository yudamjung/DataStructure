#include <iostream>
using namespace std;

int main() {
    int score[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    // score == &score == &score[0] : 배열명 == &배열명 == &배열첫원소
    cout << score << ' ' << &score << ' ' << &score[0] << '\n' << '\n';
    
    for (int i=0; i<10; i++) {
        // sizeof(int) 만큼 주소 증가
        // &score[n] == score + n. n = sizeof(dataType)
        cout << &score[i] << " : " << score + i << endl;        // 주소에 접근
        cout << score[i] << " : " << *(score + i) << endl;      // 값에 접근
        cout << '\n';
    }
    
    return 0;
}
