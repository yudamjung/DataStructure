#include <iostream>
using namespace std;

int main() {
    int score[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int* ptr;
    
    ptr = score; // int* ptr = &score[0]
    cout << ptr << '\n' << '\n';
    
    for (int i=0; i<10; i++) {
        cout << ptr + i << " : " << score + i << endl;              // 주소에 접근
        cout << ptr[i] << " : " << *(ptr+i)<< " : " << score[i]  << " : " << *(score + i) << endl;                // 값에 접근
    }
    
    return 0;
}
