#include<iostream>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N, M, res = 0, ans = 0;
	int card[101];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				res = card[i] + card[j] + card[k];
				if (res <= M) {
					ans = max(res, ans);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}