#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

Node* head = NULL;

void insert_node_at_rear(Node *new_node) {
    if( head == NULL ){    // 공백리스트인 경우
            // new_node->link = NULL;
            head = new_node;
        }
        else  {
            Node *list= head;

            while(list->link != NULL)
                list = list->link;
            list->link = new_node;
        }
}

// 노드 삭제 함수
void delete_node(int X) {
    if (head == NULL) return;       // 삭제할 것이 없음 - 빈 노드인 경우
    else if (head->data == X) {     // 찾는 노드(삭제 노드)가 첫 노드인 경우
        head = head->link;
        return;
    }
    else {
        Node *list = head;
        
        // 마지막 노드까지 순회하기
        while (list->link != NULL) {
            if (list->link->data == X) {        // 다음 노드의 값이 X이면
                list-> link = list->link->link; // 현재 노드의 주소에 삭제할 노드가 가리키는 노드의 주소를 대입
                // delete list;
                return;
            }
            list = list->link;
        }
    }
}

// 리스트 역순 함수
void reverse_list() {
    Node *p, *q, *r;
    //Node *p, q, r;  하면 p만 노드를 가리키는 포인터, q와 r은 노드의 인스턴스
    p = head;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    head = q;
}

void print_list() {
    cout << "전체 연결리스트" << endl;
    for (Node *list = head; list != NULL; list = list -> link) {  // ⭐️
        cout << list->data << '\n' ;
    }
}

int main() {
    int inputSize;
    cout << "입력할 값의 개수: ";
    cin >> inputSize;
    
    for (int i = 0; i< inputSize; i++) {
        // 새로운 노드 할당 및 값 설정
        Node *ptr = new Node;
        
        cout << "다음 데이터를 입력하세요: ";
        int value;
        cin >> value;
        
        ptr->data = value;
        ptr->link = NULL;
        
        insert_node_at_rear(ptr);       // 전체 리스트의 뒤쪽에 새로운 값 추가
    }
    // 작업 확인용
    cout << '\n';
    print_list();
    
    // 노드 역순 만들기
    reverse_list();
    
    // 작업 확인용
    cout << "===== 역순 작업 후 =====" << '\n';
    print_list();
    
    return 0;
}
