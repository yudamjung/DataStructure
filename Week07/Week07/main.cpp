#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *link;
};

Node *Head = NULL;

void insert_at_rear(Node *new_node) {
    if (Head == NULL) {
        new_node -> link = new_node;
        Head = new_node;
    }
    else {
        new_node->link = Head->link;
        Head->link = new_node;
        Head = new_node;
    }
}

void delete_node(int X) {
    if (Head == NULL) return;

    // 노드가 1개인 경우
    if (Head->link == Head && Head->data == X) {
        Head = NULL;
        return;
    }

    Node *pre = Head;
    do {
        if (pre->link->data == X) {
            Node *target = pre->link;
            pre->link = target->link;

            // 삭제 대상이 Head면 Head 갱신
            if (target == Head) Head = pre;

            delete target; // 메모리 해제도 해주기
            return;
        }
        pre = pre->link;
    } while (pre != Head);
}

void print_list() {
    Node *list;
    if (Head == NULL) cout << "List is NULL :: Noghint to show" << endl;
    else {
        for (list = Head->link; list != Head; list = list->link)
            cout << list -> data << "->";
        cout << list->data << endl;
    }
}

int main() {
    cout << "입력할 노드의 개수는: ";
    int num;
    cin >> num;
    
    for (int i=0; i<num; i++) {
        // 노드값 입력
        int data;
        cout << "data = ";
        cin >> data;
        
        // 노드 할당
        Node *ptr = new Node;
        ptr->data = data;
        ptr->link = NULL;
        
        // 기존 리스트에 연결
        insert_at_rear(ptr);
    }
    
    // 확인용
    print_list();
    
    // 노드 삭제
    cout << "삭제할 값은: ";
    int value_to_delete;
    cin >> value_to_delete;
    
    // 원형 리스트에서 삭제
    delete_node(value_to_delete);
    
    // 확인용
    cout << "=== 삭제 후 원형연결리스트 결과 ===" << endl;
    print_list();
    
    return 0;
}
