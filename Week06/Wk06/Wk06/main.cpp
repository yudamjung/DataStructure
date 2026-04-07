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

void print_list() {
    cout << "전체 연결리스트" << endl;
    for (Node *list = head; list != NULL; list = list -> link) {  // ⭐️
        cout << list->data << '\n' ;
    }
}

int main() {
    for (int i = 0; i< 8; i++) {
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
    print_list();
    return 0;
}
