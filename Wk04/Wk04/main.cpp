#include <iostream>
using namespace std;

int main() {
    int score[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    for (int i=0; i<10; i++) {
        cout << &score[i] << '\n';
    }
    
    return 0;
}
