#include <iostream>
using namespace std;

int main() {
    // 2 Dimension Array w. pointer
    int score[2][3] = { {10,20,30}, {40,50,60}};
    
//    for (int i=0; i<2; i++) {
//        for (int j=0; j<3; j++) {
//            cout << "Address of 2D Array : " << &score[i][j] << endl;
//            cout << "Value of 2D Array : " << score[i][j] << endl;
//        }
//    }
    
    cout << score[0] << endl;       // 2차원 배열의 첫 번째 행 배열의 주소 반환
    cout << score[1] << endl;       // 2차원 배열의 두 번째 행 배열의 주소 반환
    
    return 0;
}
