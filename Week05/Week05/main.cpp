#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

Node* head = NULL;

void insert_node_at_rear(Node *new_node)
{
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


int main() {
    for (int i=0; i<8; i++) {
        Node *new_node = new Node;
        new_node->data = 10 * (i+1);
        new_node->link = NULL;
        
        insert_node_at_rear(new_node);
    }
    
    for (Node *list = head; list != NULL; list=list->link) {
        cout << list->data << endl;
    }
    return 0;
}
