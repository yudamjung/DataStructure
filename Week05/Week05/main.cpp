#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

Node* head = NULL;

// C| 리스트 처음에 노드 삽입
void insert_node_at_front(Node *new_node) {
    new_node->link = head;
    head = new_node;
}

int main() {
    for (int i=0; i<8; i++) {
        Node *new_node = new Node;
        new_node->data = 10 * (i+1);
        new_node->link = NULL;
        
        insert_node_at_front(new_node);
    }
    
    // 연결리스트 내용 출력
    for (Node* list = head; list != NULL; list=list->link) {
        cout << list->data << endl;
    }
    
    // 60이라는 값을 갖는 노드 주소 출력
    for (Node* list = head; list != NULL; list=list->link) {
        if (list->data == 60) cout << "FOUND" << endl;
        cout << "NOT FOUND" << endl;
    }
    
    return 0;
}
