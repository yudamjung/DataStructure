#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

Node* head = NULL;
Node* p1, *p2, *p3;

int main() {
    p1 = new Node;
    p1->data = 10;
    p1->link = NULL;
    
    p2 = new Node;
    p2->data = 20;
    p2->link = NULL;
    
    
    p3 = new Node;
    p3->data = 30;
    p3->link = NULL;    // 마지막이니까 NULL pointing
    
    
    
    p1->link = p2;      // p2가 생성된 뒤에 연결
    p2->link = p3;      // p3가 생성된 뒤에 연결
    p3->link = NULL;
    head = p1;
        
    return 0;
}
