#if 0
// Tree Sample
#include <iostream>
using namespace std;


class TreeNode {
public:
	char data;
	TreeNode* left;
	TreeNode* right;
};

void inorder(TreeNode* root) {
	if (root == NULL) return;  // *** 중요
	cout << root->data << endl;
	inorder(root->left);
	inorder(root->right);
}

const int NODE_CNT = 11;

int main() {
	TreeNode* nodes[NODE_CNT];

	// 필요 갯수만큼 노드 생성
	for (int i = 0; i < NODE_CNT; i++) {
		nodes[i] = new TreeNode;
		nodes[i]->left = NULL;
		nodes[i]->right = NULL;
	}

	// 각 노드의 값(data) 추가
	nodes[0]->data = 'A'; 	nodes[1]->data = 'B';	nodes[2]->data = 'C'; 	nodes[3]->data = 'D';
	nodes[4]->data = 'E';   nodes[5]->data = 'F';	nodes[6]->data = 'G'; 	nodes[7]->data = 'H';
	nodes[8]->data = 'I';	nodes[9]->data = 'J';	nodes[10]->data = 'K';

	// 각 노드 연결 (그림 참조, 다만 인덱스 0부터시작) 총 10개의 가지 구현
	nodes[0]->left = nodes[1]; nodes[0]->right = nodes[2]; // A-B, A-C
	nodes[1]->left = nodes[3]; nodes[1]->right = nodes[4]; // B-D, B-E
	nodes[2]->left = nodes[5]; nodes[2]->right = nodes[6]; // C-F, C-G
	nodes[3]->left = nodes[7];							   // D-H
	nodes[4]->left = nodes[8]; nodes[4]->right = nodes[9]; // E-I, E-J
	//nodes[5] = ?? 자식노드 없음
	nodes[6]->right = nodes[10];						   // G-K

	inorder(nodes[0]);


}
#endif
