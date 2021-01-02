#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, cnt = 1;
	string ans = "";
	stack<int> st;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (cnt <= a) {
			st.push(cnt);
			cnt += 1;
			ans += "+";
			ans += "\n";
		}
		if (st.top() == a) {
			st.pop();
			ans += "-";
			ans += "\n";
		}
		else {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}