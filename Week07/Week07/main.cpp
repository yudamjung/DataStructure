#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *llink;
    DNode *rlink;
};

DNode *Head = NULL;

// 노드 new_node를 리스트 마지막 노드로 삽입한다. 즉, 헤드노드 앞쪽에 삽입
void insert_node_at_rear(DNode *new_node) {
    new_node->rlink = Head;         // 삽입노드의 우측 노드를 헤드노드로 설정
    new_node->llink = Head->llink;  // 삽입노드의 좌측 노드를 리스트의 마지막 노드로 설정
    Head->llink->rlink = new_node;  // 기존 마지막 노드의 우측 노드를 삽입 노드로 갱신
    Head->llink = new_node;         // 헤드노드의 좌측 노드를 새 노드로 갱신
}

// 리스트에서 지우려는 값을 찾아 삭제하기
void remove_node (int X) {
    for (DNode *list = Head->rlink; list != Head; list = list->rlink) {     // 연결리스트를 따라 순회하는 구조
        if (list->data == X) {                                              // 순회하는 노드의 데이터가 지우려는 값과 같으면
            list->llink->rlink = list->rlink;                               // 지우려는 노드의 다음 노드에 지우려는 노드의 이전 노드를 링크시킴
            list->rlink->llink = list->llink;                               // 지우려는 노드의 이전 노드에 지우려는 노드의 다음 노드를 링크시킴
            return;
        }
    }
}

// 전체 노드를 차례대로 순회하면서 데이터 값을 출력
void print_list() {
    for (DNode *list = Head->rlink; list != Head; list = list->rlink) {
        cout << list->data << endl;
    }
}

// 연결리스트의 노드를 역순으로 출력
void print_reverse_list() {
    for (DNode *list = Head->llink; list != Head; list = list->llink) {     // 이중원형연결리스트에서는 링크를 반대로만 바꿔서 더 쉬운 코딩이 가능
        cout << list->data << endl;
    }
}

int main() {
    // 헤드 노드 (더미 노드) 구성 - llink와 rlink가 모두 헤드 노드 자신을 가리킴
    Head = new DNode;
    Head->llink = Head;
    Head->rlink = Head;
    
    cout << "입력할 노드의 개수는: ";
    int num;
    cin >> num;
    
//    for (int i=0; i<num; i++) {
//        // 노드값 입력
//        int data;
//        cout << "data = ";
//        cin >> data;
//        
//        // 노드 할당
//        DNode *ptr = new DNode;
//        ptr->data = data;
//        ptr->llink = ptr->rlink = NULL;
//        
//        // 기존 리스트에 연결
//        insert_node_at_rear(ptr);
//    }
    
    // 입력값의 개수를 입력받아 그 수의 10을 곱한 수가 노드에 담기는 반복문
    for (int i=1; i<=num; i++) {
        DNode *temp = new DNode;
        temp -> data = i*10;
        temp -> llink = temp -> rlink = NULL;
        
        insert_node_at_rear(temp);
    }
    
    // 확인용
    cout << "구성된 이중(원형)리스트 결과" << endl;
    print_list();
    cout << "역순으로 출력" << endl;
    print_reverse_list();
    cout << '\n';
    
    // 삭제하기
    cout << "삭제할 값: ";
    int X;
    cin >> X;
    remove_node(X);
    // 확인용
    print_list();
    
    return 0;
}
