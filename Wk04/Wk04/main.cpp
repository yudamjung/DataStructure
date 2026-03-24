#include <iostream>
using namespace std;

int main() {
    char s1[] = "This is my world.";
    char s2[20] = {'M','y', ' ', 'H', 'o', 'm', 'e', '\0'};
    
    // 문자형이 아닌 배열 출력 시에는 배열명을 출력할 때 배열의 주소가 출력됐음
    // 문자형인 배열에서는 null을 만날 때까지 출력
    // s2의 남은 공간은 모두 null 초기화

    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}
