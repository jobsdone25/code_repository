#include <iostream>
#define MAX_N 100'000

using namespace std;

// 변수 선언
int n;
int preorder[MAX_N + 1],inorder[MAX_N+1], postorder[MAX_N + 1];
int cnt = 1;

void DFS(int l, int r,int l2,int r2) {
	if (l > r) return;
	if (l == r) {
		postorder[cnt++] = preorder[l];
		return;
	}
	int root = 0;
	for (int i = l2; i <= r2; i++) {
		if (preorder[l] == inorder[i])
			root = i;
	}

	int leftsize = root - l2;
	int rightsize = r2 - root;


	DFS(l + 1, l + leftsize, l2, root-1);
	DFS(l + leftsize + 1, r, root + 1, r2);
	postorder[cnt++] = preorder[l];
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> preorder[i];
	for (int i = 1; i <= n; i++) cin >> inorder[i];
	
	DFS(1, n,1,n); //전위 순회 정보, 중위 순회 정보

	for (int i = 1; i <= n; i++) {
		cout << postorder[i] << " ";
	}

	return 0;
}