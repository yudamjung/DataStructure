#include <iostream>
using namespace std;

int main () {

    // 학생 수 입력 받기
    int st;
    cout << "학생 수를 입력하세요 : ";
    cin >> st;
    
    // 학생 성적 입력 받기
    int *score = new int [st];        // 동적 메모리 할당
        // == int score[st];
    for (int i=0; i<st; i++) {
        cin >> *(score+i);
        // == cin >> score[i];
    }
    
    // 학생 성적 출력하기
    cout << "=== 입력된 학생의 성적 ===" << '\n';
    for (int i=0; i<st; i++) {
        cout << "학생" << i+1<< " 의 성적은 : " << score[i] << endl;
    }
    
    // 평균 구하기
    int sum = 0;
    for (int i=0; i<st; i++) {
        sum += *(score+i);
        // == sum += score[i];
    }
    
    cout << "=== 평균 성적 ===" << '\n';
    cout << "성적 평균은 : " << (double)sum / st << endl;
    
    return 0;
}
