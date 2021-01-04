#include<iostream>
#include<map>
using namespace std;

int unf[200001];
int netsize[200001];

int find(int v) {
	if (unf[v] == v) return v;
	return unf[v] = find(unf[v]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		unf[x] = y;
		netsize[y] += netsize[x];
		return;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc, f;
	string a, b;
	cin >> tc;

	while (tc--) {
		cin >> f;
		map<string, int> name;
		int cnt = 1;

		for (int i = 1; i <= 2 * f; i++) {
			unf[i] = i;
			netsize[i] = 1;
		}

		for (int i = 0; i < f; i++) {
			cin >> a >> b;

			if (name.count(a) == 0) name[a] = cnt++;	//key가 a이고 value가 cnt인 노드 추가
			if (name.count(b) == 0) name[b] = cnt++;

			Union(name[a], name[b]);	//key가 a,b인 value들을 union하는거
			cout << netsize[find(name[a])] << "\n";
		}
	}
	return 0;
}