#if 1
// Tree Sample - 그림 [8-14] 이진 트리의 전위 순회 경로
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
inorder(root->left);
cout << root->data << endl;
inorder(root->right);
}

const int NODE_CNT = 11;

int main() {
	TreeNode* nodes[NODE_CNT];

	// « ø‰ ∞πºˆ∏∏≈≠ ≥ÎµÂ ª˝º∫
	for (int i = 0; i < NODE_CNT; i++) {
		nodes[i] = new TreeNode;
		nodes[i]->left = NULL;
		nodes[i]->right = NULL;
	}

	// ∞¢ ≥ÎµÂ¿« ∞™(data) √ﬂ∞°
	nodes[0]->data = 'A'; 	nodes[1]->data = 'B';	nodes[2]->data = 'C'; 	nodes[3]->data = 'D';
	nodes[4]->data = 'E';   nodes[5]->data = 'F';	nodes[6]->data = 'G'; 	nodes[7]->data = 'H';
	nodes[8]->data = 'I';	nodes[9]->data = 'J';	nodes[10]->data = 'K';

	// ∞¢ ≥ÎµÂ ø¨∞· (±◊∏≤ ¬¸¡∂, ¥Ÿ∏∏ ¿Œµ¶Ω∫ 0∫Œ≈ÕΩ√¿€) √— 10∞≥¿« ∞°¡ˆ ±∏«ˆ
	nodes[0]->left = nodes[1]; nodes[0]->right = nodes[2]; // A-B, A-C
	nodes[1]->left = nodes[3]; nodes[1]->right = nodes[4]; // B-D, B-E
	nodes[2]->left = nodes[5]; nodes[2]->right = nodes[6]; // C-F, C-G
	nodes[3]->left = nodes[7];							   // D-H
	nodes[4]->left = nodes[8]; nodes[4]->right = nodes[9]; // E-I, E-J
	//nodes[5] = ?? ¿⁄Ωƒ≥ÎµÂ æ¯¿Ω
	nodes[6]->right = nodes[10];						   // G-K

	inorder(nodes[0]);


}
#endif
