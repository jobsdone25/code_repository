#include<iostream>
#include<vector>
#define MAX_N 50'000
#define MAX_H 16
using namespace std;
vector<int> edge[MAX_N + 1];
int depth[MAX_N + 1];

int parent[MAX_H][MAX_N + 1];  //parent[h][i] i번 노드에서 h까지 위로 올라갔을때의 노드 정보

void DFS(int x) {
    // 노드 x의 자식들을 살펴봅니다.
    for (int i = 0; i < (int)edge[x].size(); i++) {
        int y = edge[x][i];
        depth[y] = depth[x] + 1;

        parent[0][y] = x;
        DFS(y);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    DFS(1);

    //점화식 실행
    for (int h = 1; h <= MAX_H; h++) {
        for (int i = 1; i <= n; i++) {
            parent[h][i] = parent[h - 1][parent[h - 1][i]];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;

        cin >> a >> b;

        //step 1 높이 같게 만들어주기
        int big = depth[a] > depth[b] ? a : b;
        int small = a + b - big;

        for (int h = MAX_H; h >= 0; h--) {
            if (depth[big] - depth[small] >= (1 << h)) big = parent[h][big];
        }

        //step 2
        for (int h = MAX_H; h >= 0; h--) {
            if (parent[h][big] != parent[h][small]) {
                big = parent[h][big];
                small = parent[h][big];
            }
        }
        cout << parent[0][big]<< "\n";
    }
}