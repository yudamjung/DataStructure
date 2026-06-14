#include <iostream>
using namespace std;

int main() {
    int i = 10;
    int *pI = &i;
    
    cout << pI << endl;
    cout << pI + 1 << endl; // sizeof(int) == 4B. 4B 만큼 다음의 주소 출력.
    
    double d = 20.0;
    double *pD = &d;
    
    cout << pD << endl;
    cout << pD + 1 << endl; // sizeof(double) == 8B. 8B 만큼 다음의 주소 출력.
}
