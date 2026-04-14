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
    
    return 0;
}
