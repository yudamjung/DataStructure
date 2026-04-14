#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *llink;
    DNode *rlink;
};

DNode *Head = NULL;
//Node *Head = NULL;


// 노드 new_node를 리스트 마지막 노드로 삽입한다. 즉, 헤드노드 앞쪽에 삽입
void insert_node_at_rear(DNode *new_node)
{
    new_node->rlink = Head;
    new_node->llink = Head->llink;
    Head->llink->rlink = new_node;
    Head->llink = new_node;
}

// 전체 노드를 차례대로 순회하면서 데이터 값을 출력
void print_list() {
    for (DNode *list = Head->rlink; list != Head; list = list->rlink) {
        cout << list->data << endl;
    }
}

// 연결리스트의 노드를 역순으로 출력
void print_reverse_list() {
    for (DNode *list = Head->llink; list != Head; list = list->llink) {
        cout << list->data << endl;
    }
}

int main() {
    // 헤드 노드 구성 - llink와 rlink가 모두 헤드 노드 자신을 가리킴
    Head = new DNode;
    Head->llink = Head;
    Head->rlink = Head;
    
    cout << "입력할 노드의 개수는: ";
    int num;
    cin >> num;
    
    for (int i=0; i<num; i++) {
        // 노드값 입력
        int data;
        cout << "data = ";
        cin >> data;
        
        // 노드 할당
        DNode *ptr = new DNode;
        ptr->data = data;
        ptr->llink = ptr->rlink = NULL;
        
        // 기존 리스트에 연결
        insert_node_at_rear(ptr);
    }
    
    // 확인용
    cout << "구성된 이중(원형)리스트 결과" << endl;
    print_list();
    cout << "역순으로 출력" << endl;
    print_reverse_list();
    
    return 0;
}
