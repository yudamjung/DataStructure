#include <iostream>
using namespace std;

const int SBJNUM = 3;   // 과목 수
const int STNUM = 10;   // 학생 수
const int CLSNUM = 3;   // 학급 수

// 실습과제 3 - 학년/반별 통계
int main() {
    // 3차원 배열
    int score[CLSNUM][SBJNUM][STNUM] = {
        // 1반
        {
            // 국어 점수
            {100, 53, 54, 39, 49, 49, 80, 93, 95, 20},
            // 영어 점수
            {100, 35, 96, 86, 58, 87, 84, 75, 35, 85},
            // 수학 점수
            {100, 87, 74, 68 ,94, 36, 95, 45, 65, 36}
        },
        // 2반
        {
            // 국어 점수
            {100, 53, 54, 39, 49, 49, 80, 93, 73, 20},
            // 영어 점수
            {100, 35, 96, 86, 80, 87, 84, 75, 82, 85},
            // 수학 점수
            {100, 87, 74, 68 ,83, 36, 95, 45, 65, 36}
        },
        // 3반
        {
            // 국어 점수
            {100, 53, 54, 39, 59, 94, 80, 93, 95, 20},
            // 영어 점수
            {100, 75, 96, 86, 58, 87, 84, 75, 35, 30},
            // 수학 점수
            {100, 87, 74, 46 ,94, 36, 95, 75, 65, 25}
        }
    };
    
    // 각 반별 과목별 평균
    for (int cl=0; cl<CLSNUM; cl++) {
        for (int sj=0; sj<SBJNUM; sj++) {
            double sum = 0;
            for (int st=0; st<STNUM; st++) {
                sum += score[cl][sj][st];
            }
            cout << cl+1 << "반 " << sj+1  << "번 과목 평균 = " << sum/STNUM << endl;
        }
        
    }
    
    cout << endl;
    
    // 해당 학년 과목 평균
    for (int sj=0; sj<SBJNUM; sj++) {
        int sum = 0;
        for (int cls = 0; cls < CLSNUM; cls++) {
            for (int st = 0; st < STNUM; st++) {
                sum += score[cls][sj][st];
            }
        }
        cout << "과목 전체 평균 = " << (double)sum /(CLSNUM * STNUM) << endl;
    }
    
}
