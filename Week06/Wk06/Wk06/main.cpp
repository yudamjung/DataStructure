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
        cout << list->data << '\n' << '\n';
    }
}

int main() {
    
    
    return 0;
}
