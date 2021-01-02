#include<iostream>
#include<queue>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int cnt = 0, maxi = 0;
		queue<pair<int, int> > q;
		priority_queue<int> pq;
		int n, m, pri;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> pri;
			pq.push(pri);
			q.push(make_pair(pri, i));
		}
		while (1) {
			maxi = pq.top();
			if (q.front().first == maxi) {
				cnt += 1;
				if (q.front().second == m) {
					cout << cnt << "\n";
					break;
				}
				else {
					q.pop();
					pq.pop();
				}
			}
			else {
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				q.push(make_pair(a, b));
			}
		}
	}
	return 0;
}