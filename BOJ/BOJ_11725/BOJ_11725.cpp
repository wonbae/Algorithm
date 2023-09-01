#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
vector<int> tree[MAX_N + 1]; // 노드 연결 정보
int parent[MAX_N + 1]; // 각 노드의 부모 정보

void findParent(int node) {
    for (int child : tree[node]) {
        if (parent[child] == 0) { // 아직 부모가 정해지지 않은 자식 노드라면
            parent[child] = node; // 현재 노드를 부모로 설정
            findParent(child); // 재귀적으로 자식 노드의 부모 찾기
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    // 트리 정보 입력
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 루트 노드의 부모는 0으로 설정
    parent[1] = 0;

    // 1번(루트) 노드부터 DFS를 통해 부모 노드 찾기
    findParent(1);

    // 부모 정보 출력 (2번 노드부터)
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
