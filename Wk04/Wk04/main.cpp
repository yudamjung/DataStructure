#include <iostream>
using namespace std;

int main() {
    // 문자열은 글자 수 + 1 이상의 크기가 지정 되어야함.
    char s1[18] = "This is my world.";
    char s2[8] = {'M','y', ' ', 'H', 'o', 'm', 'e'};
    
    // 문자형이 아닌 배열 출력 시에는 배열명을 출력할 때 배열의 주소가 출력됐음
    // 문자형인 배열에서는 null을 만날 때까지 출력
    // s2의 남은 공간은 모두 null 초기화

    cout << s1 << endl;
    
    // 배열명 + n (index) => index 숫자부터 끝까지 문자형 배열 출력
    cout << s1 + 3 << endl;
    
    // index 7부터는 날리고 출력하고 싶을 때
    s1[7] = NULL;
    cout << s1 << endl;
    
    // m번째부터 n번째까지만 출력하고 싶을 때
    char ss1[18] = "This is my world.";
    ss1[7] = NULL;
    cout << ss1+5 << endl;
    
    cout << s2 << endl;

    return 0;
}
